/* MPFQ generated file -- do not edit */

#include "mpfq/mpfq_2_64.h"

#ifndef GMP_LIMB_BITS
#error "Please arrange so that GMP_LIMB_BITS is defined before including this file"
#endif

#if !(GMP_LIMB_BITS == 64)
#error "Constraints not met for this file: GMP_LIMB_BITS == 64"
#endif
/* Active handler: Mpfq::defaults::vec */
/* Active handler: Mpfq::defaults */
/* Active handler: Mpfq::gf2n::field */
/* Automatically generated code for GF(2^64) */
/* Definition polynomial P = X^64 + X^4 + X^3 + X + 1 */
/* Active handler: Mpfq::gf2n::trivialities */
/* Active handler: Mpfq::gf2n::io */
/* Active handler: Mpfq::gf2n::linearops */
/* Active handler: Mpfq::gf2n::inversion */
/* Active handler: Mpfq::gf2n::reduction */
/* Active handler: Mpfq::gf2n::mul */
/* Active handler: Mpfq::defaults::poly */
/* Options used: w=64 n=64 table=/tmp/mpfq/gf2x/wizard.table slice=4 helper=/tmp/mpfq/gf2n/helper/helper output_path=/tmp/mpfq/gf2n tag=2_64 coeffs=[64, 4, 3, 1, 0] */


/* Functions operating on the field structure */

/* Element allocation functions */

/* Elementary assignment functions */

/* Assignment of random values */

/* Arithmetic operations on elements */

/* Operations involving unreduced elements */

/* Comparison functions */

/* Input/output functions */
/* *Mpfq::gf2n::io::code_for_asprint */
void mpfq_2_64_asprint(mpfq_2_64_dst_field k, char * * pstr, mpfq_2_64_src_elt x)
{
    int type = k->io_type;
    int i, n; 
    
    // Numerical io.
    if (type <= 16) {
        // allocate enough room for base 2 conversion.
        *pstr = (char *)malloc((64+1)*sizeof(char));
        if (*pstr == NULL)
            MALLOC_FAILED();
    
        mp_limb_t tmp[1 + 1];
        for (i = 0; i < 1; ++i)
            tmp[i] = x[i];
    
        // mpn_get_str() needs a non-zero most significant limb
        int msl = 1 - 1;
        while ((msl > 0) && (tmp[msl] == 0))
            msl--;
        msl++;
        if ((msl == 1) && (tmp[0] == 0)) {
            (*pstr)[0] = '0';
            (*pstr)[1] = '\0';
            return;
        }
        n = mpn_get_str((unsigned char*)(*pstr), type, tmp, msl);
        for (i = 0; i < n; ++i) {
            char c = (*pstr)[i] + '0';
            if (c > '9')
                c = c-'0'+'a'-10;
            (*pstr)[i] = c;
        }
        (*pstr)[n] = '\0';
    
        // Remove leading 0s
        int shift = 0;
        while (((*pstr)[shift] == '0') && ((*pstr)[shift+1] != '\0')) 
            shift++;
        if (shift>0) {
            i = 0;
            while ((*pstr)[i+shift] != '\0') {
                (*pstr)[i] = (*pstr)[i+shift];
                i++;
            }
            (*pstr)[i] = '\0';
        }
    
        // Return '0' instead of empty string for zero element
        if ((*pstr)[0] == '\0') {
            (*pstr)[0] = '0';
            (*pstr)[1] = '\0';
        }
    } 
    // Polynomial io.
    else {
        char c = (char)type;
        // allocate (more than) enough room for polynomial conversion.
        // Warning: this is for exponent that fit in 3 digits
        *pstr = (char *)malloc((8*64+1)*sizeof(char));
        if (*pstr == NULL)
            MALLOC_FAILED();
        {
            unsigned int j;
            int sth = 0;
            char *ptr = *pstr;
            for(j = 0 ; j < 64 ; j++) {
                if (x[j/64] >> (j % 64) & 1UL) {
                	if (sth) {
                        *ptr++ = ' ';
                        *ptr++ = '+';
                        *ptr++ = ' ';
                    }
                	sth = 1;
                	if (j == 0) {
                        *ptr++ = '1';      
                	} else if (j == 1) {
                        *ptr++ = c;      
                	} else {
                        int ret = sprintf(ptr,"%c^%d",c,j);
                        ptr += ret;
                	}
                }
            }
            if (!sth) {
                *ptr++ = '0';
            }
            *ptr = '\0';
        }
    }
}

/* *Mpfq::defaults::code_for_fprint */
void mpfq_2_64_fprint(mpfq_2_64_dst_field k, FILE * file, mpfq_2_64_src_elt x)
{
    char *str;
    mpfq_2_64_asprint(k,&str,x);
    fprintf(file,"%s",str);
    free(str);
}

/* *Mpfq::gf2n::io::code_for_sscan */
int mpfq_2_64_sscan(mpfq_2_64_dst_field k, mpfq_2_64_dst_elt z, const char * str)
{
    if (k->io_type <= 16) {
        char *tmp;
        int len = strlen(str);
        tmp = (char *)malloc(len+1);
        int i;
        for (i = 0; i < len; ++i) {
            if (str[i] > '9')
                tmp[i] = str[i] + 10 - 'a';
            else 
                tmp[i] = str[i] - '0';
        }
        mp_limb_t *zz;
        // Allocate one limb per byte... very conservative.
        zz = (mp_limb_t *)malloc(len*sizeof(mp_limb_t));
        int ret = mpn_set_str(zz, tmp, len, k->io_type);
        free(tmp);
        if (ret > 1) {
            free(zz);
            return 0;
        }
        for (i = 0; i < ret; ++i)
            z[i] = zz[i];
        for (i = ret; i < 1; ++i)
            z[i] = 0;
        free(zz);
        return 1;
    } else {
        fprintf(stderr, "Polynomial io not implemented for reading\n");
        return 0;
    }
}

