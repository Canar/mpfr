/* mpfr_exp -- exponential of a floating-point number

Copyright 1999, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

This file is part of the MPFR Library.

The MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the MPFR Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 51 Franklin Place, Fifth Floor, Boston,
MA 02110-1301, USA. */

#include <limits.h> /* for CHAR_BIT */

#define MPFR_NEED_LONGLONG_H /* for MPFR_MPZ_SIZEINBASE2 */
#include "mpfr-impl.h"

/* y <- exp(p/2^r) within 1 ulp, using 2^m terms from the series
   Assume |p/2^r| < 1.
   We use the following binary splitting formula:
   P(a,b) = p if a+1=b, P(a,c)*P(c,b) otherwise
   Q(a,b) = a*2^r if a+1=b [except Q(0,1)=1], Q(a,c)*Q(c,b) otherwise
   T(a,b) = P(a,b) if a+1=b, Q(c,b)*T(a,c)+P(a,c)*T(c,b) otherwise
   Then exp(p/2^r) ~ T(0,i)/Q(0,i) for i so that (p/2^r)^i/i! is small enough.

   Since P(a,b) = p^(b-a), and we consider only values of b-a of the form 2^j,
   we don't need to compute P(), we only precompute p^(2^j) in the ptoj[] array
   below.

   Since Q(a,b) is divisible by 2^(r*(b-a-1)), we don't compute the power of
   two part.
*/
static void
mpfr_exp_rational (mpfr_ptr y, mpz_ptr p, long r, int m,
                   mpz_t *Q, mp_prec_t *mult)
{
  unsigned long n, i, j;
  mpz_t *S, *ptoj;
  mp_prec_t *log2_nb_terms;
  mp_exp_t diff, expo;
  mp_prec_t precy = MPFR_PREC(y), prec_i_have, accu, prec_ptoj;
  int k, l;

  MPFR_ASSERTN ((size_t) m < sizeof (long) * CHAR_BIT - 1);

  S    = Q + (m+1);
  ptoj = Q + 2*(m+1);                     /* ptoj[i] = mantissa^(2^i) */
  log2_nb_terms = mult + (m+1);

  /* Normalize p */
  MPFR_ASSERTD (mpz_cmp_ui (p, 0) != 0);
  n = mpz_scan1 (p, 0); /* number of trailing zeros in p */
  mpz_tdiv_q_2exp (p, p, n);
  r -= n; /* since |p/2^r| < 1 and p >= 1, r >= 1 */

  /* Set initial var */
  mpz_set (ptoj[0], p);
  for (k = 1; k < m; k++)
    mpz_mul (ptoj[k], ptoj[k-1], ptoj[k-1]); /* ptoj[k] = p^(2^k) */
  mpz_set_ui (Q[0], 1);
  mpz_set_ui (S[0], 1);
  k = 0;
  mult[0] = 0; /* the multiplier P[k]/Q[k] for the remaining terms
		  satisfies P[k]/Q[k] <= 2^(-mult[k]) */
  log2_nb_terms[0] = 0; /* log2(#terms) [exact in 1st loop where 2^k] */
  prec_i_have = 0;

  /* Main Loop */
  n = 1UL << m;
  for (i = 1; (prec_i_have < precy) && (i < n); i++)
    {
      /* invariant: Q[0]*Q[1]*...*Q[k] equals i! */
      k++;
      log2_nb_terms[k] = 0; /* 1 term */
      mpz_set_ui (Q[k], i + 1);
      mpz_set_ui (S[k], i + 1);
      j = i + 1; /* we have computed j = i+1 terms so far */
      l = 0;
      while ((j & 1) == 0) /* combine and reduce */
        {
	  /* invariant: S[k] corresponds to 2^l consecutive terms */
          mpz_mul (S[k], S[k], ptoj[l]);
          mpz_mul (S[k-1], S[k-1], Q[k]);
	  /* Q[k] corresponds to 2^l consecutive terms too.
	     Since it does not contains the factor 2^(r*2^l),
	     when going from l to l+1 we need to multiply
	     by 2^(r*2^(l+1))/2^(r*2^l) = 2^(r*2^l) */
          mpz_mul_2exp (S[k-1], S[k-1], r << l);
          mpz_add (S[k-1], S[k-1], S[k]);
          mpz_mul (Q[k-1], Q[k-1], Q[k]);
          log2_nb_terms[k-1] ++; /* number of terms in S[k-1]
				    is a power of 2 by construction */
          MPFR_MPZ_SIZEINBASE2 (prec_i_have, Q[k]);
	  MPFR_MPZ_SIZEINBASE2 (prec_ptoj, ptoj[l]);
	  mult[k-1] += prec_i_have + (r << l) - prec_ptoj - 1;
	  prec_i_have = mult[k] = mult[k-1];
          /* since mult[k] >= mult[k-1] + nbits(Q[k]),
             we have Q[0]*...*Q[k] <= 2^mult[k] = 2^prec_i_have */
          l ++;
          j >>= 1;
          k --;
        }
    }

  /* accumulate all products in S[0] and Q[0]. Warning: contrary to above,
     here we do not have log2_nb_terms[k-1] = log2_nb_terms[k]+1. */
  l = 0;
  accu = 0;
  while (k > 0)
    {
      j = log2_nb_terms[k-1];
      mpz_mul (S[k], S[k], ptoj[j]);
      mpz_mul (S[k-1], S[k-1], Q[k]);
      accu += 1 << log2_nb_terms[k];
      mpz_mul_2exp (S[k-1], S[k-1], r * accu);
      mpz_add (S[k-1], S[k-1], S[k]);
      mpz_mul (Q[k-1], Q[k-1], Q[k]);
      l++;
      k--;
    }

  /* Q[0] now equals i! */
  MPFR_MPZ_SIZEINBASE2 (prec_i_have, S[0]);
  diff = (mp_exp_t) prec_i_have - 2 * (mp_exp_t) precy;
  expo = diff;
  if (diff >= 0)
    mpz_div_2exp (S[0], S[0], diff);
  else
    mpz_mul_2exp (S[0], S[0], -diff);

  MPFR_MPZ_SIZEINBASE2 (prec_i_have, Q[0]);
  diff = (mp_exp_t) prec_i_have - (mp_prec_t) precy;
  expo -= diff;
  if (diff > 0)
    mpz_div_2exp (Q[0], Q[0], diff);
  else
    mpz_mul_2exp (Q[0], Q[0], -diff);

  mpz_tdiv_q (S[0], S[0], Q[0]);
  mpfr_set_z (y, S[0], GMP_RNDD);
  MPFR_SET_EXP (y, MPFR_GET_EXP (y) + expo - r * (i - 1) );
}

