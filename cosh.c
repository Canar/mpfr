/* mpfr_cosh -- hyperbolic cosine

Copyright 2001, 2002, 2004 Free Software Foundation.

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
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#include "gmp.h"
#include "gmp-impl.h"
#include "mpfr.h"
#include "mpfr-impl.h"

 /* The computation of cosh is done by

    cosh= 1/2[e^(x)+e^(-x)]
 */

int
mpfr_cosh (mpfr_ptr y, mpfr_srcptr xt , mp_rnd_t rnd_mode)
{

  /****** Declaration ******/
    mpfr_t x;
    mp_prec_t Nxt = MPFR_PREC(xt);
    int inexact =0;

    if (MPFR_UNLIKELY(MPFR_IS_SINGULAR(xt)))
      {
	if (MPFR_IS_NAN(xt))
	  {
	    MPFR_SET_NAN(y);
	    MPFR_RET_NAN;
	  }
	else if (MPFR_IS_INF(xt))
	  {
	    MPFR_SET_INF(y);
	    MPFR_SET_POS(y);
	    MPFR_RET(0);
	  }
	else if (MPFR_IS_ZERO(xt))
	  return mpfr_set_ui(y, 1, rnd_mode); /* cosh(0) = 1 */
	/* Should never reach this code */
	else
	  MPFR_ASSERTN(0);
      }

    mpfr_init2(x,Nxt);
    mpfr_abs(x, xt, GMP_RNDN);

    /* General case */
    {
    /* Declaration of the intermediary variable */
      mpfr_t t, te,ti;

      /* Declaration of the size variable */
      mp_prec_t Nx = Nxt;   /* Precision of input variable */
      mp_prec_t Ny = MPFR_PREC(y);   /* Precision of input variable */

      mp_prec_t Nt;   /* Precision of the intermediary variable */
      long int err;  /* Precision of error */

      /* compute the precision of intermediary variable */
      Nt = MAX(Nx, Ny);
      /* the optimal number of bits : see algorithms.ps */
      Nt = Nt + 3 + __gmpfr_ceil_log2 (Nt);


      /* initialise of intermediary	variable */
      mpfr_init (t);
      mpfr_init (te);
      mpfr_init (ti);

      /* First computation of cosh */
      do
        {

          /* reactualisation of the precision */

          mpfr_set_prec (t, Nt);
          mpfr_set_prec (te, Nt);
          mpfr_set_prec (ti, Nt);

          /* compute cosh */
          mpfr_exp (te, x, GMP_RNDD);         /* exp(x) */
          mpfr_ui_div (ti, 1, te, GMP_RNDU);   /* 1/exp(x) */
          mpfr_add (t, te, ti, GMP_RNDN);      /* exp(x) + 1/exp(x)*/
          mpfr_div_2ui (t, t, 1, GMP_RNDN);    /* 1/2(exp(x) + 1/exp(x))*/

          /* estimation of the error */
          err = Nt - 3;

          /* actualisation of the precision */
          Nt += 10;

        }
      while ((err < 0) || !mpfr_can_round (t, err, GMP_RNDN, GMP_RNDZ,
                                           Ny + (rnd_mode == GMP_RNDN)));

      inexact = mpfr_set (y, t, rnd_mode);

      mpfr_clear (t);
      mpfr_clear (ti);
      mpfr_clear (te);
    }

    mpfr_clear (x);

    return inexact;
}