/* *Mpfq::gf2n::io::code_for_fscan */
int mpfq_2_64_fscan(mpfq_2_64_dst_field k, FILE * file, mpfq_2_64_dst_elt z)
{
    char *tmp;
    int allocated, len=0;
    int c, start=0;
    allocated=100;
    tmp = (char *)malloc(allocated*sizeof(char));
    if (!tmp)
        MALLOC_FAILED();
    for(;;) {
        c = fgetc(file);
        if (c==EOF)
            break;
        if (isspace((int)(unsigned char)c)) {
            if (start==0)
                continue;
            else
                break;
        } else {
            if (len==allocated) {
                allocated+=100;
                tmp = (char*)realloc(tmp, allocated*sizeof(char));
            }
            tmp[len]=c;
            len++;
        }
    }
    if (len==allocated) {
        allocated+=1;
        tmp = (char*)realloc(tmp, allocated*sizeof(char));
    }
    tmp[len]='\0';
    int ret=mpfq_2_64_sscan(k,z,tmp);
    free(tmp);
    return ret;
}


/* Vector functions */
/* *Mpfq::defaults::vec::alloc::code_for_vec_init */
void mpfq_2_64_vec_init(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_vec * v, unsigned int n)
{
    unsigned int i;
    *v = (mpfq_2_64_vec) malloc (n*sizeof(mpfq_2_64_elt));
    for(i = 0; i < n; i+=1)
        mpfq_2_64_init(K, (*v) + i);
}

/* *Mpfq::defaults::vec::alloc::code_for_vec_reinit */
void mpfq_2_64_vec_reinit(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_vec * v, unsigned int n, unsigned int m)
{
    if (n < m) { // increase size
        unsigned int i;
        *v = (mpfq_2_64_vec) realloc (*v, m * sizeof(mpfq_2_64_elt));
        for(i = n; i < m; i+=1)
            mpfq_2_64_init(K, (*v) + i);
    } else if (m < n) { // decrease size
        unsigned int i;
        for(i = m; i < n; i+=1)
            mpfq_2_64_clear(K, (*v) + i);
        *v = (mpfq_2_64_vec) realloc (*v, m * sizeof(mpfq_2_64_elt));
    }
}

/* *Mpfq::defaults::vec::alloc::code_for_vec_clear */
void mpfq_2_64_vec_clear(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_vec * v, unsigned int n)
{
        unsigned int i;
    for(i = 0; i < n; i+=1)
        mpfq_2_64_clear(K, (*v) + i);
    free(*v);
}

/* *Mpfq::defaults::vec::io::code_for_vec_asprint */
void mpfq_2_64_vec_asprint(mpfq_2_64_dst_field K MAYBE_UNUSED, char * * pstr, mpfq_2_64_src_vec w, unsigned int n)
{
    if (n == 0) {
        *pstr = (char *)malloc(4*sizeof(char));
        sprintf(*pstr, "[ ]");
        return;
    }
    int alloc = 100;
    int len = 0;
    *pstr = (char *)malloc(alloc*sizeof(char));
    char *str = *pstr;
    *str++ = '[';
    *str++ = ' ';
    len = 2;
    unsigned int i;
    for(i = 0; i < n; i+=1) {
        if (i) {
            (*pstr)[len++] = ',';
            (*pstr)[len++] = ' ';
        }
        char *tmp;
        mpfq_2_64_asprint(K, &tmp, w[i]);
        int ltmp = strlen(tmp);
        if (len+ltmp+4 > alloc) {
            alloc = len+ltmp+100;
            *pstr = (char *)realloc(*pstr, alloc*sizeof(char));
        }
        strncpy(*pstr+len, tmp, ltmp+4);
        len += ltmp;
        free(tmp);
    }
    (*pstr)[len++] = ' ';
    (*pstr)[len++] = ']';
    (*pstr)[len] = '\0';
}

/* *Mpfq::defaults::vec::io::code_for_vec_fprint */
void mpfq_2_64_vec_fprint(mpfq_2_64_dst_field K MAYBE_UNUSED, FILE * file, mpfq_2_64_src_vec w, unsigned int n)
{
    char *str;
    mpfq_2_64_vec_asprint(K,&str,w,n);
    fprintf(file,"%s",str);
    free(str);
}

/* *Mpfq::defaults::vec::io::code_for_vec_print */
void mpfq_2_64_vec_print(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_src_vec w, unsigned int n)
{
    mpfq_2_64_vec_fprint(K,stdout,w,n);
}

/* *Mpfq::defaults::vec::io::code_for_vec_sscan */
int mpfq_2_64_vec_sscan(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_vec * w, unsigned int * n, const char * str)
{
    // start with a clean vector
    mpfq_2_64_vec_reinit(K, w, *n, 0);
    *n = 0;
    while (isspace((int)(unsigned char)str[0]))
        str++;
    if (str[0] != '[')
        return 0;
    str++;
    if (str[0] != ' ')
        return 0;
    str++;
    if (str[0] == ']') {
        return 1;
    }
    unsigned int i = 0;
    for (;;) {
        if (*n < i+1) {
            mpfq_2_64_vec_reinit(K, w, *n, i+1);
            *n = i+1;
        }
        int ret;
        ret = mpfq_2_64_sscan(K, (*w)[i], str);
        if (!ret) {
            return 0;
        }
        i++;
        while (isdigit((int)(unsigned char)str[0]))
            str++;
        while (isspace((int)(unsigned char)str[0]))
            str++;
        if (str[0] == ']')
            break;
        if (str[0] != ',')
            return 0;
        str++;
        while (isspace((int)(unsigned char)str[0]))
            str++;
    }
    return 1;
}

