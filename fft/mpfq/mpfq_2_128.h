#ifndef MPFQ_2_128_H_
#define MPFQ_2_128_H_

/* MPFQ generated file -- do not edit */

#include "mpfq/mpfq.h"
#include "mpfq/mpfq_gf2n_common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <ctype.h>
#include <emmintrin.h>
#include <stddef.h>
#include <stdio.h>

#ifdef  HAVE_PCLMUL
#include <wmmintrin.h>
#endif

#include "assert.h"
#ifdef	MPFQ_LAST_GENERATED_TAG
#undef	MPFQ_LAST_GENERATED_TAG
#endif
#define MPFQ_LAST_GENERATED_TAG      2_128

#ifndef GMP_LIMB_BITS
#error "Please arrange so that GMP_LIMB_BITS is defined before including this file"
#endif

#if !(GMP_LIMB_BITS == 64)
#error "Constraints not met for this file: GMP_LIMB_BITS == 64"
#endif
/* Active handler: Mpfq::defaults::vec */
/* Active handler: Mpfq::defaults */
/* Active handler: Mpfq::gf2n::field */
/* Automatically generated code for GF(2^128) */
/* Definition polynomial P = X^128 + X^7 + X^2 + X + 1 */
/* Active handler: Mpfq::gf2n::trivialities */
/* Active handler: Mpfq::gf2n::io */
/* Active handler: Mpfq::gf2n::linearops */
/* Active handler: Mpfq::gf2n::inversion */
/* Active handler: Mpfq::gf2n::reduction */
/* Active handler: Mpfq::gf2n::mul */
/* Active handler: Mpfq::defaults::poly */
/* Options used: w=64 n=128 table=/tmp/mpfq/gf2x/wizard.table slice=4 helper=/tmp/mpfq/gf2n/helper/helper output_path=/tmp/mpfq/gf2n tag=2_128 coeffs=[128, 7, 2, 1, 0] */

typedef mpfq_2_field mpfq_2_128_field;
typedef mpfq_2_dst_field mpfq_2_128_dst_field;

typedef unsigned long mpfq_2_128_elt[2];
typedef unsigned long * mpfq_2_128_dst_elt;
typedef const unsigned long * mpfq_2_128_src_elt;

typedef unsigned long mpfq_2_128_elt_ur[4];
typedef unsigned long * mpfq_2_128_dst_elt_ur;
typedef const unsigned long * mpfq_2_128_src_elt_ur;

typedef mpfq_2_128_elt * mpfq_2_128_vec;
typedef mpfq_2_128_elt * mpfq_2_128_dst_vec;
typedef mpfq_2_128_elt * mpfq_2_128_src_vec;

typedef mpfq_2_128_elt_ur * mpfq_2_128_vec_ur;
typedef mpfq_2_128_elt_ur * mpfq_2_128_dst_vec_ur;
typedef mpfq_2_128_elt_ur * mpfq_2_128_src_vec_ur;

typedef struct {
  mpfq_2_128_vec c;
  unsigned int alloc;
  unsigned int size;
} mpfq_2_128_poly_struct;
typedef mpfq_2_128_poly_struct mpfq_2_128_poly [1];
typedef struct {
  mpfq_2_128_poly c00;
  mpfq_2_128_poly c01;
  mpfq_2_128_poly c10;
  mpfq_2_128_poly c11;
} mpfq_2_128_polymat;
typedef mpfq_2_128_poly_struct * mpfq_2_128_dst_poly;
typedef mpfq_2_128_poly_struct * mpfq_2_128_src_poly;

