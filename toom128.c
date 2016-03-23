/* This file is part of the gf2x library.

   Copyright 2007-2016
   Richard Brent, Pierrick Gaudry, Emmanuel Thome', Paul Zimmermann

   This program is free software; you can redistribute it and/or modify it
   under the terms of either:
    - If the archive contains a file named toom-gpl.c (not a trivial
    placeholder), the GNU General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.
    - If the archive contains a file named toom-gpl.c which is a trivial
    placeholder, the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.
   
   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the license text for more details.
   
   You should have received a copy of the GNU General Public License as
   well as the GNU Lesser General Public License along with this program;
   see the files COPYING and COPYING.LIB.  If not, write to the Free
   Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
   02110-1301, USA.
*/

/* Variants of Toom-Cook using SSE2 128-bit XOR, copied from toom.c.
   Those routines assume that "unsigned long" is a 64-bit type. */

#include <stdio.h>
#include <string.h> /* for memcpy() */

#include "gf2x.h"
#include "gf2x/gf2x-impl.h"

#ifdef HAVE_ALLOCA
#define ALLOC alloca
#else
#include <stdlib.h>
#define ALLOC malloc
#endif

/* from https://www.gnu.org/software/autoconf/manual/autoconf-2.60/html_node/Particular-Functions.html */
#if HAVE_ALLOCA_H
# include <alloca.h>
#elif defined __GNUC__
# define alloca __builtin_alloca
#elif defined _AIX
# define alloca __alloca
#elif defined _MSC_VER
# include <malloc.h>
# define alloca _alloca
#else
# include <stddef.h>
void *alloca (size_t);
#endif

#ifdef HAVE_KARAX
#include <emmintrin.h>

/* assuming x is 64-bit aligned (result of malloc on a 64-bit machine),
   return 0 if x is 128-bit aligned, 1 otherwise */
static inline unsigned long
alignement_128 (const unsigned long *x)
{
  return ((long) x >> 3) & 1;
}

/* assuming x is 64-bit aligned (result of malloc on a 64-bit machine),
   return x if x is 128-bit aligned, x+1 otherwise */
static inline unsigned long*
aligned128 (unsigned long *x)
{
  return x + alignement_128 (x);
}

/* Let spx(n) be the space requirement (in number of 128-bit words) for stk
   in gf2x_mul_karax_internal(n), and sp(n) the space requirement (in number
   of 64-bit words) for stk in the gf2x_mul_kara() routine:
   (1) if 2*n < GF2X_MUL_KARA_THRESHOLD then spx(n) <= ceil(sp(2*n)/2)
   (2) otherwise spx(n) <= 3*ceil(n/2) + spx(ceil(n/2)).

   Assumes c, a, b, stk are 128-bit aligned.

   FIXME: write a 256-bit variant using AVX2:
   VPXOR: __m256i _mm256_xor_si256 ( __m256i a, __m256i b)
 */