#define shift (BITS_PER_MP_LIMB/2)

int
mpfr_exp_3 (mpfr_ptr y, mpfr_srcptr x, mp_rnd_t rnd_mode)
{
  mpfr_t t, x_copy, tmp;
  mpz_t uk;
  mp_exp_t ttt, shift_x;
  unsigned long twopoweri;
  mpz_t *P;
  mp_prec_t *mult;
  int i, k, loop;
  int prec_x;
  mp_prec_t realprec, Prec;
  int iter;
  int inexact = 0;
  MPFR_ZIV_DECL (ziv_loop);

  /* decompose x */
  /* we first write x = 1.xxxxxxxxxxxxx
     ----- k bits -- */
  prec_x = MPFR_INT_CEIL_LOG2 (MPFR_PREC (x)) - MPFR_LOG2_BITS_PER_MP_LIMB;
  if (prec_x < 0)
    prec_x = 0;

  ttt = MPFR_GET_EXP (x);
  mpfr_init2 (x_copy, MPFR_PREC(x));
  mpfr_set (x_copy, x, GMP_RNDD);

  /* we shift to get a number less than 1 */
  if (ttt > 0)
    {
      shift_x = ttt;
      mpfr_div_2ui (x_copy, x, ttt, GMP_RNDN);
      ttt = MPFR_GET_EXP (x_copy);
    }
  else
    shift_x = 0;
  MPFR_ASSERTD (ttt <= 0);

  /* Init prec and vars */
  realprec = MPFR_PREC (y) + MPFR_INT_CEIL_LOG2 (prec_x + MPFR_PREC (y));
  Prec = realprec + shift + 2 + shift_x;
  mpfr_init2 (t, Prec);
  mpfr_init2 (tmp, Prec);
  mpz_init (uk);

  /* Main loop */
  MPFR_ZIV_INIT (ziv_loop, realprec);
  for (;;)
    {
      k = MPFR_INT_CEIL_LOG2 (Prec) - MPFR_LOG2_BITS_PER_MP_LIMB;

      /* now we have to extract */
      twopoweri = BITS_PER_MP_LIMB;

      /* Allocate tables */
      P    = (mpz_t*) (*__gmp_allocate_func) (3*(k+2)*sizeof(mpz_t));
      for (i = 0; i < 3*(k+2); i++)
        mpz_init (P[i]);
      mult = (mp_prec_t*) (*__gmp_allocate_func) (2*(k+2)*sizeof(mp_prec_t));

      /* Particular case for i==0 */
      mpfr_extract (uk, x_copy, 0);
      MPFR_ASSERTD (mpz_cmp_ui (uk, 0) != 0);
      mpfr_exp_rational (tmp, uk, shift + twopoweri - ttt, k + 1, P, mult);
      for (loop = 0; loop < shift; loop++)
        mpfr_sqr (tmp, tmp, GMP_RNDD);
      twopoweri *= 2;

      /* General case */
      iter = (k <= prec_x) ? k : prec_x;
      for (i = 1; i <= iter; i++)
        {
          mpfr_extract (uk, x_copy, i);
          if (MPFR_LIKELY (mpz_cmp_ui (uk, 0) != 0))
            {
              mpfr_exp_rational (t, uk, twopoweri - ttt, k  - i + 1, P, mult);
              mpfr_mul (tmp, tmp, t, GMP_RNDD);
            }
          MPFR_ASSERTN (twopoweri <= LONG_MAX/2);
          twopoweri *=2;
        }

      /* Clear tables */
      for (i = 0; i < 3*(k+2); i++)
        mpz_clear (P[i]);
      (*__gmp_free_func) (P, 3*(k+2)*sizeof(mpz_t));
      (*__gmp_free_func) (mult, 2*(k+2)*sizeof(mp_prec_t));

      mpfr_clear_flags ();
      for (loop = 0; loop < shift_x; loop++)
        mpfr_mul (tmp, tmp, tmp, GMP_RNDD);

      if (MPFR_UNLIKELY (mpfr_overflow_p ()))
        {
          /* We hack to set a FP number outside the valid range so that
             mpfr_check_range properly generates an overflow */
          mpfr_setmax (y, __gmpfr_emax);
          MPFR_EXP (y) ++;
          inexact = 1;
          break;
        }
      else if (MPFR_UNLIKELY (mpfr_underflow_p ()))
        {
          /* We hack to set a FP number outside the valid range so that
             mpfr_check_range properly generates an underflow.
             Note that the range has been increased to allow a safe
             detection of underflow (MPFR_EMIN_MIN-3 in exp.c) even for
             RNDN */
          mpfr_setmax (y, MPFR_EMIN_MIN-2);
          inexact = -1;
          break;
        }
      else if (mpfr_can_round (tmp, realprec, GMP_RNDD, GMP_RNDZ,
                               MPFR_PREC(y) + (rnd_mode == GMP_RNDN)))
        {
          inexact = mpfr_set (y, tmp, rnd_mode);
          break;
        }
      MPFR_ZIV_NEXT (ziv_loop, realprec);
      Prec = realprec + shift + 2 + shift_x;
      mpfr_set_prec (t, Prec);
      mpfr_set_prec (tmp, Prec);
    }
  MPFR_ZIV_FREE (ziv_loop);

  mpz_clear (uk);
  mpfr_clear (tmp);
  mpfr_clear (t);
  mpfr_clear (x_copy);
  return inexact;
}