#ifdef  __cplusplus
extern "C" {
#endif

/* Functions operating on the field structure */
/* *Mpfq::gf2n::field::code_for_field_characteristic */
#define mpfq_2_128_field_characteristic(f, x)	mpz_set_ui(x,2);
/* *Mpfq::gf2n::field::code_for_field_degree */
#define mpfq_2_128_field_degree(f)	128
static inline
void mpfq_2_128_field_init(mpfq_2_128_dst_field);
/* *Mpfq::defaults::code_for_field_clear */
#define mpfq_2_128_field_clear(K)	/**/
/* *Mpfq::defaults::code_for_field_specify */
#define mpfq_2_128_field_specify(k, dummy, vp)	/**/
static inline
void mpfq_2_128_field_setopt(mpfq_2_128_dst_field, unsigned long, void *);

/* Element allocation functions */
/* *Mpfq::defaults::flatdata::code_for_init */
#define mpfq_2_128_init(f, px)	/**/
/* *Mpfq::defaults::flatdata::code_for_clear */
#define mpfq_2_128_clear(f, px)	/**/

/* Elementary assignment functions */
static inline
void mpfq_2_128_set(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_set_ui(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, unsigned long);
static inline
void mpfq_2_128_set_zero(mpfq_2_128_dst_field, mpfq_2_128_dst_elt);
static inline
unsigned long mpfq_2_128_get_ui(mpfq_2_128_dst_field, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_set_mpn(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mp_limb_t *, size_t);
static inline
void mpfq_2_128_set_mpz(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpz_t);
static inline
void mpfq_2_128_get_mpn(mpfq_2_128_dst_field, mp_limb_t *, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_get_mpz(mpfq_2_128_dst_field, mpz_t, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_set_uipoly(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, unsigned long);
static inline
void mpfq_2_128_set_uipoly_wide(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, const unsigned long *, unsigned int);
static inline
unsigned long mpfq_2_128_get_uipoly(mpfq_2_128_dst_field, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_get_uipoly_wide(mpfq_2_128_dst_field, unsigned long *, mpfq_2_128_src_elt);

/* Assignment of random values */
static inline
void mpfq_2_128_random(mpfq_2_128_dst_field, mpfq_2_128_dst_elt);
#define HAVE_mpfq_2_128_random2
static inline
void mpfq_2_128_random2(mpfq_2_128_dst_field, mpfq_2_128_dst_elt);

/* Arithmetic operations on elements */
static inline
void mpfq_2_128_add(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt, mpfq_2_128_src_elt);
/* *Mpfq::gf2n::trivialities::code_for_sub */
#define mpfq_2_128_sub(K, r, s1, s2)	mpfq_2_128_add(K,r,s1,s2)
/* *Mpfq::gf2n::trivialities::code_for_neg */
#define mpfq_2_128_neg(K, r, s)	mpfq_2_128_set(K,r,s)
static inline
void mpfq_2_128_mul(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_sqr(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt);
/* *Mpfq::gf2n::trivialities::code_for_is_sqr */
#define mpfq_2_128_is_sqr(f, p)	1
static inline
int mpfq_2_128_sqrt(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_pow(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt, unsigned long *, size_t);
/* *Mpfq::gf2n::trivialities::code_for_frobenius */
#define mpfq_2_128_frobenius(K, r, s)	mpfq_2_128_sqr(K,r,s)
static inline
void mpfq_2_128_add_ui(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt, unsigned long);
/* *Mpfq::gf2n::trivialities::code_for_sub_ui */
#define mpfq_2_128_sub_ui(K, r, s1, s2)	mpfq_2_128_add_ui(K,r,s1,s2)
static inline
void mpfq_2_128_mul_ui(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt, unsigned long);
static inline
void mpfq_2_128_add_uipoly(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt, unsigned long);
/* *Mpfq::gf2n::trivialities::code_for_sub_uipoly */
#define mpfq_2_128_sub_uipoly(K, r, s1, s2)	mpfq_2_128_add_uipoly(K,r,s1,s2)
static inline
void mpfq_2_128_mul_uipoly(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt, unsigned long);
static inline
void mpfq_2_128_longaddshift_left(unsigned long *, const unsigned long *, int, int);
static inline
void mpfq_2_128_longshift_left(unsigned long *, const unsigned long *, int, int);
static inline
int mpfq_2_128_inv(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_as_solve(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_elt);
static inline
unsigned long mpfq_2_128_trace(mpfq_2_128_dst_field, mpfq_2_128_src_elt);

/* Operations involving unreduced elements */
/* *Mpfq::defaults::flatdata::code_for_elt_ur_init */
#define mpfq_2_128_elt_ur_init(f, px)	/**/
/* *Mpfq::defaults::flatdata::code_for_elt_ur_clear */
#define mpfq_2_128_elt_ur_clear(f, px)	/**/
static inline
void mpfq_2_128_elt_ur_set(mpfq_2_128_dst_field, mpfq_2_128_dst_elt_ur, mpfq_2_128_src_elt_ur);
static inline
void mpfq_2_128_elt_ur_set_ui(mpfq_2_128_dst_field, mpfq_2_128_dst_elt_ur, unsigned long);
static inline
void mpfq_2_128_elt_ur_add(mpfq_2_128_dst_field, mpfq_2_128_dst_elt_ur, mpfq_2_128_src_elt_ur, mpfq_2_128_src_elt_ur);
/* *Mpfq::gf2n::trivialities::code_for_elt_ur_neg */
#define mpfq_2_128_elt_ur_neg(K, r, s)	mpfq_2_128_elt_ur_set(K,r,s)
/* *Mpfq::gf2n::trivialities::code_for_elt_ur_sub */
#define mpfq_2_128_elt_ur_sub(K, r, s1, s2)	mpfq_2_128_elt_ur_add(K,r,s1,s2)
static inline
void mpfq_2_128_mul_ur(mpfq_2_128_dst_field, mpfq_2_128_dst_elt_ur, mpfq_2_128_src_elt, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_sqr_ur(mpfq_2_128_dst_field, mpfq_2_128_dst_elt_ur, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_reduce(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_dst_elt_ur);

/* Comparison functions */
static inline
int mpfq_2_128_cmp(mpfq_2_128_dst_field, mpfq_2_128_src_elt, mpfq_2_128_src_elt);
static inline
int mpfq_2_128_cmp_ui(mpfq_2_128_dst_field, mpfq_2_128_src_elt, unsigned long);
static inline
int mpfq_2_128_is_zero(mpfq_2_128_dst_field, mpfq_2_128_src_elt);

/* Input/output functions */
void mpfq_2_128_asprint(mpfq_2_128_dst_field, char * *, mpfq_2_128_src_elt);
void mpfq_2_128_fprint(mpfq_2_128_dst_field, FILE *, mpfq_2_128_src_elt);
/* *Mpfq::defaults::code_for_print */
#define mpfq_2_128_print(k, x)	mpfq_2_128_fprint(k,stdout,x)
int mpfq_2_128_sscan(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, const char *);
int mpfq_2_128_fscan(mpfq_2_128_dst_field, FILE *, mpfq_2_128_dst_elt);
/* *Mpfq::gf2n::io::code_for_scan */
#define mpfq_2_128_scan(k, x)	mpfq_2_128_fscan(k,stdout,x)

/* Vector functions */
void mpfq_2_128_vec_init(mpfq_2_128_dst_field, mpfq_2_128_vec *, unsigned int);
void mpfq_2_128_vec_reinit(mpfq_2_128_dst_field, mpfq_2_128_vec *, unsigned int, unsigned int);
void mpfq_2_128_vec_clear(mpfq_2_128_dst_field, mpfq_2_128_vec *, unsigned int);
static inline
void mpfq_2_128_vec_set(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, mpfq_2_128_src_vec, unsigned int);
static inline
void mpfq_2_128_vec_set_zero(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, unsigned int);
static inline
void mpfq_2_128_vec_setcoef(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, mpfq_2_128_src_elt, unsigned int);
static inline
void mpfq_2_128_vec_setcoef_ui(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, unsigned long, unsigned int);
static inline
void mpfq_2_128_vec_getcoef(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_vec, unsigned int);
static inline
void mpfq_2_128_vec_add(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, mpfq_2_128_src_vec, mpfq_2_128_src_vec, unsigned int);
static inline
void mpfq_2_128_vec_neg(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, mpfq_2_128_src_vec, unsigned int);
static inline
void mpfq_2_128_vec_rev(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, mpfq_2_128_src_vec, unsigned int);
static inline
void mpfq_2_128_vec_sub(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, mpfq_2_128_src_vec, mpfq_2_128_src_vec, unsigned int);
static inline
void mpfq_2_128_vec_scal_mul(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, mpfq_2_128_src_vec, mpfq_2_128_src_elt, unsigned int);
static inline
void mpfq_2_128_vec_conv(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, mpfq_2_128_src_vec, unsigned int, mpfq_2_128_src_vec, unsigned int);
static inline
void mpfq_2_128_vec_random(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, unsigned int);
#define HAVE_mpfq_2_128_vec_random2
static inline
void mpfq_2_128_vec_random2(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, unsigned int);
static inline
int mpfq_2_128_vec_cmp(mpfq_2_128_dst_field, mpfq_2_128_src_vec, mpfq_2_128_src_vec, unsigned int);
static inline
int mpfq_2_128_vec_is_zero(mpfq_2_128_dst_field, mpfq_2_128_src_vec, unsigned int);
void mpfq_2_128_vec_asprint(mpfq_2_128_dst_field, char * *, mpfq_2_128_src_vec, unsigned int);
void mpfq_2_128_vec_fprint(mpfq_2_128_dst_field, FILE *, mpfq_2_128_src_vec, unsigned int);
void mpfq_2_128_vec_print(mpfq_2_128_dst_field, mpfq_2_128_src_vec, unsigned int);
int mpfq_2_128_vec_sscan(mpfq_2_128_dst_field, mpfq_2_128_vec *, unsigned int *, const char *);
int mpfq_2_128_vec_fscan(mpfq_2_128_dst_field, FILE *, mpfq_2_128_vec *, unsigned int *);
/* *Mpfq::defaults::vec::io::code_for_vec_scan */
#define mpfq_2_128_vec_scan(K, w, n)	mpfq_2_128_vec_fscan(K,stdout,w,n)
void mpfq_2_128_vec_ur_init(mpfq_2_128_dst_field, mpfq_2_128_vec_ur *, unsigned int);
void mpfq_2_128_vec_ur_reinit(mpfq_2_128_dst_field, mpfq_2_128_vec_ur *, unsigned int, unsigned int);
void mpfq_2_128_vec_ur_clear(mpfq_2_128_dst_field, mpfq_2_128_vec_ur *, unsigned int);
static inline
void mpfq_2_128_vec_ur_set(mpfq_2_128_dst_field, mpfq_2_128_dst_vec_ur, mpfq_2_128_src_vec_ur, unsigned int);
static inline
void mpfq_2_128_vec_ur_setcoef(mpfq_2_128_dst_field, mpfq_2_128_dst_vec_ur, mpfq_2_128_src_elt_ur, unsigned int);
static inline
void mpfq_2_128_vec_ur_getcoef(mpfq_2_128_dst_field, mpfq_2_128_dst_elt_ur, mpfq_2_128_src_vec_ur, unsigned int);
static inline
void mpfq_2_128_vec_ur_add(mpfq_2_128_dst_field, mpfq_2_128_dst_vec_ur, mpfq_2_128_src_vec_ur, mpfq_2_128_src_vec_ur, unsigned int);
static inline
void mpfq_2_128_vec_ur_sub(mpfq_2_128_dst_field, mpfq_2_128_dst_vec_ur, mpfq_2_128_src_vec_ur, mpfq_2_128_src_vec_ur, unsigned int);
static inline
void mpfq_2_128_vec_scal_mul_ur(mpfq_2_128_dst_field, mpfq_2_128_dst_vec_ur, mpfq_2_128_src_vec, mpfq_2_128_src_elt, unsigned int);
static inline
void mpfq_2_128_vec_conv_ur_n(mpfq_2_128_dst_field, mpfq_2_128_dst_vec_ur, mpfq_2_128_src_vec, mpfq_2_128_src_vec, unsigned int);
static inline
void mpfq_2_128_vec_conv_ur(mpfq_2_128_dst_field, mpfq_2_128_dst_vec_ur, mpfq_2_128_src_vec, unsigned int, mpfq_2_128_src_vec, unsigned int);
static inline
void mpfq_2_128_vec_reduce(mpfq_2_128_dst_field, mpfq_2_128_dst_vec, mpfq_2_128_dst_vec_ur, unsigned int);
/* *Mpfq::defaults::flatdata::code_for_vec_elt_stride */
#define mpfq_2_128_vec_elt_stride(K, n)	((n)*sizeof(mpfq_2_128_elt))

/* Polynomial functions */
static inline
void mpfq_2_128_poly_init(mpfq_2_128_dst_field, mpfq_2_128_poly, unsigned int);
static inline
void mpfq_2_128_poly_clear(mpfq_2_128_dst_field, mpfq_2_128_poly);
static inline
void mpfq_2_128_poly_set(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly);
void mpfq_2_128_poly_setmonic(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly);
static inline
void mpfq_2_128_poly_setcoef(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_elt, unsigned int);
static inline
void mpfq_2_128_poly_setcoef_ui(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, unsigned long, unsigned int);
static inline
void mpfq_2_128_poly_getcoef(mpfq_2_128_dst_field, mpfq_2_128_dst_elt, mpfq_2_128_src_poly, unsigned int);
static inline
int mpfq_2_128_poly_deg(mpfq_2_128_dst_field, mpfq_2_128_src_poly);
static inline
void mpfq_2_128_poly_add(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, mpfq_2_128_src_poly);
static inline
void mpfq_2_128_poly_sub(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, mpfq_2_128_src_poly);
static inline
void mpfq_2_128_poly_add_ui(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, unsigned long);
static inline
void mpfq_2_128_poly_sub_ui(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, unsigned long);
static inline
void mpfq_2_128_poly_neg(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly);
static inline
void mpfq_2_128_poly_scal_mul(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, mpfq_2_128_src_elt);
static inline
void mpfq_2_128_poly_mul(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, mpfq_2_128_src_poly);
void mpfq_2_128_poly_divmod(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, mpfq_2_128_src_poly);
void mpfq_2_128_poly_precomp_mod(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly);
void mpfq_2_128_poly_mod_pre(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, mpfq_2_128_src_poly, mpfq_2_128_src_poly);
void mpfq_2_128_poly_gcd(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, mpfq_2_128_src_poly);
void mpfq_2_128_poly_xgcd(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, mpfq_2_128_dst_poly, mpfq_2_128_dst_poly, mpfq_2_128_src_poly, mpfq_2_128_src_poly);
static inline
void mpfq_2_128_poly_random(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, unsigned int);
#define HAVE_mpfq_2_128_poly_random2
static inline
void mpfq_2_128_poly_random2(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, unsigned int);
static inline
int mpfq_2_128_poly_cmp(mpfq_2_128_dst_field, mpfq_2_128_src_poly, mpfq_2_128_src_poly);
static inline
void mpfq_2_128_poly_asprint(mpfq_2_128_dst_field, char * *, mpfq_2_128_src_poly);
static inline
void mpfq_2_128_poly_fprint(mpfq_2_128_dst_field, FILE *, mpfq_2_128_src_poly);
static inline
void mpfq_2_128_poly_print(mpfq_2_128_dst_field, mpfq_2_128_src_poly);
static inline
int mpfq_2_128_poly_sscan(mpfq_2_128_dst_field, mpfq_2_128_dst_poly, const char *);
static inline
int mpfq_2_128_poly_fscan(mpfq_2_128_dst_field, FILE *, mpfq_2_128_dst_poly);
static inline
int mpfq_2_128_poly_scan(mpfq_2_128_dst_field, mpfq_2_128_dst_poly);
#ifdef  __cplusplus
}
#endif

/* Implementations for inlines */
/* *Mpfq::gf2n::field::code_for_field_init */
static inline
void mpfq_2_128_field_init(mpfq_2_128_dst_field f)
{
    f->io_type=16;
}

/* *Mpfq::gf2n::field::code_for_field_setopt */
static inline
void mpfq_2_128_field_setopt(mpfq_2_128_dst_field f, unsigned long x, void * y)
{
    assert(x == MPFQ_IO_TYPE);
    f->io_type=((unsigned long*)y)[0];
}

/* *Mpfq::defaults::flatdata::code_for_set */
static inline
void mpfq_2_128_set(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s)
{
    if (r != s) memcpy(r,s,sizeof(mpfq_2_128_elt));
}

/* *Mpfq::gf2n::trivialities::code_for_set_ui */
static inline
void mpfq_2_128_set_ui(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, unsigned long x)
{
    r[0] = x & 1UL;
    memset(r + 1, 0, sizeof(mpfq_2_128_elt) - sizeof(unsigned long));
}

/* *Mpfq::defaults::flatdata::code_for_set_zero */
static inline
void mpfq_2_128_set_zero(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r)
{
    mpfq_2_128_vec_set_zero(K,(mpfq_2_128_dst_vec)r,1);
}

/* *Mpfq::gf2n::trivialities::code_for_get_ui */
static inline
unsigned long mpfq_2_128_get_ui(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_src_elt r)
{
    return r[0] & 1UL;
}

/* *Mpfq::gf2n::trivialities::code_for_set_mpn */
static inline
void mpfq_2_128_set_mpn(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mp_limb_t * x, size_t n)
{
    r[0] = MPFQ_LIKELY(n > 0) ? (x[0] & 1UL) : 0;
    memset(r + 1, 0, sizeof(mpfq_2_128_elt) - sizeof(unsigned long));
}

/* *Mpfq::gf2n::trivialities::code_for_set_mpz */
static inline
void mpfq_2_128_set_mpz(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpz_t z)
{
    r[0] = mpz_getlimbn(z,0) & 1UL;
    memset(r + 1, 0, sizeof(mpfq_2_128_elt) - sizeof(unsigned long));
}

/* *Mpfq::gf2n::trivialities::code_for_get_mpn */
static inline
void mpfq_2_128_get_mpn(mpfq_2_128_dst_field K MAYBE_UNUSED, mp_limb_t * p, mpfq_2_128_src_elt r)
{
    p[0] = r[0] & 1UL;
    memset(p + 1, 0, (2 - 1) * sizeof(mp_limb_t));
}

/* *Mpfq::gf2n::trivialities::code_for_get_mpz */
static inline
void mpfq_2_128_get_mpz(mpfq_2_128_dst_field K MAYBE_UNUSED, mpz_t z, mpfq_2_128_src_elt r)
{
    mpz_set_ui(z, r[0] & 1UL);
}

/* *Mpfq::gf2n::trivialities::code_for_set_uipoly */
static inline
void mpfq_2_128_set_uipoly(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, unsigned long x)
{
    r[0] = x;
    memset(r + 1, 0, sizeof(mpfq_2_128_elt) - sizeof(unsigned long));
}

/* *Mpfq::gf2n::trivialities::code_for_set_uipoly_wide */
static inline
void mpfq_2_128_set_uipoly_wide(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, const unsigned long * x, unsigned int n)
{
    unsigned int i;
    for (i = 0 ; i < n && i < 2 ; i++)
        r[i] = x[i];
}

/* *Mpfq::gf2n::trivialities::code_for_get_uipoly */
static inline
unsigned long mpfq_2_128_get_uipoly(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_src_elt r)
{
    return r[0];
}

/* *Mpfq::gf2n::trivialities::code_for_get_uipoly_wide */
static inline
void mpfq_2_128_get_uipoly_wide(mpfq_2_128_dst_field K MAYBE_UNUSED, unsigned long * r, mpfq_2_128_src_elt x)
{
    unsigned int i;
    for(i = 0 ; i < 2 ; i++) r[i] = x[i];
}

/* *Mpfq::gf2n::trivialities::code_for_random */
static inline
void mpfq_2_128_random(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r)
{
    mpn_random(r, 2);
}

/* *Mpfq::gf2n::trivialities::code_for_random2 */
static inline
void mpfq_2_128_random2(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r)
{
    mpn_random2(r, 2);
}

/* *Mpfq::gf2n::trivialities::code_for_add */
static inline
void mpfq_2_128_add(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s1, mpfq_2_128_src_elt s2)
{
    int i;
    for(i = 0 ; i < 2 ; i++)
        r[i] = s1[i] ^ s2[i];
}

/* *Mpfq::gf2n::trivialities::code_for_mul */
static inline
void mpfq_2_128_mul(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s1, mpfq_2_128_src_elt s2)
{
    mpfq_2_128_elt_ur t;
    mpfq_2_128_mul_ur(K, t, s1, s2);
    mpfq_2_128_reduce(K, r, t);
}

/* *Mpfq::gf2n::trivialities::code_for_sqr */
static inline
void mpfq_2_128_sqr(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s)
{
    mpfq_2_128_elt_ur t;
    mpfq_2_128_sqr_ur(K, t, s);
    mpfq_2_128_reduce(K, r, t);
}

/* *Mpfq::gf2n::linearops::code_for_sqrt */
static inline
int mpfq_2_128_sqrt(mpfq_2_128_dst_field K, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s)
{
    static const mp_limb_t shuffle_table[256] = {
        0, 1, 16, 17, 2, 3, 18, 19,
        32, 33, 48, 49, 34, 35, 50, 51,
        4, 5, 20, 21, 6, 7, 22, 23,
        36, 37, 52, 53, 38, 39, 54, 55,
        64, 65, 80, 81, 66, 67, 82, 83,
        96, 97, 112, 113, 98, 99, 114, 115,
        68, 69, 84, 85, 70, 71, 86, 87,
        100, 101, 116, 117, 102, 103, 118, 119,
        8, 9, 24, 25, 10, 11, 26, 27,
        40, 41, 56, 57, 42, 43, 58, 59,
        12, 13, 28, 29, 14, 15, 30, 31,
        44, 45, 60, 61, 46, 47, 62, 63,
        72, 73, 88, 89, 74, 75, 90, 91,
        104, 105, 120, 121, 106, 107, 122, 123,
        76, 77, 92, 93, 78, 79, 94, 95,
        108, 109, 124, 125, 110, 111, 126, 127,
        128, 129, 144, 145, 130, 131, 146, 147,
        160, 161, 176, 177, 162, 163, 178, 179,
        132, 133, 148, 149, 134, 135, 150, 151,
        164, 165, 180, 181, 166, 167, 182, 183,
        192, 193, 208, 209, 194, 195, 210, 211,
        224, 225, 240, 241, 226, 227, 242, 243,
        196, 197, 212, 213, 198, 199, 214, 215,
        228, 229, 244, 245, 230, 231, 246, 247,
        136, 137, 152, 153, 138, 139, 154, 155,
        168, 169, 184, 185, 170, 171, 186, 187,
        140, 141, 156, 157, 142, 143, 158, 159,
        172, 173, 188, 189, 174, 175, 190, 191,
        200, 201, 216, 217, 202, 203, 218, 219,
        232, 233, 248, 249, 234, 235, 250, 251,
        204, 205, 220, 221, 206, 207, 222, 223,
        236, 237, 252, 253, 238, 239, 254, 255,
    };
    
    mpfq_2_128_elt sqrt_t ={ 0x6db6db6db6db6da4UL, 0x2492492492492492UL, }
    ;
    
    mpfq_2_128_elt odd, even;
    mpfq_2_128_elt_ur odd_t;
    mp_limb_t t;
#define	EVEN_MASK	(((mp_limb_t)-1)/3UL)
#define	ODD_MASK	((EVEN_MASK)<<1)
    unsigned int i;
    for(i = 0 ; i < 2 ; i++) {
        even[i] = s[i] & EVEN_MASK;
    }
    for(i = 0 ; i < 1 ; i++) {
        t = even[2*i];   t |= t >> 7;
              even[i]  = shuffle_table[t & 255];
        t >>= 16; even[i] |= shuffle_table[t & 255] << 8;
        t >>= 16; even[i] |= shuffle_table[t & 255] << 16;
        t >>= 16; even[i] |= shuffle_table[t & 255] << 24;
        t = even[2*i+1]; t |= t >> 7;
              even[i] |= shuffle_table[t & 255] << 32;
        t >>= 16; even[i] |= shuffle_table[t & 255] << 40;
        t >>= 16; even[i] |= shuffle_table[t & 255] << 48;
        t >>= 16; even[i] |= shuffle_table[t & 255] << 56;
    }
    memset(even + 1, 0, 1 * sizeof(mp_limb_t));
    for(i = 0 ; i < 2 ; i++) {
        odd[i] = (s[i] & ODD_MASK) >> 1;
    }
    for(i = 0 ; i < 1 ; i++) {
        t = odd[2*i];   t |= t >> 7;
              odd[i]  = shuffle_table[t & 255];
        t >>= 16; odd[i] |= shuffle_table[t & 255] << 8;
        t >>= 16; odd[i] |= shuffle_table[t & 255] << 16;
        t >>= 16; odd[i] |= shuffle_table[t & 255] << 24;
        t = odd[2*i+1]; t |= t >> 7;
              odd[i] |= shuffle_table[t & 255] << 32;
        t >>= 16; odd[i] |= shuffle_table[t & 255] << 40;
        t >>= 16; odd[i] |= shuffle_table[t & 255] << 48;
        t >>= 16; odd[i] |= shuffle_table[t & 255] << 56;
    }
    memset(odd + 1, 0, 1 * sizeof(mp_limb_t));
    mpfq_2_128_mul_ur(K, odd_t, odd, sqrt_t);
    for(i = 0 ; i < (2+1)/2 ; i++) {
        odd_t[i] ^= even[i];
    }
    /* mpfq_2_128_print(K, stdout, odd_t); */
    mpfq_2_128_reduce(K, r, odd_t);
    /* mpfq_2_128_print(K, stdout, r); */
    /* fprintf(stdout, "\n"); */
    /* fflush(stdout); */
    return 1;
}

/* *Mpfq::defaults::pow::code_for_pow */
static inline
void mpfq_2_128_pow(mpfq_2_128_dst_field k, mpfq_2_128_dst_elt res, mpfq_2_128_src_elt r, unsigned long * x, size_t n)
{
    mpfq_2_128_elt u, a;
    long i, j, lead;     /* it is a signed type */
    unsigned long mask;
    
    assert (n>0);
    
    /* get the correct (i,j) position of the most significant bit in x */
    for(i = n-1; i>=0 && x[i]==0; i--)
        ;
    if (i < 0) {
        mpfq_2_128_set_ui(k, res, 0);
        return;
    }
    j = 64 - 1;
    mask = (1UL<<j);
    for( ; (x[i]&mask)==0 ;j--, mask>>=1)
        ;
    lead = i*64+j;      /* Ensured. */
    
    mpfq_2_128_init(k, &u);
    mpfq_2_128_init(k, &a);
    mpfq_2_128_set(k, a, r);
    for( ; lead > 0; lead--) {
        if (j-- == 0) {
            i--;
            j = 64-1;
            mask = (1UL<<j);
        } else {
            mask >>= 1;
        }
        if (x[i]&mask) {
            mpfq_2_128_sqr(k, u, a);
            mpfq_2_128_mul(k, a, u, r);
        } else {
            mpfq_2_128_sqr(k, a,a);
        }
    }
    mpfq_2_128_set(k, res, a);
    mpfq_2_128_clear(k, &u);
    mpfq_2_128_clear(k, &a);
}

/* *Mpfq::gf2n::trivialities::code_for_add_ui */
static inline
void mpfq_2_128_add_ui(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s, unsigned long x)
{
    mpfq_2_128_set(K, r, s);
    r[0] ^= x & 1UL;
}

/* *Mpfq::gf2n::trivialities::code_for_mul_ui */
static inline
void mpfq_2_128_mul_ui(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s, unsigned long x)
{
    if (x & 1UL) {
        mpfq_2_128_set(K, r, s);
    } else {
        memset(r, 0, sizeof(mpfq_2_128_elt));
    }
}

/* *Mpfq::gf2n::trivialities::code_for_add_uipoly */
static inline
void mpfq_2_128_add_uipoly(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s, unsigned long x)
{
    mpfq_2_128_set(K, r, s);
    r[0] ^= x;
}

/* *Mpfq::gf2n::trivialities::code_for_mul_uipoly */
static inline
void mpfq_2_128_mul_uipoly(mpfq_2_128_dst_field k, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s, unsigned long x)
{
    mpfq_2_128_elt xx;
    mpfq_2_128_init(k, &xx);
    mpfq_2_128_set_uipoly(k, xx, x);
    mpfq_2_128_mul(k, r, s, xx);
    mpfq_2_128_clear(k, &xx);
}

/* *Mpfq::gf2n::inversion::code_for_inv */
static inline
void mpfq_2_128_longaddshift_left(unsigned long * dst, const unsigned long * src, int n, int s)
{
    int m = s / 64;
    int i;
    s %= 64;
    if (s>0) {
        for(i = n-m-1 ; i > 0 ; i--) {
            dst[m+i] ^= src[i] << s ^ src[i-1] >> (64-s);
        }
        dst[m] ^= src[0] << s;
    } else {
        for(i = n-m-1 ; i > 0 ; i--) {
            dst[m+i] ^= src[i];
        }
        dst[m] ^= src[0];
    }
}

/* *Mpfq::gf2n::inversion::code_for_inv */
static inline
void mpfq_2_128_longshift_left(unsigned long * dst, const unsigned long * src, int n, int s)
{
    int m = s / 64;
    int i;
    s %= 64;
    if (s > 0) {
        for(i = n-m-1 ; i > 0 ; i--) {
            dst[m+i] = src[i] << s ^ src[i-1] >> (64-s);
        }
        dst[m] = src[0] << s;
    } else {
        for(i = n-m-1 ; i > 0 ; i--) {
            dst[m+i] = src[i];
        }
        dst[m] = src[0];
    }
    for(i = m-1 ; i>= 0 ; i--) {
        dst[i] = 0UL;
    }
    
}

/* *Mpfq::gf2n::inversion::code_for_inv */
static inline
int mpfq_2_128_inv(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s)
{
    mp_limb_t a[3] = { 0x8000000000000000UL, 0x43UL, 0x8000000000000000UL, };
    mp_limb_t b[3];
    mp_limb_t u[3] = { 0, };
    mp_limb_t v[3] = { 1, 0, };
    mp_limb_t x;
    mp_size_t ia, ib;
    int i,d;
    
    if (mpfq_2_128_cmp_ui(K, s, 0UL) == 0)
        return 0;
    {
        unsigned long z;
        z = s[0] << 63;
        b[0] = z;
        z = s[0] >>  1 ^ s[1] << 63;
        b[1] = z;
        z = s[1] >>  1;
        b[2] = z;
    }
    ib = clzlx(b, 3);
    ia = 0;
    
    mpfq_2_128_longshift_left(b,b,3,ib);
    
    for(d = ib - ia ; ; ) {
            if (d == 0) {
                    for(i = 0 ; i < 3 ; i++) v[i] ^= u[i];
            b[0] ^= a[0]; x = b[0];
            b[1] ^= a[1]; x |= b[1];
            b[2] ^= a[2]; x |= b[2];
                    if (!x) { memcpy(r,u,2 * sizeof(mp_limb_t)); return 1; }
                    mp_limb_t t = clzlx(b,3);
                    ib += t;
                    d += t;
                    mpfq_2_128_longshift_left(b,b,3,t);
            }
            for(;d > 0;) {
                    mpfq_2_128_longaddshift_left(u,v,3,d);
            a[0] ^= b[0]; x = a[0];
            a[1] ^= b[1]; x |= a[1];
            a[2] ^= b[2]; x |= a[2];
                    if (!x) { memcpy(r,v,2 * sizeof(mp_limb_t)); return 1; }
                    mp_limb_t t = clzlx(a,3);
                    ia += t;
                    d -= t;
                    mpfq_2_128_longshift_left(a,a,3,t);
            } 
            if (d == 0) {
                    for(i = 0 ; i < 3 ; i++) u[i] ^= v[i];
            a[0] ^= b[0]; x = a[0];
            a[1] ^= b[1]; x |= a[1];
            a[2] ^= b[2]; x |= a[2];
                    if (!x) { memcpy(r,v,2 * sizeof(mp_limb_t)); return 1; }
                    mp_limb_t t = clzlx(a,3);
                    ia += t;
                    d -= t;
                    mpfq_2_128_longshift_left(a,a,3,t);
            }
            for(;d < 0;) {
                    mpfq_2_128_longaddshift_left(v,u,3,-d);
            b[0] ^= a[0]; x = b[0];
            b[1] ^= a[1]; x |= b[1];
            b[2] ^= a[2]; x |= b[2];
                    if (!x) { memcpy(r,u,2 * sizeof(mp_limb_t)); return 1; }
                    mp_limb_t t = clzlx(b,3);
                    ib += t;
                    d += t;
                    mpfq_2_128_longshift_left(b,b,3,t);
            }
    }
}

/* *Mpfq::gf2n::linearops::code_for_as_solve */
static inline
void mpfq_2_128_as_solve(mpfq_2_128_dst_field K, mpfq_2_128_dst_elt r, mpfq_2_128_src_elt s)
{
    static const mpfq_2_128_elt t[128] = {
        { 0x676aac9fa4b20b08UL, 0x295ac0b1f4731af9UL, },
        { 0x929959af766af404UL, 0xe5da5595ee970b89UL, },
        { 0x929959af766af406UL, 0xe5da5595ee970b89UL, },
        { 0x7783f7333404a20cUL, 0x4e9826c74350bfe6UL, },
        { 0x929959af766af402UL, 0xe5da5595ee970b89UL, },
        { 0x7dc714cb83074e6aUL, 0x2aaea79ad7da34b0UL, },
        { 0x7783f7333404a204UL, 0x4e9826c74350bfe6UL, },
        { 0xf5f3f531d2d9fe18UL, 0xcc8095241ae41171UL, },
        { 0x929959af766af412UL, 0xe5da5595ee970b89UL, },
        { 0x77cb862e8ac85b44UL, 0x4e983687d159ce96UL, },
        { 0x7dc714cb83074e4aUL, 0x2aaea79ad7da34b0UL, },
        { 0xf73fcb3c06aaff56UL, 0xaae2ab6aaf144aafUL, },
        { 0x7783f7333404a244UL, 0x4e9826c74350bfe6UL, },
        { 0x893fe9ca40603f62UL, 0xe62f327ccd5792ddUL, },
        { 0xf5f3f531d2d9fe98UL, 0xcc8095241ae41171UL, },
        { 0xe1336bc7d453b626UL, 0xab52f0323f47c90bUL, },
        { 0x929959af766af512UL, 0xe5da5595ee970b89UL, },
        { 0x79a6a089abf4573aUL, 0x2abe34bad75338b4UL, },
        { 0x77cb862e8ac85944UL, 0x4e983687d159ce96UL, },
        { 0x1a9cbef8232562fcUL, 0x1e8ccb9dcc72f2eUL, },
        { 0x7dc714cb83074a4aUL, 0x2aaea79ad7da34b0UL, },
        { 0xce869b24a80e48cUL, 0x2442c3221f3dc1aUL, },
        { 0xf73fcb3c06aaf756UL, 0xaae2ab6aaf144aafUL, },
        { 0xeb3ff936dd9aa228UL, 0xcf64612f39c4323dUL, },
        { 0x7783f7333404b244UL, 0x4e9826c74350bfe6UL, },
        { 0xf0d5382a57572458UL, 0xcc911696880d4909UL, },
        { 0x893fe9ca40601f62UL, 0xe62f327ccd5792ddUL, },
        { 0x697f6478e5db2834UL, 0x4d7cd7cc29d28cf2UL, },
        { 0xf5f3f531d2d9be98UL, 0xcc8095241ae41171UL, },
        { 0xfc0956ca1a5b86a4UL, 0xccc99127569146a7UL, },
        { 0xe1336bc7d4533626UL, 0xab52f0323f47c90bUL, },
        { 0x14f5986b001eeb82UL, 0x65cece94dacd5b1cUL, },
        { 0x929959af766bf512UL, 0xe5da5595ee970b89UL, },
        { 0x6fe27169c7c3e73aUL, 0x2b0e7fa2d509ca74UL, },
        { 0x79a6a089abf6573aUL, 0x2abe34bad75338b4UL, },
        { 0x11d3553885980142UL, 0x65df4d2648241324UL, },
        { 0x77cb862e8acc5944UL, 0x4e983687d159ce96UL, },
        { 0xef6fd21d2af671a4UL, 0xcf74f70e70ef2af7UL, },
        { 0x1a9cbef8232d62fcUL, 0x1e8ccb9dcc72f2eUL, },
        { 0xf91a9d8499490f58UL, 0xcec4b9173b16cdf9UL, },
        { 0x7dc714cb83174a4aUL, 0x2aaea79ad7da34b0UL, },
        { 0x99a6cf206b513bdcUL, 0x83f16f99175f6247UL, },
        { 0xce869b24aa0e48cUL, 0x2442c3221f3dc1aUL, },
        { 0x1b9e27ebe84671c0UL, 0x3f562a96a2aa908UL, },
        { 0xf73fcb3c06eaf756UL, 0xaae2ab6aaf144aafUL, },
        { 0xfcd6d526cddeebd4UL, 0xccc9c07ae11bcce3UL, },
        { 0xeb3ff936dd1aa228UL, 0xcf64612f39c4323dUL, },
        { 0xe461dfebe8467196UL, 0xa95fc803c09556f7UL, },
        { 0x7783f7333504b244UL, 0x4e9826c74350bfe6UL, },
        { 0x7b20ee03c15c7384UL, 0x4cdc1ab0f0ab5b2eUL, },
        { 0xf0d5382a55572458UL, 0xcc911696880d4909UL, },
        { 0xfb48c8c7fe68cf6aUL, 0xaaba68961da11d79UL, },
        { 0x893fe9ca44601f62UL, 0xe62f327ccd5792ddUL, },
        { 0x938b5c70638d3beeUL, 0xe5db5416ee209847UL, },
        { 0x697f6478eddb2834UL, 0x4d7cd7cc29d28cf2UL, },
        { 0xb49fa26a7e512ceUL, 0x6437818b95e2e76eUL, },
        { 0xf5f3f531c2d9be98UL, 0xcc8095241ae41171UL, },
        { 0x7868a299022ddf34UL, 0x4cd9020746184ba2UL, },
        { 0xfc0956ca3a5b86a4UL, 0xccc99127569146a7UL, },
        { 0x8f1d24e407e8e76cUL, 0x824171dcefbe4a8bUL, },
        { 0xe1336bc794533626UL, 0xab52f0323f47c90bUL, },
        { 0x88711e202cdc3b5eUL, 0xe62e22af1f6bf32bUL, },
        { 0x14f5986b801eeb82UL, 0x65cece94dacd5b1cUL, },
        { 0x9aadb85427b54520UL, 0x83f4672b23a92e49UL, },
        { 0x929959ae766bf512UL, 0xe5da5595ee970b89UL, },
        { 0x48711dbeccf94cUL, 0x104092097172UL, },
        { 0x6fe2716bc7c3e73aUL, 0x2b0e7fa2d509ca74UL, },
        { 0x99d6b267d0d7976cUL, 0x81edd40a7a7437cbUL, },
        { 0x79a6a08dabf6573aUL, 0x2abe34bad75338b4UL, },
        { 0x84dd884d1a5d4462UL, 0xe46a1e8deccdf96dUL, },
        { 0x11d3553085980142UL, 0x65df4d2648241324UL, },
        { 0x8ab1aeeb3a605920UL, 0x804c1cb1eac70f69UL, },
        { 0x77cb863e8acc5944UL, 0x4e983687d159ce96UL, },
        { 0xe04514377dbd55aaUL, 0xa94f4b3252499e01UL, },
        { 0xef6fd23d2af671a4UL, 0xcf74f70e70ef2af7UL, },
        { 0x978a93f3f56f619eUL, 0xe7d77da5831189d3UL, },
        { 0x1a9cbeb8232d62fcUL, 0x1e8ccb9dcc72f2eUL, },
        { 0x7a5109eab0a16ef4UL, 0x4cdd0f362b68e52aUL, },
        { 0xf91a9d0499490f58UL, 0xcec4b9173b16cdf9UL, },
        { 0x8830781e88d05912UL, 0xe4329c3d7bf23369UL, },
        { 0x7dc715cb83174a4aUL, 0x2aaea79ad7da34b0UL, },
        { 0x8618bcbfcff334e0UL, 0x8208208259738741UL, },
        { 0x99a6cd206b513bdcUL, 0x83f16f99175f6247UL, },
        { 0x6297e291f4adcc3aUL, 0x294b124ed1181a84UL, },
        { 0xce86db24aa0e48cUL, 0x2442c3221f3dc1aUL, },
        { 0x9b696b666550119eUL, 0xe78fff4114466493UL, },
        { 0x1b9e2febe84671c0UL, 0x3f562a96a2aa908UL, },
        { 0xeb568d9e63d55a14UL, 0xcd78dbfd54a1436bUL, },
        { 0xf73fdb3c06eaf756UL, 0xaae2ab6aaf144aafUL, },
        { 0xfacabbbeed722b64UL, 0xccdd4e7b1ce38d0fUL, },
        { 0xfcd6f526cddeebd4UL, 0xccc9c07ae11bcce3UL, },
        { 0x1fb4754fa43bbf3cUL, 0x3e5e1ccb1bf89c6UL, },
        { 0xeb3fb936dd1aa228UL, 0xcf64612f39c4323dUL, },
        { 0x926f68f4172caea2UL, 0xe5da00893461b455UL, },
        { 0xe4615febe8467196UL, 0xa95fc803c09556f7UL, },
        { 0x981cf1dccb9d1fd2UL, 0xe78ae2a77b3e87b1UL, },
        { 0x7782f7333504b244UL, 0x4e9826c74350bfe6UL, },
        { 0x6fd777b6c15f72c6UL, 0x2912d4222a675b0aUL, },
        { 0x7b22ee03c15c7384UL, 0x4cdc1ab0f0ab5b2eUL, },
        { 0x96f8740f85956fd2UL, 0xe7d6682e58d237f1UL, },
        { 0xf0d1382a55572458UL, 0xcc911696880d4909UL, },
        { 0xe46143c933474626UL, 0xab4366b0764a0b4bUL, },
        { 0xfb40c8c7fe68cf6aUL, 0xaaba68961da11d79UL, },
        { 0x97849bb7f7de0d9eUL, 0xe7d77d718378aeb3UL, },
        { 0x892fe9ca44601f62UL, 0xe62f327ccd5792ddUL, },
        { 0xd13f9bd382e380eUL, 0x64231d9efb5729d6UL, },
        { 0x93ab5c70638d3beeUL, 0xe5db5416ee209847UL, },
        { 0x959811bd9a557220UL, 0x81b51ab7a5fe1499UL, },
        { 0x693f6478eddb2834UL, 0x4d7cd7cc29d28cf2UL, },
        { 0x678a4ee975a08406UL, 0x295ab4bb43072c12UL, },
        { 0xbc9fa26a7e512ceUL, 0x6437818b95e2e76eUL, },
        { 0xef9e1acd25989a26UL, 0xab0eead38eb165ebUL, },
        { 0xf4f3f531c2d9be98UL, 0xcc8095241ae41171UL, },
        { 0x10185b9b29b00000UL, 0x3ba7996db230c00UL, },
        { 0x7a68a299022ddf34UL, 0x4cd9020746184ba2UL, },
        { 0x8261f45338765990UL, 0x8210932010890d05UL, },
        { 0xf80956ca3a5b86a4UL, 0xccc99127569146a7UL, },
        { 0x7f14722e3db361faUL, 0x2a88e0fbb92f0c2cUL, },
        { 0x871d24e407e8e76cUL, 0x824171dcefbe4a8bUL, },
        { 0x6fb067f47d17578aUL, 0x29b11e87b8989fd8UL, },
        { 0xf1336bc794533626UL, 0xab52f0323f47c90bUL, },
        { 0xdb7ed8c3891e6faUL, 0x38b21c09fae1613cUL, },
        { 0xa8711e202cdc3b5eUL, 0xe62e22af1f6bf32bUL, },
        { 0xa8711e202cdc3b6cUL, 0x862e22af1f6bf32bUL, },
        { 0x54f5986b801eeb82UL, 0x65cece94dacd5b1cUL, },
        { 0xb1ef36f7c270bdacUL, 0x8e8cbdc6770aef73UL, },
        { 0x1aadb85427b54520UL, 0x83f4672b23a92e49UL, },
        { 0x0UL, 0x0UL, },
    };
    const mpfq_2_128_elt * ptr = t;
    unsigned int i,j;
    memset(r, 0, sizeof(mpfq_2_128_elt));
    for(i = 0 ; i < 2 ; i++) {
        mp_limb_t a = s[i];
        for(j = 0 ; j < 64 && ptr != &t[128]; j++, ptr++) {
            if (a & 1UL) {
                mpfq_2_128_add(K, r, r, *ptr);
            }
            a >>= 1;
        }
    }
}

/* *Mpfq::gf2n::linearops::code_for_trace */
static inline
unsigned long mpfq_2_128_trace(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_src_elt s)
{
    return ((s[1]>>63) ^ (s[1]>>57)) & 1;
}

/* *Mpfq::defaults::flatdata::code_for_elt_ur_set */
static inline
void mpfq_2_128_elt_ur_set(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt_ur r, mpfq_2_128_src_elt_ur s)
{
    if (r != s) memcpy(r,s,sizeof(mpfq_2_128_elt_ur));
}

/* *Mpfq::gf2n::trivialities::code_for_elt_ur_set_ui */
static inline
void mpfq_2_128_elt_ur_set_ui(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt_ur r, unsigned long x)
{
    r[0] = x & 1UL;
    memset(r + 1, 0, sizeof(mpfq_2_128_elt_ur) - sizeof(unsigned long));
}

/* *Mpfq::gf2n::trivialities::code_for_elt_ur_add */
static inline
void mpfq_2_128_elt_ur_add(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt_ur r, mpfq_2_128_src_elt_ur s1, mpfq_2_128_src_elt_ur s2)
{
    int i;
    for(i = 0 ; i < 4 ; i++)
        r[i] = s1[i] ^ s2[i];
}

/* *Mpfq::gf2n::mul::code_for_mul_ur */
static inline
void mpfq_2_128_mul_ur(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt_ur t, mpfq_2_128_src_elt s1, mpfq_2_128_src_elt s2)
{
#if HAVE_PCLMUL
    typedef union {
        __v2di s;
        unsigned long x[2];
    } __v2di_proxy;

    __v2di ss1, ss2, s1s, s2s;
    __v2di_proxy t00, tk;
    __v2di_proxy t11;
    ss1 = _mm_loadu_si128((__v2di *)s1);
    ss2 = _mm_loadu_si128((__v2di *)s2);


    t00.s = _mm_clmulepi64_si128(ss1, ss2, 0);
    t11.s = _mm_clmulepi64_si128(ss1, ss2, 17);

    s1s = _mm_shuffle_epi32(ss1, 78);
    ss1 ^= s1s;
    s2s = _mm_shuffle_epi32(ss2, 78);
    ss2 ^= s2s;

    tk.s = _mm_clmulepi64_si128(ss1, ss2, 0);

    tk.s ^= t00.s ^ t11.s;

    /* store result */
    t[0] = t00.x[0];
    t[1] = t00.x[1] ^ tk.x[0];
    t[2] = t11.x[0] ^ tk.x[1];
    t[3] = t11.x[1];
#else
    typedef union { __v2di s; unsigned long x[2]; } v2di_proxy;
#define SHL(x, r) _mm_slli_epi64((x), (r))
#define SHR(x, r) _mm_srli_epi64((x), (r))
#define SHLD(x, r) _mm_slli_si128((x), (r) >> 3)
#define SHRD(x, r) _mm_srli_si128((x), (r) >> 3)
    __v2di u;
    __v2di t0;
    __v2di t1;
    __v2di t2;
    
    __v2di g[16];
    __v2di w;
    __v2di m = (__v2di) { 0xeeeeeeeeeeeeeeeeUL, 0xeeeeeeeeeeeeeeeeUL, };
    /* sequence update walk */
    g[ 0] = (__v2di) { 0, };
    __v2di b0 = (__v2di) { s2[0], s2[1], };
    g[ 1] = b0;
    __v2di v1 = (__v2di) { s1[0], s1[0], };
    w = -SHR(b0,63);
    __v2di v2 = (__v2di) { s1[1], s1[1], };
    v1 = SHR(v1 & m, 1); t1 = v1 & w;
    g[ 2] = SHL(b0, 1); g[ 3] = g[ 2] ^ b0;
    v2 = SHR(v2 & m, 1); t2 = v2 & w;
    g[ 4] = SHL(g[ 2], 1); g[ 5] = g[ 4] ^ b0;
    w = -SHR(g[ 2],63);
    g[ 6] = SHL(g[ 3], 1); g[ 7] = g[ 6] ^ b0;
    v1 = SHR(v1 & m, 1); t1 ^= v1 & w;
    g[ 8] = SHL(g[ 4], 1); g[ 9] = g[ 8] ^ b0;
    v2 = SHR(v2 & m, 1); t2 ^= v2 & w;
    g[10] = SHL(g[ 5], 1); g[11] = g[10] ^ b0;
    w = -SHR(g[4],63);
    g[12] = SHL(g[ 6], 1); g[13] = g[12] ^ b0;
    v1 = SHR(v1 & m, 1); t1 ^= v1 & w;
    g[14] = SHL(g[ 7], 1); g[15] = g[14] ^ b0;
    v2 = SHR(v2 & m, 1); t2 ^= v2 & w;
    
    
    
    /* round 0 */
    u = g[s1[0]       & 15]; t0  = u;
    u = g[s1[0] >>  4 & 15]; t0 ^= SHL(u,  4); t1 ^= SHR(u, 60);
    u = g[s1[0] >>  8 & 15]; t0 ^= SHL(u,  8); t1 ^= SHR(u, 56);
    u = g[s1[0] >> 12 & 15]; t0 ^= SHL(u, 12); t1 ^= SHR(u, 52);
    u = g[s1[0] >> 16 & 15]; t0 ^= SHL(u, 16); t1 ^= SHR(u, 48);
    u = g[s1[0] >> 20 & 15]; t0 ^= SHL(u, 20); t1 ^= SHR(u, 44);
    u = g[s1[0] >> 24 & 15]; t0 ^= SHL(u, 24); t1 ^= SHR(u, 40);
    u = g[s1[0] >> 28 & 15]; t0 ^= SHL(u, 28); t1 ^= SHR(u, 36);
    u = g[s1[0] >> 32 & 15]; t0 ^= SHL(u, 32); t1 ^= SHR(u, 32);
    u = g[s1[0] >> 36 & 15]; t0 ^= SHL(u, 36); t1 ^= SHR(u, 28);
    u = g[s1[0] >> 40 & 15]; t0 ^= SHL(u, 40); t1 ^= SHR(u, 24);
    u = g[s1[0] >> 44 & 15]; t0 ^= SHL(u, 44); t1 ^= SHR(u, 20);
    u = g[s1[0] >> 48 & 15]; t0 ^= SHL(u, 48); t1 ^= SHR(u, 16);
    u = g[s1[0] >> 52 & 15]; t0 ^= SHL(u, 52); t1 ^= SHR(u, 12);
    u = g[s1[0] >> 56 & 15]; t0 ^= SHL(u, 56); t1 ^= SHR(u,  8);
    u = g[s1[0] >> 60 & 15]; t0 ^= SHL(u, 60); t1 ^= SHR(u,  4);
    
    /* round 1 */
    u = g[s1[1]       & 15]; t1 ^= u;
    u = g[s1[1] >>  4 & 15]; t1 ^= SHL(u,  4); t2 ^= SHR(u, 60);
    u = g[s1[1] >>  8 & 15]; t1 ^= SHL(u,  8); t2 ^= SHR(u, 56);
    u = g[s1[1] >> 12 & 15]; t1 ^= SHL(u, 12); t2 ^= SHR(u, 52);
    u = g[s1[1] >> 16 & 15]; t1 ^= SHL(u, 16); t2 ^= SHR(u, 48);
    u = g[s1[1] >> 20 & 15]; t1 ^= SHL(u, 20); t2 ^= SHR(u, 44);
    u = g[s1[1] >> 24 & 15]; t1 ^= SHL(u, 24); t2 ^= SHR(u, 40);
    u = g[s1[1] >> 28 & 15]; t1 ^= SHL(u, 28); t2 ^= SHR(u, 36);
    u = g[s1[1] >> 32 & 15]; t1 ^= SHL(u, 32); t2 ^= SHR(u, 32);
    u = g[s1[1] >> 36 & 15]; t1 ^= SHL(u, 36); t2 ^= SHR(u, 28);
    u = g[s1[1] >> 40 & 15]; t1 ^= SHL(u, 40); t2 ^= SHR(u, 24);
    u = g[s1[1] >> 44 & 15]; t1 ^= SHL(u, 44); t2 ^= SHR(u, 20);
    u = g[s1[1] >> 48 & 15]; t1 ^= SHL(u, 48); t2 ^= SHR(u, 16);
    u = g[s1[1] >> 52 & 15]; t1 ^= SHL(u, 52); t2 ^= SHR(u, 12);
    u = g[s1[1] >> 56 & 15]; t1 ^= SHL(u, 56); t2 ^= SHR(u,  8);
    u = g[s1[1] >> 60 & 15]; t1 ^= SHL(u, 60); t2 ^= SHR(u,  4);
    /* end */
    
    /* store result */
    {
        v2di_proxy r;
        r.s = t0 ^ SHLD(t1, 64);
        t[0] = r.x[0];
        t[1] = r.x[1];
    }
    
    {
        v2di_proxy r;
        r.s = t2 ^ SHRD(t1, 64);
        t[2] = r.x[0];
        t[3] = r.x[1];
    }
#undef SHL
#undef SHR
#undef SHLD
#undef SHRD
#endif
}

/* *Mpfq::gf2n::squaring::code_for_sqr_ur */
static inline
void mpfq_2_128_sqr_ur(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt_ur t, mpfq_2_128_src_elt s)
{
    static const mp_limb_t g[16] = {
        0, 1, 4, 5, 16, 17, 20, 21,
        64, 65, 68, 69, 80, 81, 84, 85,
    };
    {
        mp_limb_t u;
        u = g[s[0]       & 15];
    t[0]  = u;
        u = g[s[0] >>  4 & 15];
    t[0] ^= u <<  8;
        u = g[s[0] >>  8 & 15];
    t[0] ^= u << 16;
        u = g[s[0] >> 12 & 15];
    t[0] ^= u << 24;
        u = g[s[0] >> 16 & 15];
    t[0] ^= u << 32;
        u = g[s[0] >> 20 & 15];
    t[0] ^= u << 40;
        u = g[s[0] >> 24 & 15];
    t[0] ^= u << 48;
        u = g[s[0] >> 28 & 15];
    t[0] ^= u << 56;
        u = g[s[0] >> 32 & 15];
    t[1]  = u;
        u = g[s[0] >> 36 & 15];
    t[1] ^= u <<  8;
        u = g[s[0] >> 40 & 15];
    t[1] ^= u << 16;
        u = g[s[0] >> 44 & 15];
    t[1] ^= u << 24;
        u = g[s[0] >> 48 & 15];
    t[1] ^= u << 32;
        u = g[s[0] >> 52 & 15];
    t[1] ^= u << 40;
        u = g[s[0] >> 56 & 15];
    t[1] ^= u << 48;
        u = g[s[0] >> 60 & 15];
    t[1] ^= u << 56;
        u = g[s[1]       & 15];
    t[2]  = u;
        u = g[s[1] >>  4 & 15];
    t[2] ^= u <<  8;
        u = g[s[1] >>  8 & 15];
    t[2] ^= u << 16;
        u = g[s[1] >> 12 & 15];
    t[2] ^= u << 24;
        u = g[s[1] >> 16 & 15];
    t[2] ^= u << 32;
        u = g[s[1] >> 20 & 15];
    t[2] ^= u << 40;
        u = g[s[1] >> 24 & 15];
    t[2] ^= u << 48;
        u = g[s[1] >> 28 & 15];
    t[2] ^= u << 56;
        u = g[s[1] >> 32 & 15];
    t[3]  = u;
        u = g[s[1] >> 36 & 15];
    t[3] ^= u <<  8;
        u = g[s[1] >> 40 & 15];
    t[3] ^= u << 16;
        u = g[s[1] >> 44 & 15];
    t[3] ^= u << 24;
        u = g[s[1] >> 48 & 15];
    t[3] ^= u << 32;
        u = g[s[1] >> 52 & 15];
    t[3] ^= u << 40;
        u = g[s[1] >> 56 & 15];
    t[3] ^= u << 48;
        u = g[s[1] >> 60 & 15];
    t[3] ^= u << 56;
    }
}

/* *Mpfq::gf2n::reduction::code_for_reduce */
static inline
void mpfq_2_128_reduce(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt r, mpfq_2_128_dst_elt_ur t)
{
    {
        mp_limb_t s[3];
        /* 127 excess bits */
        {
            unsigned long z;
            z = t[0];
            s[0] = z;
            z = t[1];
            s[1] = z;
        }
        memset(s + 2, 0, 1 * sizeof(mp_limb_t));
        {
            unsigned long z;
            z = t[2];
            s[0]^= z <<  7;
            s[0]^= z <<  2;
            s[0]^= z <<  1;
            s[0]^= z;
            z >>= 57;
            z^= t[3] <<  7;
            s[1]^= z;
            z >>= 5;
            z^= t[3] >> 57 << 59;
            s[1]^= z;
            z >>= 1;
            z^= t[3] >> 62 << 63;
            s[1]^= z;
            z >>= 1;
            s[1]^= z;
            z >>= 57;
            s[2]^= z;
            z >>= 5;
            s[2]^= z;
        }
        /* 6 excess bits */
        {
            unsigned long z;
            z = s[0];
            r[0] = z;
            z = s[1];
            r[1] = z;
        }
        {
            unsigned long z;
            z = s[2];
            r[0]^= z <<  7;
            r[0]^= z <<  2;
            r[0]^= z <<  1;
            r[0]^= z;
        }
    }
}

/* *Mpfq::gf2n::trivialities::code_for_cmp */
static inline
int mpfq_2_128_cmp(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_src_elt a, mpfq_2_128_src_elt b)
{
    return mpn_cmp(a, b, 2);
}

/* *Mpfq::gf2n::trivialities::code_for_cmp_ui */
static inline
int mpfq_2_128_cmp_ui(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_src_elt r, unsigned long x)
{
    int i;
    if (r[0] < (x & 1UL)) return -1;
    if (r[0] > (x & 1UL)) return 1;
    for(i = 1 ; i < 2 ; i++) {
        if (r[i]) return 1;
    }
    return 0;
}

/* *Mpfq::defaults::flatdata::code_for_is_zero */
static inline
int mpfq_2_128_is_zero(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_src_elt r)
{
        unsigned int i;
        for(i = 0 ; i < sizeof(mpfq_2_128_elt)/sizeof(r[0]) ; i++) {
            if (r[i]) return 0;
        }
        return 1;
}

/* *Mpfq::defaults::vec::flatdata::code_for_vec_set */
static inline
void mpfq_2_128_vec_set(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec r, mpfq_2_128_src_vec s, unsigned int n)
{
    if (r != s) memcpy(r, s, n*sizeof(mpfq_2_128_elt));
}

/* *Mpfq::defaults::vec::flatdata::code_for_vec_set_zero */
static inline
void mpfq_2_128_vec_set_zero(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec r, unsigned int n)
{
    memset(r, 0, n*sizeof(mpfq_2_128_elt));
}

/* *Mpfq::defaults::vec::getset::code_for_vec_setcoef */
static inline
void mpfq_2_128_vec_setcoef(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, mpfq_2_128_src_elt x, unsigned int i)
{
    mpfq_2_128_set(K, w[i], x);
}

/* *Mpfq::defaults::vec::getset::code_for_vec_setcoef_ui */
static inline
void mpfq_2_128_vec_setcoef_ui(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, unsigned long x, unsigned int i)
{
    mpfq_2_128_set_ui(K, w[i], x);
}

/* *Mpfq::defaults::vec::getset::code_for_vec_getcoef */
static inline
void mpfq_2_128_vec_getcoef(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt x, mpfq_2_128_src_vec w, unsigned int i)
{
    mpfq_2_128_set(K, x, w[i]);
}

/* *Mpfq::defaults::vec::addsub::code_for_vec_add */
static inline
void mpfq_2_128_vec_add(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, mpfq_2_128_src_vec u, mpfq_2_128_src_vec v, unsigned int n)
{
        unsigned int i;
    for(i = 0; i < n; i+=1)
        mpfq_2_128_add(K, w[i], u[i], v[i]);
}

/* *Mpfq::defaults::vec::addsub::code_for_vec_neg */
static inline
void mpfq_2_128_vec_neg(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, mpfq_2_128_src_vec u, unsigned int n)
{
        unsigned int i;
    for(i = 0; i < n; ++i)
        mpfq_2_128_neg(K, w[i], u[i]);
}

/* *Mpfq::defaults::vec::addsub::code_for_vec_rev */
static inline
void mpfq_2_128_vec_rev(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, mpfq_2_128_src_vec u, unsigned int n)
{
    unsigned int nn = n >> 1;
    mpfq_2_128_elt tmp[1];
    mpfq_2_128_init(K, tmp);
    unsigned int i;
    for(i = 0; i < nn; ++i) {
        mpfq_2_128_set(K, tmp[0], u[i]);
        mpfq_2_128_set(K, w[i], u[n-1-i]);
        mpfq_2_128_set(K, w[n-1-i], tmp[0]);
    }
    if (n & 1)
        mpfq_2_128_set(K, w[nn], u[nn]);
    mpfq_2_128_clear(K, tmp);
}

/* *Mpfq::defaults::vec::addsub::code_for_vec_sub */
static inline
void mpfq_2_128_vec_sub(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, mpfq_2_128_src_vec u, mpfq_2_128_src_vec v, unsigned int n)
{
    unsigned int i;
    for(i = 0; i < n; ++i)
        mpfq_2_128_sub(K, w[i], u[i], v[i]);
}

/* *Mpfq::defaults::vec::mul::code_for_vec_scal_mul */
static inline
void mpfq_2_128_vec_scal_mul(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, mpfq_2_128_src_vec u, mpfq_2_128_src_elt x, unsigned int n)
{
        unsigned int i;
    for(i = 0; i < n; i+=1)
        mpfq_2_128_mul(K, w[i], u[i], x);
}

/* *Mpfq::defaults::vec::conv::code_for_vec_conv */
static inline
void mpfq_2_128_vec_conv(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, mpfq_2_128_src_vec u, unsigned int n, mpfq_2_128_src_vec v, unsigned int m)
{
    mpfq_2_128_vec_ur tmp;
    mpfq_2_128_vec_ur_init(K, &tmp, m+n-1);
    mpfq_2_128_vec_conv_ur(K, tmp, u, n, v, m);
    mpfq_2_128_vec_reduce(K, w, tmp, m+n-1);
    mpfq_2_128_vec_ur_clear(K, &tmp, m+n-1);
}

/* *Mpfq::defaults::vec::getset::code_for_vec_random */
static inline
void mpfq_2_128_vec_random(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, unsigned int n)
{
    unsigned int i;
    for(i = 0; i < n; ++i)
        mpfq_2_128_random(K, w[i]);
}

/* *Mpfq::defaults::vec::getset::code_for_vec_random2 */
static inline
void mpfq_2_128_vec_random2(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, unsigned int n)
{
    unsigned int i;
    for(i = 0; i < n; ++i)
        mpfq_2_128_random2(K, w[i]);
}

/* *Mpfq::defaults::vec::getset::code_for_vec_cmp */
static inline
int mpfq_2_128_vec_cmp(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_src_vec u, mpfq_2_128_src_vec v, unsigned int n)
{
    unsigned int i;
    for(i = 0; i < n; ++i) {
        int ret = mpfq_2_128_cmp(K, u[i], v[i]);
        if (ret != 0)
            return ret;
    }
    return 0;
}

/* *Mpfq::defaults::vec::flatdata::code_for_vec_is_zero */
static inline
int mpfq_2_128_vec_is_zero(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_src_vec r, unsigned int n)
{
    unsigned int i;
    for(i = 0 ; i < n ; i+=1) {
        if (!mpfq_2_128_is_zero(K,r[i])) return 0;
    }
    return 1;
}

/* *Mpfq::defaults::vec::flatdata::code_for_vec_ur_set */
static inline
void mpfq_2_128_vec_ur_set(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec_ur r, mpfq_2_128_src_vec_ur s, unsigned int n)
{
    if (r != s) memcpy(r, s, n*sizeof(mpfq_2_128_elt_ur));
}

/* *Mpfq::defaults::vec::getset::code_for_vec_ur_setcoef */
static inline
void mpfq_2_128_vec_ur_setcoef(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec_ur w, mpfq_2_128_src_elt_ur x, unsigned int i)
{
    mpfq_2_128_elt_ur_set(K, w[i], x);
}

/* *Mpfq::defaults::vec::getset::code_for_vec_ur_getcoef */
static inline
void mpfq_2_128_vec_ur_getcoef(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_elt_ur x, mpfq_2_128_src_vec_ur w, unsigned int i)
{
    mpfq_2_128_elt_ur_set(K, x, w[i]);
}

/* *Mpfq::defaults::vec::addsub::code_for_vec_ur_add */
static inline
void mpfq_2_128_vec_ur_add(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec_ur w, mpfq_2_128_src_vec_ur u, mpfq_2_128_src_vec_ur v, unsigned int n)
{
    unsigned int i;
    for(i = 0; i < n; i+=1)
        mpfq_2_128_elt_ur_add(K, w[i], u[i], v[i]);
}

/* *Mpfq::defaults::vec::addsub::code_for_vec_ur_sub */
static inline
void mpfq_2_128_vec_ur_sub(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec_ur w, mpfq_2_128_src_vec_ur u, mpfq_2_128_src_vec_ur v, unsigned int n)
{
    unsigned int i;
    for(i = 0; i < n; i+=1)
        mpfq_2_128_elt_ur_sub(K, w[i], u[i], v[i]);
}

/* *Mpfq::defaults::vec::mul::code_for_vec_scal_mul_ur */
static inline
void mpfq_2_128_vec_scal_mul_ur(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec_ur w, mpfq_2_128_src_vec u, mpfq_2_128_src_elt x, unsigned int n)
{
    unsigned int i;
    for(i = 0; i < n; i+=1)
        mpfq_2_128_mul_ur(K, w[i], u[i], x);
}

/* *Mpfq::defaults::vec::conv::code_for_vec_conv_ur */
static inline
void mpfq_2_128_vec_conv_ur_n(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec_ur w, mpfq_2_128_src_vec u, mpfq_2_128_src_vec v, unsigned int n)
{
    if (n == 0)
        return;
    if (n == 1) {
        mpfq_2_128_mul_ur(K, w[0], u[0], v[0]);
        return;
    }
    if (n == 2) {  // Kara 2
        mpfq_2_128_elt t1, t2;
        mpfq_2_128_init(K, &t1);
        mpfq_2_128_init(K, &t2);
        mpfq_2_128_mul_ur(K, w[0], u[0], v[0]);
        mpfq_2_128_mul_ur(K, w[2], u[1], v[1]);
        mpfq_2_128_add(K, t1, u[0], u[1]);
        mpfq_2_128_add(K, t2, v[0], v[1]);
        mpfq_2_128_mul_ur(K, w[1], t1, t2);
        mpfq_2_128_elt_ur_sub(K, w[1], w[1], w[0]);
        mpfq_2_128_elt_ur_sub(K, w[1], w[1], w[2]);
        mpfq_2_128_clear(K, &t1);
        mpfq_2_128_clear(K, &t2);
        return;
    }
    if (n == 3) {  // do it in 6
        mpfq_2_128_elt t1, t2;
        mpfq_2_128_elt_ur s;
        mpfq_2_128_init(K, &t1);
        mpfq_2_128_init(K, &t2);
        mpfq_2_128_elt_ur_init(K, &s);
        // a0*b0*(1 - X)
        mpfq_2_128_mul_ur(K, w[0], u[0], v[0]);
        mpfq_2_128_elt_ur_neg(K, w[1], w[0]);
        // a1*b1*(-X + 2*X^2 - X^3)
        mpfq_2_128_mul_ur(K, w[2], u[1], v[1]);
        mpfq_2_128_elt_ur_neg(K, w[3], w[2]);
        mpfq_2_128_elt_ur_add(K, w[2], w[2], w[2]);
        mpfq_2_128_elt_ur_add(K, w[1], w[1], w[3]);
        // a2*b2*(-X^3+X^4)
        mpfq_2_128_mul_ur(K, w[4], u[2], v[2]);
        mpfq_2_128_elt_ur_sub(K, w[3], w[3], w[4]);
        // (a0+a1)*(b0+b1)*(X - X^2)
        mpfq_2_128_add(K, t1, u[0], u[1]);
        mpfq_2_128_add(K, t2, v[0], v[1]);
        mpfq_2_128_mul_ur(K, s, t1, t2);
        mpfq_2_128_elt_ur_add(K, w[1], w[1], s);
        mpfq_2_128_elt_ur_sub(K, w[2], w[2], s);
        // (a1+a2)*(b1+b2)*(X^3 - X^2)
        mpfq_2_128_add(K, t1, u[1], u[2]);
        mpfq_2_128_add(K, t2, v[1], v[2]);
        mpfq_2_128_mul_ur(K, s, t1, t2);
        mpfq_2_128_elt_ur_add(K, w[3], w[3], s);
        mpfq_2_128_elt_ur_sub(K, w[2], w[2], s);
        // (a0+a1+a2)*(b0+b1+b2)* X^2
        mpfq_2_128_add(K, t1, u[0], t1);
        mpfq_2_128_add(K, t2, v[0], t2);
        mpfq_2_128_mul_ur(K, s, t1, t2);
        mpfq_2_128_elt_ur_add(K, w[2], w[2], s);
        return;
    }
    unsigned int n0, n1;
    n0 = n / 2;
    n1 = n - n0;
    mpfq_2_128_vec_conv_ur_n(K, w, u, v, n0);
    mpfq_2_128_vec_conv_ur_n(K, w + 2*n0, u + n0, v + n0, n1);
    mpfq_2_128_elt_ur_set_ui(K, w[2*n0-1], 0);
    
    mpfq_2_128_vec tmpu, tmpv;
    mpfq_2_128_vec_ur tmpw;
    mpfq_2_128_vec_init(K, &tmpu, n1);
    mpfq_2_128_vec_init(K, &tmpv, n1);
    mpfq_2_128_vec_ur_init(K, &tmpw, 2*n1-1);
    
    mpfq_2_128_vec_set(K, tmpu, u, n0);
    if (n1 != n0) 
        mpfq_2_128_set_ui(K, tmpu[n0], 0);
    mpfq_2_128_vec_add(K, tmpu, tmpu, u+n0, n1);
    mpfq_2_128_vec_set(K, tmpv, v, n0);
    if (n1 != n0) 
        mpfq_2_128_set_ui(K, tmpv[n0], 0);
    mpfq_2_128_vec_add(K, tmpv, tmpv, v+n0, n1);
    mpfq_2_128_vec_conv_ur_n(K, tmpw, tmpu, tmpv, n1);
    mpfq_2_128_vec_ur_sub(K, tmpw, tmpw, w, 2*n0-1);
    mpfq_2_128_vec_ur_sub(K, tmpw, tmpw, w + 2*n0, 2*n1-1);
    mpfq_2_128_vec_ur_add(K, w + n0, w + n0, tmpw, 2*n1-1);
    
    mpfq_2_128_vec_clear(K, &tmpu, n1);
    mpfq_2_128_vec_clear(K, &tmpv, n1);
    mpfq_2_128_vec_ur_clear(K, &tmpw, 2*n1-1);
    return;
}

/* *Mpfq::defaults::vec::conv::code_for_vec_conv_ur */
static inline
void mpfq_2_128_vec_conv_ur(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec_ur w, mpfq_2_128_src_vec u, unsigned int n, mpfq_2_128_src_vec v, unsigned int m)
{
    unsigned int i, j MAYBE_UNUSED, k;
    mpfq_2_128_elt_ur acc, z;
    mpfq_2_128_elt_ur_init(K, &acc);
    mpfq_2_128_elt_ur_init(K, &z);
    // swap pointers to have n <= m
    mpfq_2_128_src_vec uu, vv;
    if (n <= m) {
        uu = u; vv = v;
    } else {
        uu = v; vv = u;
        unsigned int tmp = n;
        n = m; m = tmp;
    }
    for(k = 0; k < n; ++k) {
        mpfq_2_128_mul_ur(K, acc, uu[0], vv[k]);
        for(i = 1; i <= k; ++i) {
            mpfq_2_128_mul_ur(K, z, uu[i], vv[k-i]);
            mpfq_2_128_elt_ur_add(K, acc, acc, z);
        }
        mpfq_2_128_elt_ur_set(K, w[k], acc);
    }
    for(k = n; k < m; ++k) {
        mpfq_2_128_mul_ur(K, acc, uu[0], vv[k]);
        for(i = 1; i < n; ++i) {
            mpfq_2_128_mul_ur(K, z, uu[i], vv[k-i]);
            mpfq_2_128_elt_ur_add(K, acc, acc, z);
        }
        mpfq_2_128_elt_ur_set(K, w[k], acc);
    }
    for(k = m; k < n+m-1; ++k) {
        mpfq_2_128_mul_ur(K, acc, uu[k-m+1], vv[m-1]);
        for(i = k-m+2; i < n; ++i) {
            mpfq_2_128_mul_ur(K, z, uu[i], vv[k-i]);
            mpfq_2_128_elt_ur_add(K, acc, acc, z);
        }
        mpfq_2_128_elt_ur_set(K, w[k], acc);
    }
    mpfq_2_128_elt_ur_clear(K, &acc);
    mpfq_2_128_elt_ur_clear(K, &z);
}

/* *Mpfq::defaults::vec::mul::code_for_vec_reduce */
static inline
void mpfq_2_128_vec_reduce(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_vec w, mpfq_2_128_dst_vec_ur u, unsigned int n)
{
    unsigned int i;
    for(i = 0; i < n; i+=1)
        mpfq_2_128_reduce(K, w[i], u[i]);
}

/* *Mpfq::defaults::poly::code_for_poly_init */
static inline
void mpfq_2_128_poly_init(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_poly p, unsigned int n)
{
    mpfq_2_128_vec_init(k, &(p->c), n);
    p->alloc=n;
    p->size=0;
}

/* *Mpfq::defaults::poly::code_for_poly_clear */
static inline
void mpfq_2_128_poly_clear(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_poly p)
{
    mpfq_2_128_vec_clear(k, &(p->c), p->alloc);
}

/* *Mpfq::defaults::poly::code_for_poly_set */
static inline
void mpfq_2_128_poly_set(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, mpfq_2_128_src_poly u)
{
    if (w->alloc < u->size) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, u->size);
        w->alloc = u->size;
    }
    mpfq_2_128_vec_set(k, w->c, u->c, u->size);
    w->size = u->size;
}

/* *Mpfq::defaults::poly::code_for_poly_setcoef */
static inline
void mpfq_2_128_poly_setcoef(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, mpfq_2_128_src_elt x, unsigned int i)
{
    if (w->alloc < i+1) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, i+1);
        w->alloc = i+1;
    }
    mpfq_2_128_vec_setcoef(k, w->c, x, i);
    if (w->size < i+1)
        w->size = i+1;
}

/* *Mpfq::defaults::poly::code_for_poly_setcoef_ui */
static inline
void mpfq_2_128_poly_setcoef_ui(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, unsigned long x, unsigned int i)
{
    if (w->alloc < i+1) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, i+1);
        w->alloc = i+1;
    }
    mpfq_2_128_vec_setcoef_ui(k, w->c, x, i);
    if (w->size < i+1)
        w->size = i+1;
}

/* *Mpfq::defaults::poly::code_for_poly_getcoef */
static inline
void mpfq_2_128_poly_getcoef(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_elt x, mpfq_2_128_src_poly w, unsigned int i)
{
    assert (w->size > i);
    mpfq_2_128_vec_getcoef(k, x, w->c, i);
}

/* *Mpfq::defaults::poly::code_for_poly_deg */
static inline
int mpfq_2_128_poly_deg(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_src_poly w)
{
    if (w->size == 0)
        return -1;
    int deg = w->size-1;
    while ((deg >= 0) && (mpfq_2_128_cmp_ui(K, (w->c)[deg], 0) == 0))
        deg--;
    return deg;
}

/* *Mpfq::defaults::poly::code_for_poly_add */
static inline
void mpfq_2_128_poly_add(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, mpfq_2_128_src_poly u, mpfq_2_128_src_poly v)
{
    unsigned int minsize MAYBE_UNUSED = MIN(u->size, v->size);
    unsigned int maxsize MAYBE_UNUSED = MAX(u->size, v->size);
    if (w->alloc < maxsize) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, maxsize);
        w->alloc = maxsize;
    }
    if (u->size <= v->size) {
        mpfq_2_128_vec_add(k, w->c, u->c, v->c, u->size);
        mpfq_2_128_vec_set(k, (w->c)+(u->size), (v->c)+(u->size), v->size-u->size);
    } else {
        mpfq_2_128_vec_add(k, w->c, u->c, v->c, v->size);
        mpfq_2_128_vec_set(k, (w->c)+(v->size), (u->c)+(v->size), u->size-v->size);
    }
    w->size=maxsize;
    unsigned int wdeg = mpfq_2_128_poly_deg(k, w);
    w->size=wdeg+1;
}

/* *Mpfq::defaults::poly::code_for_poly_sub */
static inline
void mpfq_2_128_poly_sub(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, mpfq_2_128_src_poly u, mpfq_2_128_src_poly v)
{
    unsigned int minsize MAYBE_UNUSED = MIN(u->size, v->size);
    unsigned int maxsize MAYBE_UNUSED = MAX(u->size, v->size);
    if (w->alloc < maxsize) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, maxsize);
        w->alloc = maxsize;
    }
    if (u->size <= v->size) {
        mpfq_2_128_vec_sub(k, w->c, u->c, v->c, u->size);
        unsigned int i;
        for (i = u->size; i < v->size; ++i)
            mpfq_2_128_neg(k, (w->c)[i], (v->c)[i]);
    } else {
        mpfq_2_128_vec_sub(k, w->c, u->c, v->c, v->size);
        mpfq_2_128_vec_set(k, (w->c)+(v->size), (u->c)+(v->size), u->size-v->size);
    }
    w->size=maxsize;
    unsigned int wdeg = mpfq_2_128_poly_deg(k, w);
    w->size=wdeg+1;
}