/* *Mpfq::defaults::vec::io::code_for_vec_fscan */
int mpfq_2_64_vec_fscan(mpfq_2_64_dst_field K MAYBE_UNUSED, FILE * file, mpfq_2_64_vec * w, unsigned int * n)
{
    char *tmp;
    int c;
    int allocated, len=0;
    allocated=100;
    tmp = (char *)malloc(allocated*sizeof(char));
    if (!tmp)
        MALLOC_FAILED();
    for(;;) {
        c = fgetc(file);
        if (c==EOF)
            return 0;
        if (len==allocated) {
            allocated+=100;
            tmp = (char*)realloc(tmp, allocated*sizeof(char));
        }
        tmp[len]=c;
        len++;
        if (c==']')
            break;
    }
    if (len==allocated) {
        allocated+=1;
        tmp = (char*)realloc(tmp, allocated*sizeof(char));
    }
    tmp[len]='\0';
    int ret=mpfq_2_64_vec_sscan(K,w,n,tmp);
    free(tmp);
    return ret;
}

/* *Mpfq::defaults::vec::alloc::code_for_vec_ur_init */
void mpfq_2_64_vec_ur_init(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_vec_ur * v, unsigned int n)
{
    unsigned int i;
    *v = (mpfq_2_64_vec_ur) malloc (n*sizeof(mpfq_2_64_elt_ur));
    for(i = 0; i < n; i+=1)
        mpfq_2_64_elt_ur_init(K, &( (*v)[i]));
}

/* *Mpfq::defaults::vec::alloc::code_for_vec_ur_reinit */
void mpfq_2_64_vec_ur_reinit(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_vec_ur * v, unsigned int n, unsigned int m)
{
    if (n < m) { // increase size
        *v = (mpfq_2_64_vec_ur) realloc (*v, m * sizeof(mpfq_2_64_elt_ur));
        unsigned int i;
        for(i = n; i < m; i+=1)
            mpfq_2_64_elt_ur_init(K, (*v) + i);
    } else if (m < n) { // decrease size
        unsigned int i;
        for(i = m; i < n; i+=1)
            mpfq_2_64_elt_ur_clear(K, (*v) + i);
        *v = (mpfq_2_64_vec_ur) realloc (*v, m * sizeof(mpfq_2_64_elt_ur));
    }
}

/* *Mpfq::defaults::vec::alloc::code_for_vec_ur_clear */
void mpfq_2_64_vec_ur_clear(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_vec_ur * v, unsigned int n)
{
    unsigned int i;
    for(i = 0; i < n; i+=1)
        mpfq_2_64_elt_ur_clear(K, &( (*v)[i]));
    free(*v);
}


/* Polynomial functions */
/* *Mpfq::defaults::poly::code_for_poly_setmonic */
void mpfq_2_64_poly_setmonic(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_dst_poly q, mpfq_2_64_src_poly p)
{
    long degp = mpfq_2_64_poly_deg(K, p);
    if (degp == -1) {
        q->size = 0;
        return;
    }
    if (degp == 0) {
        mpfq_2_64_elt aux;
        mpfq_2_64_init(K, &aux);
        mpfq_2_64_set_ui(K, aux, 1);
        mpfq_2_64_poly_setcoef(K, q, aux, 0);
        mpfq_2_64_clear(K, &aux);
        q->size = 1;
        return;
    }
    mpfq_2_64_elt lc;
    mpfq_2_64_init(K, &lc);
    mpfq_2_64_poly_getcoef(K, lc, p, degp);
    mpfq_2_64_inv(K, lc, lc);
    mpfq_2_64_poly_setcoef_ui(K, q, 1, degp);
    mpfq_2_64_vec_scal_mul(K, q->c, p->c, lc, degp);
    q->size = degp+1;
    mpfq_2_64_clear(K, &lc);
}

static void mpfq_2_64_poly_preinv(mpfq_2_64_dst_field, mpfq_2_64_dst_poly, mpfq_2_64_src_poly, int);
static /* *Mpfq::defaults::poly::code_for_poly_divmod */
void mpfq_2_64_poly_preinv(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_dst_poly q, mpfq_2_64_src_poly p, int n)
{
    // Compute the inverse of p(x) modulo x^n
    // Newton iteration: x_{n+1} = x_n + x_n(1 - a*x_n)
    // Requires p(0) = 1
    // Assume p != q (no alias)
    assert (mpfq_2_64_cmp_ui(K, p->c[0], 1) == 0);
    assert (p != q);
    int m;
    if (n <= 2) {
        mpfq_2_64_poly_setcoef_ui(K, q, 1, 0);
        q->size = 1;
        m = 1;
        if (n == 1)
            return;
    } else {
        // n >= 3: recursive call at prec m = ceil(n/2)
        m = 1 + ((n-1)/2);
        mpfq_2_64_poly_preinv(K, q, p, m);
    }
    // enlarge q if necessary
    if (q->alloc < n) {
        mpfq_2_64_vec_reinit(K, &(q->c), q->alloc, n);
        q->alloc = n;
    }
    // refine value
    mpfq_2_64_vec tmp;
    mpfq_2_64_vec_init(K, &tmp, m+n-1);
    
    mpfq_2_64_vec_conv(K, tmp, p->c, MIN(n, p->size), q->c, m);
    int nn = MIN(n, MIN(n, p->size) + m -1);
    mpfq_2_64_vec_neg(K, tmp, tmp, nn);
    mpfq_2_64_add_ui(K, tmp[0], tmp[0], 1);
    mpfq_2_64_vec_conv(K, tmp, q->c, m, tmp, nn);
    mpfq_2_64_vec_set(K, q->c + m, tmp + m, n-m);
    q->size = n;
    
    mpfq_2_64_vec_clear(K, &tmp, m+n-1);
}