#define XOR(a,b) _mm_xor_si128(a,b)
static void
gf2x_mul_karax_internal (__m128i *c, const __m128i *a,
                         const __m128i *b, long n, __m128i * stk)
{
    __m128i *aa, *bb, *cc;
    long j, d, n2;

    /* since this routine is usually faster than gf2x_mul_kara, we directly
       call gf2x_mul_basecase() here */
    if (2 * n < GF2X_MUL_KARA_THRESHOLD)
      {
        gf2x_mul_basecase ((unsigned long*) c, (unsigned long*) a, 2 * n,
                           (unsigned long*) b, 2 * n);
	return;
      }

    n2 = (n + 1) / 2;		/* ceil(n/2) */
    d = n & 1;			/* 2*n2 - n = 1 if n odd, 0 if n even */
    aa = stk;			/* Size n2   */
    bb = aa + n2;		/* Size n2   */
    cc = bb + n2;		/* Size n2   */

    stk = cc + n2;		/* sp(n) = 3*ceil(n/2)) + sp(ceil(n/2)) */

    const __m128i *a1 = a + n2;	/* a[n2] */
    const __m128i *b1 = b + n2;	/* b[n2] */
    __m128i *c1 = c + n2;	/* c[n2]   */
    __m128i *c2 = c1 + n2;	/* c[2*n2] */
    __m128i *c3 = c2 + n2;	/* c[3*n2] */

    gf2x_mul_karax_internal (c, a, b, n2, stk);	/* Low */

    gf2x_mul_karax_internal (c2, a1, b1, n2 - d, stk);	/* High */

    for (j = 0; j < n2 - d; j++)
      {
        aa[j] = XOR (a[j], a1[j]);
        bb[j] = XOR (b[j], b1[j]);
        cc[j] = XOR (c1[j], c2[j]);
      }
    for (; j < n2; j++)
      {	/* Only when n odd */
	aa[j] = a[j];
	bb[j] = b[j];
	cc[j] = XOR (c1[j], c2[j]);
    }

    gf2x_mul_karax_internal (c1, aa, bb, n2, stk);	/* Middle */

    for (j = 0; j < n2 - 2 * d; j++)
      {
	c1[j] = XOR (c1[j], XOR (cc[j], c[j]));
	c2[j] = XOR (c2[j], XOR (cc[j], c3[j]));
      }
    for (; j < n2; j++)
      {	/* Only when n odd */
	c1[j] = XOR (c1[j], XOR (cc[j], c[j]));
	c2[j] = XOR (c2[j], cc[j]);
      }
}

void
gf2x_mul_karax (unsigned long *c, const unsigned long *a,
                const unsigned long *b, long n, unsigned long *stk)
{
    unsigned long *cc, *aa, *bb, *tc = NULL, *ta = NULL, *tb = NULL;

    if ((n & 1) == 0) /* n is even */
      {
        /* check if c is 16-byte aligned */
        if (alignement_128 (c) == 0)
          cc = c;
        else
          {
            /* since we need an array of 2n unsigned long's that is
               128-bit aligned, we allocate 2n+1 words */
            tc = ALLOC ((2 * n + 1) * sizeof (unsigned long));
            cc = aligned128 (tc);
          }

        /* check if a is 16-byte aligned */
        if (alignement_128 (a) == 0)
          aa = (unsigned long*) a;
        else
          {
            ta = ALLOC ((n + 1) * sizeof (unsigned long));
            aa = aligned128 (ta);
            memcpy (aa, a, n * sizeof (unsigned long));
          }

        /* check if b is 16-byte aligned */
        if (alignement_128 (b) == 0)
          bb = (unsigned long*) b;
        else
          {
            tb = ALLOC ((n + 1) * sizeof (unsigned long));
            bb = aligned128 (tb);
            memcpy (bb, b, n * sizeof (unsigned long));
          }
        
        gf2x_mul_karax_internal ((__m128i*) cc, (__m128i*) aa,
                                 (__m128i*) bb, n >> 1,
                                 (__m128i*) aligned128 (stk));

        if (cc != c)
          memcpy (c, cc, 2 * n * sizeof (unsigned long));
      }
    else /* n is odd */
      {
        /* we need an array of n+1 words that is 128-bit aligned for a,
           another similar for b, and another of 2n+2 words for c, thus
           in total 4n+4 words */
        ta = ALLOC ((4 * n + 5) * sizeof (unsigned long));
        aa = aligned128 (ta);
        memcpy (aa, a, n * sizeof (unsigned long));
        aa[n] = 0;

        bb = aa + n + 1;
        memcpy (bb, b, n * sizeof (unsigned long));
        bb[n] = 0;
        
        cc = bb + n + 1;
        gf2x_mul_karax_internal ((__m128i*) cc, (__m128i*) aa,
                                 (__m128i*) bb, (n + 1) >> 1,
                                 (__m128i*) aligned128 (stk));

        memcpy (c, cc, 2 * n * sizeof (unsigned long));
      }

#ifndef HAVE_ALLOCA
    if (ta != NULL)
      free (ta);
    if (tb != NULL)
      free (tb);
    if (tc != NULL)
      free (tc);
#endif
}

#endif /* HAVE_KARAX */