/* *Mpfq::defaults::poly::code_for_poly_add_ui */
static inline
void mpfq_2_128_poly_add_ui(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, mpfq_2_128_src_poly u, unsigned long x)
{
    if (u->size == 0) {
        if (x == 0) {
            w->size = 0;
            return;
        }
        if (w->alloc == 0) {
            mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, 1);
            w->alloc = 1;
        }
        w->size = 1;
        mpfq_2_128_vec_setcoef_ui(k, w->c, x, 0);
        return;
    }
    if (w->alloc < u->size) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, u->size);
        w->alloc = u->size;
    }
    mpfq_2_128_add_ui(k, (w->c)[0], (u->c)[0], x);
    mpfq_2_128_vec_set(k, (w->c)+1, (u->c)+1, u->size - 1);
    w->size=u->size;
    unsigned int wdeg = mpfq_2_128_poly_deg(k, w);
    w->size=wdeg+1;
}

/* *Mpfq::defaults::poly::code_for_poly_sub_ui */
static inline
void mpfq_2_128_poly_sub_ui(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, mpfq_2_128_src_poly u, unsigned long x)
{
    if (u->size == 0) {
        if (x == 0) {
            w->size = 0;
            return;
        }
        if (w->alloc == 0) {
            mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, 1);
            w->alloc = 1;
        }
        w->size = 1;
        mpfq_2_128_vec_setcoef_ui(k, w->c, x, 0);
        mpfq_2_128_neg(k, (w->c)[0], (w->c)[0]);
        return;
    }
    if (w->alloc < u->size) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, u->size);
        w->alloc = u->size;
    }
    mpfq_2_128_sub_ui(k, (w->c)[0], (u->c)[0], x);
    mpfq_2_128_vec_set(k, (w->c)+1, (u->c)+1, u->size - 1);
    w->size=u->size;
    unsigned int wdeg = mpfq_2_128_poly_deg(k, w);
    w->size=wdeg+1;
}