/* *Mpfq::defaults::poly::code_for_poly_divmod */
void mpfq_2_64_poly_divmod(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_dst_poly q, mpfq_2_64_dst_poly r, mpfq_2_64_src_poly a, mpfq_2_64_src_poly b)
{
    if (b->size == 0) {
        fprintf(stderr, "Error: division by 0\n");
        exit(1);
    }
    if (a->size == 0) {
        q->size = 0; r->size = 0;
        return;
    }
    int dega = mpfq_2_64_poly_deg(K, a);
    if (dega<0) {
        q->size = 0; r->size = 0;
        return;
    }
    // Compute deg b and inverse of leading coef
    int degb = mpfq_2_64_poly_deg(K, b);
    if (degb<0) {
        fprintf(stderr, "Error: division by 0\n");
        exit(1);
    }
    if (degb > dega) {
        q->size=0;
        mpfq_2_64_poly_set(K, r, a);
        return;
    }
    int bmonic;
    mpfq_2_64_elt ilb;
    mpfq_2_64_init(K, &ilb);
    if (mpfq_2_64_cmp_ui(K, (b->c)[degb], 1) == 0) {
        bmonic = 1;
    } else {
        mpfq_2_64_inv(K, ilb, (b->c)[degb]);
        bmonic = 0;
    }
    
    mpfq_2_64_poly qq, rr;
    mpfq_2_64_poly_init(K, qq, dega-degb+1);
    mpfq_2_64_poly_init(K, rr, dega);
    
    mpfq_2_64_poly_set(K, rr, a);
    mpfq_2_64_elt aux, aux2;
    
    mpfq_2_64_init(K, &aux);
    mpfq_2_64_init(K, &aux2);
    
    int i;
    int j;
    for (i = dega; i >= (int)degb; --i) {
        mpfq_2_64_poly_getcoef(K, aux, rr, i);
        if (!bmonic) 
            mpfq_2_64_mul(K, aux, aux, ilb);
        mpfq_2_64_poly_setcoef(K, qq, aux, i-degb);
        for (j = i-1; j >= (int)(i - degb); --j) {
            mpfq_2_64_mul(K, aux2, aux, (b->c)[j-i+degb]);
            mpfq_2_64_sub(K, (rr->c)[j], (rr->c)[j], aux2);
        }
    }    
    
    rr->size = degb;
    int degr = mpfq_2_64_poly_deg(K, rr);
    rr->size = degr+1;
    
    if (q != NULL) 
        mpfq_2_64_poly_set(K, q, qq);
    if (r != NULL)
        mpfq_2_64_poly_set(K, r, rr);
    mpfq_2_64_clear(K, &aux);
    mpfq_2_64_clear(K, &aux2);
    mpfq_2_64_poly_clear(K, rr);
    mpfq_2_64_poly_clear(K, qq);
}

/* *Mpfq::defaults::poly::code_for_poly_precomp_mod */
void mpfq_2_64_poly_precomp_mod(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_dst_poly q, mpfq_2_64_src_poly p)
{
    assert(p != q);
    int N = mpfq_2_64_poly_deg(K, p);
    mpfq_2_64_poly rp;
    mpfq_2_64_poly_init(K, rp, N+1);
    mpfq_2_64_vec_rev(K, rp->c, p->c, N+1);
    rp->size = N+1;
    mpfq_2_64_poly_preinv(K, q, rp, N);
    mpfq_2_64_poly_clear(K, rp);
}

/* *Mpfq::defaults::poly::code_for_poly_mod_pre */
void mpfq_2_64_poly_mod_pre(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_dst_poly r, mpfq_2_64_src_poly q, mpfq_2_64_src_poly p, mpfq_2_64_src_poly irp)
{
    int N = mpfq_2_64_poly_deg(K, p);
    int degq = mpfq_2_64_poly_deg(K, q);
    if (degq < N) {
        mpfq_2_64_poly_set(K, r, q);
        return;
    }
    int m = degq - N;
    assert (degq <= 2*N-2);
    mpfq_2_64_poly revq;
    mpfq_2_64_poly_init(K, revq, MAX(degq+1, m+1));
    mpfq_2_64_vec_rev(K, revq->c, q->c, degq+1);
    revq->size = q->size;
    mpfq_2_64_poly_mul(K, revq, revq, irp);
    mpfq_2_64_vec_rev(K, revq->c, revq->c, m+1);
    revq->size = m+1;
    
    mpfq_2_64_poly_mul(K, revq, revq, p);
    mpfq_2_64_poly_sub(K, r, q, revq);
    r->size = mpfq_2_64_poly_deg(K, r)+1;
    mpfq_2_64_poly_clear(K, revq);
}

