/* This file is part of the gf2x library.

   Copyright 2007, 2008, 2009, 2010, 2013, 2014, 2015
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

#ifndef GF2XFFT_MACROS_H_
#define GF2XFFT_MACROS_H_

#include <assert.h>
#define ASSERT(x)	assert(x)

#if 0
/**********************************************************************/
/* Common asserting/debugging defines */
/* See README.macro_usage */

#include <stdio.h>
#include <stdlib.h>


#define croak__(x,y) do {						\
        fprintf(stderr,"%s in %s at %s:%d -- %s\n",			\
                (x),__func__,__FILE__,__LINE__,(y));			\
    } while (0)

#define ASSERT_ALWAYS(x)						\
    do {								\
        if (!(x)) {							\
            croak__("code BUG() : condition " #x " failed",		\
                    "Abort");						\
            abort();							\
        }								\
    } while (0)
#define FATAL_ERROR_CHECK(cond, msg)					\
    do {								\
      if (UNLIKELY((cond))) {                                           \
            croak__("Fatal error", msg);				\
          abort();                                                      \
        }								\
    } while (0)

#define DIE_ERRNO_DIAG(tst, func, arg) do {				\
    if (UNLIKELY(tst)) {				        	\
        fprintf(stderr, func "(%s): %s\n", arg, strerror(errno));       \
        exit(1);					        	\
    }							        	\
} while (0)
#endif

/*********************************************************************/
/* Helper macros */
/* See README.macro_usage */

#ifndef ABS
#define ABS(x) ((x) >= 0 ? (x) : -(x))
#endif

#ifndef MIN
#define MIN(l,o) ((l) < (o) ? (l) : (o))
#endif

#ifndef MAX
#define MAX(h,i) ((h) > (i) ? (h) : (i))
#endif

/* Handy, and does not require libm */
#ifndef iceildiv
/* unfortunately this fails miserably if x+y-1 overflows */
#define iceildiv(x,y)	(((x)+(y)-1)/(y))
#endif

#define LEXGE2(X,Y,A,B) (X>A || (X == A && Y >= B))
#define LEXGE3(X,Y,Z,A,B,C) (X>A || (X == A && LEXGE2(Y,Z,B,C)))
#define LEXLE2(X,Y,A,B) LEXGE2(A,B,X,Y)
#define LEXLE3(X,Y,Z,A,B,C) LEXGE3(A,B,C,X,Y,Z)

#ifndef GNUC_VERSION
#define GNUC_VERSION(X,Y,Z)     \
    defined(__GNUC__) &&        \
(__GNUC__ == X && __GNUC_MINOR__ == Y && __GNUC_PATCHLEVEL__ == Z)
#endif

#ifndef GNUC_VERSION_ATLEAST
#define GNUC_VERSION_ATLEAST(X,Y,Z)     \
    defined(__GNUC__) &&        \
LEXGE3(__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__,X,Y,Z)
#endif

#ifndef GNUC_VERSION_ATMOST
#define GNUC_VERSION_ATMOST(X,Y,Z)     \
    defined(__GNUC__) &&        \
LEXLE3(__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__,X,Y,Z)
#endif

#ifndef MAYBE_UNUSED
#if GNUC_VERSION_ATLEAST(3,4,0)
/* according to
 * http://gcc.gnu.org/onlinedocs/gcc-3.1.1/gcc/Variable-Attributes.html#Variable%20Attributes
 * the 'unused' attribute already existed in 3.1.1 ; however the rules
 * for its usage remained quirky until 3.4.0, so we prefer to stick to
 * the more modern way of using the unused attribute, and recommend
 * setting the -Wno-unused flag for pre-3.4 versions of gcc
 */
#define MAYBE_UNUSED __attribute__ ((unused))
#else
#define MAYBE_UNUSED
#endif
#endif

#if defined(__GNUC__)

#ifndef NO_INLINE
#define NO_INLINE __attribute__ ((noinline))
#endif
#ifndef PACKED
#define PACKED __attribute__ ((packed))
#endif
#ifndef EXPECT
#define EXPECT(x,val)	__builtin_expect(x,val)
#endif
#ifndef ATTR_PRINTF
#define ATTR_PRINTF(a,b) __attribute__((format(printf,a,b)))
#endif
#else
#ifndef NO_INLINE
#define NO_INLINE
#endif
#ifndef PACKED
#define PACKED
#endif
#ifndef EXPECT
#define	EXPECT(x,val)	(x)
#endif
#ifndef ATTR_PRINTF
#define ATTR_PRINTF(a,b) /**/
#endif
#endif

#ifndef	LIKELY
#define LIKELY(x)	EXPECT(x,1)
#endif
#ifndef	UNLIKELY
#define UNLIKELY(x)	EXPECT(x,0)
#endif

#endif	/* GF2XFFT_MACROS_H_ */