/* *Mpfq::defaults::poly::code_for_poly_neg */
static inline
void mpfq_2_128_poly_neg(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, mpfq_2_128_src_poly u)
{
    if (w->alloc < u->size) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, u->size);
        w->alloc = u->size;
    }
    mpfq_2_128_vec_neg(k, w->c, u->c, u->size);
    w->size = u->size;
}

/* *Mpfq::defaults::poly::code_for_poly_scal_mul */
static inline
void mpfq_2_128_poly_scal_mul(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, mpfq_2_128_src_poly u, mpfq_2_128_src_elt x)
{
    if (mpfq_2_128_cmp_ui(k, x, 0) == 0) {
        w->size = 0;
        return;
    }
    unsigned int n = u->size;
    if (w->alloc < n) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, n);
        w->alloc = n;
    }
    mpfq_2_128_vec_scal_mul(k, w->c, u->c, x, n);
    w->size=n;
}

/* *Mpfq::defaults::poly::code_for_poly_mul */
static inline
void mpfq_2_128_poly_mul(mpfq_2_128_dst_field K MAYBE_UNUSED, mpfq_2_128_dst_poly w, mpfq_2_128_src_poly u, mpfq_2_128_src_poly v)
{
    unsigned int usize = mpfq_2_128_poly_deg(K, u)+1;
    unsigned int vsize = mpfq_2_128_poly_deg(K, v)+1;
    if ((usize == 0) || (vsize == 0)) {
        w->size = 0;
        return;
    }
    unsigned int wsize = usize + vsize - 1;
    if (w->alloc < wsize) {
        mpfq_2_128_vec_reinit(K, &(w->c), w->alloc, wsize);
        w->alloc = wsize;
    }
    mpfq_2_128_vec_conv(K, w->c, u->c, usize, v->c, vsize);
    w->size=wsize;
}