/* *Mpfq::defaults::poly::code_for_poly_gcd */
void mpfq_2_64_poly_gcd(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_dst_poly d, mpfq_2_64_src_poly a, mpfq_2_64_src_poly b)
{
    // GCD with 0 copy other operand
    long dega = mpfq_2_64_poly_deg(K, a);
    if (dega == -1) {
        mpfq_2_64_poly_setmonic(K, d, b);
        return;
    }
    long degb = mpfq_2_64_poly_deg(K, b);
    if (degb == -1) {
        mpfq_2_64_poly_setmonic(K, d, a);
        return;
    }
    // GCD with constant poly yields 1.
    if ((degb == 0) || (dega == 0)) {
        mpfq_2_64_poly_setcoef_ui(K, d, 1, 0);
        d->size=1;
        return;
    }
    
    mpfq_2_64_poly aa, bb;
    mpfq_2_64_poly_init(K, aa, dega+1);
    mpfq_2_64_poly_init(K, bb, degb+1);
    mpfq_2_64_vec_set(K, aa->c, a->c, dega+1);
    mpfq_2_64_vec_set(K, bb->c, b->c, degb+1);
    aa->size=dega+1;
    bb->size=degb+1;
    
    // Force deg(A) < deg(B)
    mpfq_2_64_poly_struct * A, * B;
    if (dega < degb) {
        A = &(aa[0]);
        B = &(bb[0]);
    } else if (dega > degb) {
        B = &(aa[0]);
        A = &(bb[0]);
        long tmp = dega;
        dega = degb;
        degb = tmp;
    } else { // equal degree, do one step
        mpfq_2_64_poly_divmod(K, NULL, aa, aa, bb);
        A = &(aa[0]);
        B = &(bb[0]);
        dega = mpfq_2_64_poly_deg(K, A);
    }
    
    // entering here, we have deg(A) < deg(B)
    while (mpfq_2_64_poly_deg(K, A) > 0) {
        mpfq_2_64_poly_divmod(K, NULL, B, B, A);
        mpfq_2_64_poly_struct *tmp;
        tmp = A; A = B; B = tmp;
    }
    // now we have deg(B) > 0 and deg(A) <= 0
    
    if (mpfq_2_64_poly_deg(K, A) == -1) {
        mpfq_2_64_poly_setmonic(K, d, B);
    } else {
        assert (mpfq_2_64_poly_deg(K, A) == 0);
        mpfq_2_64_poly_setcoef_ui(K, d, 1, 0);
        d->size=1;
    }
    mpfq_2_64_poly_clear(K, aa);
    mpfq_2_64_poly_clear(K, bb);
}

static void mpfq_2_64_poly_swap(mpfq_2_64_dst_field, mpfq_2_64_dst_poly, mpfq_2_64_dst_poly);
static /* *Mpfq::defaults::poly::code_for_poly_xgcd */
void mpfq_2_64_poly_swap(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_dst_poly U, mpfq_2_64_dst_poly V)
{
    mpfq_2_64_vec tmp;
    tmp = U->c; U->c = V->c; V->c = tmp;
    unsigned long xx;
    xx = U->alloc; U->alloc = V->alloc; V->alloc = xx;
    xx = U->size; U->size = V->size; V->size = xx;
}

static void mpfq_2_64_poly_IterHalfGCD(mpfq_2_64_dst_field, mpfq_2_64_polymat *, mpfq_2_64_dst_poly, mpfq_2_64_dst_poly, long);
static /* *Mpfq::defaults::poly::code_for_poly_xgcd */
void mpfq_2_64_poly_IterHalfGCD(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_polymat * M, mpfq_2_64_dst_poly UU, mpfq_2_64_dst_poly VV, long d_red)
{
    mpfq_2_64_poly_setcoef_ui(K, M->c00, 1, 0);
    M->c00->size=1;
    mpfq_2_64_poly_setcoef_ui(K, M->c11, 1, 0);
    M->c11->size=1;
    M->c01->size=0;
    M->c10->size=0;
    
    long goal = mpfq_2_64_poly_deg(K, UU) - d_red;
    
    if (mpfq_2_64_poly_deg(K, VV) <= goal)
        return;
    
    mpfq_2_64_poly_struct *U, *V;
    U = &UU[0]; V = &VV[0];
    
    mpfq_2_64_poly Q, t;
    mpfq_2_64_poly_init(K, Q, 0);
    mpfq_2_64_poly_init(K, t, 0);
    while (mpfq_2_64_poly_deg(K, V) > goal) {
        mpfq_2_64_poly_divmod(K, Q, U, U, V);
        {
            mpfq_2_64_poly_struct * tmp;
            tmp = U; U = V; V = tmp;
        }
    
        mpfq_2_64_poly_mul(K, t, Q, M->c10);
        mpfq_2_64_poly_sub(K, t, M->c00, t);
        mpfq_2_64_poly_set(K, M->c00, M->c10);
        mpfq_2_64_poly_set(K, M->c10, t);
    
        mpfq_2_64_poly_mul(K, t, Q, M->c11);
        mpfq_2_64_poly_sub(K, t, M->c01, t);
        mpfq_2_64_poly_set(K, M->c01, M->c11);
        mpfq_2_64_poly_set(K, M->c11, t);
    }
    if (U != &UU[0]) {
        mpfq_2_64_poly_swap(K, UU, VV);
    }
    mpfq_2_64_poly_clear(K, Q);
    mpfq_2_64_poly_clear(K, t);
}