/* *Mpfq::defaults::poly::code_for_poly_random */
static inline
void mpfq_2_128_poly_random(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, unsigned int n)
{
    n++;
    if (w->alloc < n) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, n);
        w->alloc = n;
    }
    mpfq_2_128_vec_random(k, w->c, n);
    w->size=n;
    int wdeg = mpfq_2_128_poly_deg(k, w);
    w->size=wdeg+1;
}

/* *Mpfq::defaults::poly::code_for_poly_random2 */
static inline
void mpfq_2_128_poly_random2(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, unsigned int n)
{
    if (w->alloc < n) {
        mpfq_2_128_vec_reinit(k, &(w->c), w->alloc, n);
        w->alloc = n;
    }
    mpfq_2_128_vec_random2(k, w->c, n);
    w->size=n;
    int wdeg = mpfq_2_128_poly_deg(k, w);
    w->size=wdeg+1;
}

/* *Mpfq::defaults::poly::code_for_poly_cmp */
static inline
int mpfq_2_128_poly_cmp(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_src_poly u, mpfq_2_128_src_poly v)
{
    if (u->size != v->size)
        return (int)(u->size) - (int)(v->size);
    else
        return mpfq_2_128_vec_cmp(k, u->c, v->c, u->size);
}

/* *Mpfq::defaults::poly::code_for_poly_asprint */
static inline
void mpfq_2_128_poly_asprint(mpfq_2_128_dst_field k MAYBE_UNUSED, char * * pstr, mpfq_2_128_src_poly w)
{
    mpfq_2_128_vec_asprint(k, pstr, w->c, w->size);
}