static void mpfq_2_64_poly_mat_mul(mpfq_2_64_dst_field, mpfq_2_64_polymat *, mpfq_2_64_dst_poly, mpfq_2_64_dst_poly);
static /* *Mpfq::defaults::poly::code_for_poly_xgcd */
void mpfq_2_64_poly_mat_mul(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_polymat * M, mpfq_2_64_dst_poly U, mpfq_2_64_dst_poly V)
{
    // (U, V)^t := M * (U, V)^t
    mpfq_2_64_poly aux1, aux2, aux3;
    mpfq_2_64_poly_init(K, aux1, 0);
    mpfq_2_64_poly_init(K, aux2, 0);
    mpfq_2_64_poly_init(K, aux3, 0);
    mpfq_2_64_poly_mul(K, aux1, M->c00, U);
    mpfq_2_64_poly_mul(K, aux2, M->c01, V);
    mpfq_2_64_poly_add(K, aux2, aux2, aux1);
    
    mpfq_2_64_poly_mul(K, aux1, M->c10, U);
    mpfq_2_64_poly_mul(K, aux3, M->c11, V);
    mpfq_2_64_poly_add(K, V, aux1, aux3);
    mpfq_2_64_poly_set(K, U, aux2);
    mpfq_2_64_poly_clear(K, aux1);
    mpfq_2_64_poly_clear(K, aux2);
    mpfq_2_64_poly_clear(K, aux3);
}

static void mpfq_2_64_polymat_mul(mpfq_2_64_dst_field, mpfq_2_64_polymat *, mpfq_2_64_polymat *, mpfq_2_64_polymat *);
static /* *Mpfq::defaults::poly::code_for_poly_xgcd */
void mpfq_2_64_polymat_mul(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_polymat * M, mpfq_2_64_polymat * M1, mpfq_2_64_polymat * M2)
{
    // M = M1*M2
    // TODO: Strassen!!!
    mpfq_2_64_poly aux1, aux2;
    mpfq_2_64_poly_init(K, aux1, 0);
    mpfq_2_64_poly_init(K, aux2, 0);
    mpfq_2_64_poly_mul(K, aux1, M1->c00, M2->c00);
    mpfq_2_64_poly_mul(K, aux2, M1->c01, M2->c10);
    mpfq_2_64_poly_add(K, M->c00, aux2, aux1);
    mpfq_2_64_poly_mul(K, aux1, M1->c00, M2->c01);
    mpfq_2_64_poly_mul(K, aux2, M1->c01, M2->c11);
    mpfq_2_64_poly_add(K, M->c01, aux2, aux1);
    mpfq_2_64_poly_mul(K, aux1, M1->c10, M2->c00);
    mpfq_2_64_poly_mul(K, aux2, M1->c11, M2->c10);
    mpfq_2_64_poly_add(K, M->c10, aux2, aux1);
    mpfq_2_64_poly_mul(K, aux1, M1->c10, M2->c01);
    mpfq_2_64_poly_mul(K, aux2, M1->c11, M2->c11);
    mpfq_2_64_poly_add(K, M->c11, aux2, aux1);
    mpfq_2_64_poly_clear(K, aux1);
    mpfq_2_64_poly_clear(K, aux2);
}

static void mpfq_2_64_poly_HalfGCD(mpfq_2_64_dst_field, mpfq_2_64_polymat *, mpfq_2_64_dst_poly, mpfq_2_64_dst_poly, long);
static /* *Mpfq::defaults::poly::code_for_poly_xgcd */
void mpfq_2_64_poly_HalfGCD(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_polymat * M, mpfq_2_64_dst_poly U, mpfq_2_64_dst_poly V, long d_red)
{
    if ((mpfq_2_64_poly_deg(K, V) == -1) ||
            (mpfq_2_64_poly_deg(K, V) <= (mpfq_2_64_poly_deg(K, U) - d_red))) {
        mpfq_2_64_poly_setcoef_ui(K, M->c00, 1, 0);
        M->c00->size=1;
        mpfq_2_64_poly_setcoef_ui(K, M->c11, 1, 0);
        M->c11->size=1;
        M->c01->size=0;
        M->c10->size=0;
        return;
    }
    // printf("Starting HalfGCD(%d)\n", d_red);
    
    long n = mpfq_2_64_poly_deg(K, U) - 2*d_red + 2;
    if (n < 0) n = 0;
    
    mpfq_2_64_poly U1, V1;
    mpfq_2_64_poly_init(K, U1, mpfq_2_64_poly_deg(K, U)-n+1);
    mpfq_2_64_poly_init(K, V1, mpfq_2_64_poly_deg(K, V)-n+1);
    
    mpfq_2_64_vec_set(K, U1->c, U->c+n, MAX(mpfq_2_64_poly_deg(K, U)+1-n, 0));
    mpfq_2_64_vec_set(K, V1->c, V->c+n, MAX(mpfq_2_64_poly_deg(K, V)+1-n, 0));
    U1->size = MAX(mpfq_2_64_poly_deg(K, U)-n+1, 0);
    V1->size = MAX(mpfq_2_64_poly_deg(K, V)-n+1, 0);
#define GCD_THRESHOLD 50
    if (d_red <= GCD_THRESHOLD) {
        mpfq_2_64_poly_IterHalfGCD(K, M, U1, V1, d_red);
        mpfq_2_64_poly_clear(K, U1);
        mpfq_2_64_poly_clear(K, V1);
        return;
    }
    
    long d1 = (d_red + 1)/2;
    if (d1 < 1) d1 = 1;
    if (d1 >= d_red) d1 = d_red - 1;
    
    mpfq_2_64_polymat M1;
    mpfq_2_64_poly_init(K, M1.c00, 0); mpfq_2_64_poly_init(K, M1.c01, 0);
    mpfq_2_64_poly_init(K, M1.c10, 0); mpfq_2_64_poly_init(K, M1.c11, 0);
    
    mpfq_2_64_poly_HalfGCD(K, &M1, U1, V1, d1);
    mpfq_2_64_poly_mat_mul(K, &M1, U1, V1);
    
    long d2 = mpfq_2_64_poly_deg(K, V1) - mpfq_2_64_poly_deg(K, U) + n + d_red;
    
    if ((mpfq_2_64_poly_deg(K, V1) == -1) || d2 <= 0) {
        mpfq_2_64_poly_set(K, M->c00, M1.c00);
        mpfq_2_64_poly_set(K, M->c01, M1.c01);
        mpfq_2_64_poly_set(K, M->c10, M1.c10);
        mpfq_2_64_poly_set(K, M->c11, M1.c11);
        mpfq_2_64_poly_clear(K, M1.c00); mpfq_2_64_poly_clear(K, M1.c01);
        mpfq_2_64_poly_clear(K, M1.c10); mpfq_2_64_poly_clear(K, M1.c11);
        return;
    }
    
    mpfq_2_64_poly Q;
    mpfq_2_64_polymat M2;
    mpfq_2_64_poly_init(K, Q, 0);
    mpfq_2_64_poly_init(K, M2.c00, 0); mpfq_2_64_poly_init(K, M2.c01, 0);
    mpfq_2_64_poly_init(K, M2.c10, 0); mpfq_2_64_poly_init(K, M2.c11, 0);
    
    mpfq_2_64_poly_divmod(K, Q, U1, U1, V1);
    mpfq_2_64_poly_swap(K, U1, V1);
    
    mpfq_2_64_poly_HalfGCD(K, &M2, U1, V1, d2);
    
    mpfq_2_64_poly t;
    mpfq_2_64_poly_init(K, t, 0);
    
    mpfq_2_64_poly_mul(K, t, Q, M1.c10);
    mpfq_2_64_poly_sub(K, t, M1.c00, t);
    mpfq_2_64_poly_swap(K, M1.c00, M1.c10);
    mpfq_2_64_poly_swap(K, M1.c10, t);
    
    mpfq_2_64_poly_mul(K, t, Q, M1.c11);
    mpfq_2_64_poly_sub(K, t, M1.c01, t);
    mpfq_2_64_poly_swap(K, M1.c01, M1.c11);
    mpfq_2_64_poly_swap(K, M1.c11, t);
    
    mpfq_2_64_poly_clear(K, t);
    mpfq_2_64_poly_clear(K, Q);
    
    mpfq_2_64_polymat_mul(K, M, &M2, &M1);
    mpfq_2_64_poly_clear(K, M1.c00); mpfq_2_64_poly_clear(K, M1.c01);
    mpfq_2_64_poly_clear(K, M1.c10); mpfq_2_64_poly_clear(K, M1.c11);
    mpfq_2_64_poly_clear(K, M2.c00); mpfq_2_64_poly_clear(K, M2.c01);
    mpfq_2_64_poly_clear(K, M2.c10); mpfq_2_64_poly_clear(K, M2.c11);
}

static void mpfq_2_64_poly_xHalfGCD(mpfq_2_64_dst_field, mpfq_2_64_polymat *, mpfq_2_64_dst_poly, mpfq_2_64_dst_poly, long);
static /* *Mpfq::defaults::poly::code_for_poly_xgcd */
void mpfq_2_64_poly_xHalfGCD(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_polymat * M, mpfq_2_64_dst_poly U, mpfq_2_64_dst_poly V, long d_red)
{
    if ((mpfq_2_64_poly_deg(K, V) == -1) ||
            (mpfq_2_64_poly_deg(K, V) <= (mpfq_2_64_poly_deg(K, U) - d_red))) {
        mpfq_2_64_poly_setcoef_ui(K, M->c00, 1, 0);
        M->c00->size=1;
        mpfq_2_64_poly_setcoef_ui(K, M->c11, 1, 0);
        M->c11->size=1;
        M->c01->size=0;
        M->c10->size=0;
        return;
    }
    long du = mpfq_2_64_poly_deg(K, U);
#define XGCD_THRESHOLD 50
    if (d_red <= XGCD_THRESHOLD) {
        mpfq_2_64_poly_IterHalfGCD(K, M, U, V, d_red);
        return;
    }
    // printf("Starting xHalfGCD(%d)\n", d_red);
    
    
    long d1 = (d_red + 1)/2;
    if (d1 < 1) d1 = 1;
    if (d1 >= d_red) d1 = d_red - 1;
    
    mpfq_2_64_polymat M1;
    mpfq_2_64_poly_init(K, M1.c00, 0); mpfq_2_64_poly_init(K, M1.c01, 0);
    mpfq_2_64_poly_init(K, M1.c10, 0); mpfq_2_64_poly_init(K, M1.c11, 0);
    
    mpfq_2_64_poly_HalfGCD(K, &M1, U, V, d1);
    mpfq_2_64_poly_mat_mul(K, &M1, U, V);
    
    long d2 = mpfq_2_64_poly_deg(K, V) - du + d_red;
    
    if ((mpfq_2_64_poly_deg(K, V) == -1) || d2 <= 0) {
        mpfq_2_64_poly_set(K, M->c00, M1.c00);
        mpfq_2_64_poly_set(K, M->c01, M1.c01);
        mpfq_2_64_poly_set(K, M->c10, M1.c10);
        mpfq_2_64_poly_set(K, M->c11, M1.c11);
        mpfq_2_64_poly_clear(K, M1.c00); mpfq_2_64_poly_clear(K, M1.c01);
        mpfq_2_64_poly_clear(K, M1.c10); mpfq_2_64_poly_clear(K, M1.c11);
        return;
    }
    
    mpfq_2_64_poly Q;
    mpfq_2_64_polymat M2;
    mpfq_2_64_poly_init(K, Q, 0);
    mpfq_2_64_poly_init(K, M2.c00, 0); mpfq_2_64_poly_init(K, M2.c01, 0);
    mpfq_2_64_poly_init(K, M2.c10, 0); mpfq_2_64_poly_init(K, M2.c11, 0);
    
    mpfq_2_64_poly_divmod(K, Q, U, U, V);
    mpfq_2_64_poly_swap(K, U, V);
    
    mpfq_2_64_poly_xHalfGCD(K, &M2, U, V, d2);
    
    mpfq_2_64_poly t;
    mpfq_2_64_poly_init(K, t, 0);
    
    mpfq_2_64_poly_mul(K, t, Q, M1.c10);
    mpfq_2_64_poly_sub(K, t, M1.c00, t);
    mpfq_2_64_poly_swap(K, M1.c00, M1.c10);
    mpfq_2_64_poly_swap(K, M1.c10, t);
    
    mpfq_2_64_poly_mul(K, t, Q, M1.c11);
    mpfq_2_64_poly_sub(K, t, M1.c01, t);
    mpfq_2_64_poly_swap(K, M1.c01, M1.c11);
    mpfq_2_64_poly_swap(K, M1.c11, t);
    
    mpfq_2_64_poly_clear(K, t);
    mpfq_2_64_poly_clear(K, Q);
    
    mpfq_2_64_polymat_mul(K, M, &M2, &M1);
    mpfq_2_64_poly_clear(K, M1.c00); mpfq_2_64_poly_clear(K, M1.c01);
    mpfq_2_64_poly_clear(K, M1.c10); mpfq_2_64_poly_clear(K, M1.c11);
    mpfq_2_64_poly_clear(K, M2.c00); mpfq_2_64_poly_clear(K, M2.c01);
    mpfq_2_64_poly_clear(K, M2.c10); mpfq_2_64_poly_clear(K, M2.c11);
}