/* *Mpfq::defaults::poly::code_for_poly_fprint */
static inline
void mpfq_2_128_poly_fprint(mpfq_2_128_dst_field k MAYBE_UNUSED, FILE * file, mpfq_2_128_src_poly w)
{
    mpfq_2_128_vec_fprint(k, file, w->c, w->size);
}

/* *Mpfq::defaults::poly::code_for_poly_print */
static inline
void mpfq_2_128_poly_print(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_src_poly w)
{
    mpfq_2_128_vec_print(k, w->c, w->size);
}

/* *Mpfq::defaults::poly::code_for_poly_sscan */
static inline
int mpfq_2_128_poly_sscan(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w, const char * str)
{
    int ret;
    ret = mpfq_2_128_vec_sscan(k, &(w->c), &(w->alloc), str);
    w->size = w->alloc;
    return ret;
}

/* *Mpfq::defaults::poly::code_for_poly_fscan */
static inline
int mpfq_2_128_poly_fscan(mpfq_2_128_dst_field k MAYBE_UNUSED, FILE * file, mpfq_2_128_dst_poly w)
{
    int ret;
    ret = mpfq_2_128_vec_fscan(k, file, &(w->c), &(w->alloc));
    w->size = w->alloc;
    return ret;
}

/* *Mpfq::defaults::poly::code_for_poly_scan */
static inline
int mpfq_2_128_poly_scan(mpfq_2_128_dst_field k MAYBE_UNUSED, mpfq_2_128_dst_poly w)
{
    int ret;
    ret = mpfq_2_128_vec_scan(k, &(w->c), &(w->alloc));
    w->size = w->alloc;
    return ret;
}


#endif  /* MPFQ_2_128_H_ */

/* vim:set ft=cpp: */