/* *Mpfq::defaults::poly::code_for_poly_xgcd */
void mpfq_2_64_poly_xgcd(mpfq_2_64_dst_field K MAYBE_UNUSED, mpfq_2_64_dst_poly d, mpfq_2_64_dst_poly s, mpfq_2_64_dst_poly t, mpfq_2_64_src_poly a, mpfq_2_64_src_poly b)
{
    if ((mpfq_2_64_poly_deg(K, a) == -1) && (mpfq_2_64_poly_deg(K, b) == -1)) {
        d->size=0;
        t->size=0;
        mpfq_2_64_poly_setcoef_ui(K, s, 1, 0);
        s->size=1;
        return;
    }
    
    mpfq_2_64_poly UU, VV, Q;
    mpfq_2_64_poly_init(K, UU, 0);
    mpfq_2_64_poly_init(K, VV, 0);
    mpfq_2_64_poly_init(K, Q, 0);
    mpfq_2_64_poly_struct *U, *V;
    U = &UU[0]; V = &VV[0];
    
    mpfq_2_64_poly_set(K, U, a);
    mpfq_2_64_poly_set(K, V, b);
    
    long flag = 0;
    
    if (mpfq_2_64_poly_deg(K, U) == mpfq_2_64_poly_deg(K, V)) {
        mpfq_2_64_poly_divmod(K, Q, U, U, V);
        mpfq_2_64_poly_struct *tmp;
        tmp = U; U = V; V = tmp;
        flag = 1;
    } else if (mpfq_2_64_poly_deg(K, U) < mpfq_2_64_poly_deg(K, V)) {
        mpfq_2_64_poly_struct *tmp;
        tmp = U; U = V; V = tmp;
        flag = 2;
    }
    
    mpfq_2_64_polymat M;
    mpfq_2_64_poly_init(K, M.c00, 0);
    mpfq_2_64_poly_init(K, M.c01, 0);
    mpfq_2_64_poly_init(K, M.c10, 0);
    mpfq_2_64_poly_init(K, M.c11, 0);
    
    mpfq_2_64_poly_xHalfGCD(K, &M, U, V, mpfq_2_64_poly_deg(K, U)+1);
    
    mpfq_2_64_poly_set(K, d, U);
    
    if (flag == 0) {
        mpfq_2_64_poly_set(K, s, M.c00);
        mpfq_2_64_poly_set(K, t, M.c01);
    } else if (flag == 1) {
        mpfq_2_64_poly_set(K, s, M.c01);
        mpfq_2_64_poly_mul(K, t, Q, M.c01);
        mpfq_2_64_poly_sub(K, t, M.c00, t);
    } else {
        mpfq_2_64_poly_set(K, s, M.c01);
        mpfq_2_64_poly_set(K, t, M.c00);
    }
    
    mpfq_2_64_elt w;
    mpfq_2_64_init(K, &w);
    mpfq_2_64_poly_getcoef(K, w, d, mpfq_2_64_poly_deg(K, d));
    mpfq_2_64_inv(K, w, w);
    mpfq_2_64_poly_scal_mul(K, d, d, w);
    mpfq_2_64_poly_scal_mul(K, s, s, w);
    mpfq_2_64_poly_scal_mul(K, t, t, w);
    mpfq_2_64_clear(K, &w);
    
    mpfq_2_64_poly_clear(K, M.c00);
    mpfq_2_64_poly_clear(K, M.c01);
    mpfq_2_64_poly_clear(K, M.c10);
    mpfq_2_64_poly_clear(K, M.c11);
    
    mpfq_2_64_poly_clear(K, UU);
    mpfq_2_64_poly_clear(K, VV);
    mpfq_2_64_poly_clear(K, Q);
}


/* vim:set ft=cpp: */
