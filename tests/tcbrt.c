/* Test file for mpfr_cbrt.

Copyright 2002, 2003, 2004 Free Software Foundation, Inc.

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

#include <stdio.h>
#include <stdlib.h>

#include "mpfr-test.h"

static void
special (void)
{
  mpfr_t x, y;

  mpfr_init (x);
  mpfr_init (y);

  /* cbrt(NaN) = NaN */
  mpfr_set_nan (x);
  mpfr_cbrt (y, x, GMP_RNDN);
  if (!mpfr_nan_p (y))
    {
      printf ("Error: cbrt(NaN) <> NaN\n");
      exit (1);
    }

  /* cbrt(+Inf) = +Inf */
  mpfr_set_inf (x, 1);
  mpfr_cbrt (y, x, GMP_RNDN);
  if (!mpfr_inf_p (y) || mpfr_sgn (y) < 0)
    {
      printf ("Error: cbrt(+Inf) <> +Inf\n");
      exit (1);
    }

  /* cbrt(-Inf) =  -Inf */
  mpfr_set_inf (x, -1);
  mpfr_cbrt (y, x, GMP_RNDN);
  if (!mpfr_inf_p (y) || mpfr_sgn (y) > 0)
    {
      printf ("Error: cbrt(-Inf) <> -Inf\n");
      exit (1);
    }

  /* cbrt(+/-0) =  +/-0 */
  mpfr_set_ui (x, 0, GMP_RNDN);
  mpfr_cbrt (y, x, GMP_RNDN);
  if (mpfr_cmp_ui (y, 0) || mpfr_sgn (y) < 0)
    {
      printf ("Error: cbrt(+0) <> +0\n");
      exit (1);
    }
  mpfr_neg (x, x, GMP_RNDN);
  mpfr_cbrt (y, x, GMP_RNDN);
  if (mpfr_cmp_ui (y, 0) || mpfr_sgn (y) > 0)
    {
      printf ("Error: cbrt(-0) <> -0\n");
      exit (1);
    }

  mpfr_set_prec (x, 53);
  mpfr_set_str (x, "8.39005285514734966412e-01", 10, GMP_RNDN);
  mpfr_cbrt (x, x, GMP_RNDN);
  if (mpfr_cmp_str1 (x, "9.43166207799662426048e-01"))
    {
      printf ("Error in crbrt (1)\n");
      exit (1);
    }

  mpfr_set_prec (x, 32);
  mpfr_set_prec (y, 32);
  mpfr_set_str_binary (x, "0.10000100001100101001001001011001");
  mpfr_cbrt (x, x, GMP_RNDN);
  mpfr_set_str_binary (y, "0.11001101011000100111000111111001");
  if (mpfr_cmp (x, y))
    {
      printf ("Error in cbrt (2)\n");
      exit (1);
    }

  mpfr_set_prec (x, 32);
  mpfr_set_prec (y, 32);
  mpfr_set_str_binary (x, "-0.1100001110110000010101011001011");
  mpfr_cbrt (x, x, GMP_RNDN);
  mpfr_set_str_binary (y, "-0.11101010000100100101000101011001");
  if (mpfr_cmp (x, y))
    {
      printf ("Error in cbrt (3)\n");
      exit (1);
    }

  mpfr_clear (x);
  mpfr_clear (y);
}

int
main (void)
{
  mpfr_t x;
  mp_rnd_t r;
  mp_prec_t p;

  tests_start_mpfr ();

  special ();

  mpfr_init (x);

  for (p=2; p<100; p++)
    {
      mpfr_set_prec (x, p);
      for (r=0; r<4; r++)
        {
          mpfr_set_ui (x, 1, GMP_RNDN);
          mpfr_cbrt (x, x, r);
          if (mpfr_cmp_ui (x, 1))
            {
              printf ("Error in mpfr_cbrt for x=1, rnd=%s\ngot ",
                      mpfr_print_rnd_mode (r));
              mpfr_out_str (stdout, 2, 0, x, GMP_RNDN);
              printf ("\n");
              exit (1);
            }
          mpfr_set_si (x, -1, GMP_RNDN);
          mpfr_cbrt (x, x, r);
          if (mpfr_cmp_si (x, -1))
            {
              printf ("Error in mpfr_cbrt for x=-1, rnd=%s\ngot ",
                      mpfr_print_rnd_mode (r));
              mpfr_out_str (stdout, 2, 0, x, GMP_RNDN);
              printf ("\n");
              exit (1);
            }

          if (p >= 5)
            {
              int i;
              for (i = -12; i <= 12; i++)
                {
                  mpfr_set_ui (x, 27, GMP_RNDN);
                  mpfr_mul_2si (x, x, 3*i, GMP_RNDN);
                  mpfr_cbrt (x, x, GMP_RNDN);
                  if (mpfr_cmp_si_2exp (x, 3, i))
                    {
                      printf ("Error in mpfr_cbrt for "
                              "x = 27.0 * 2^(%d), rnd=%s\ngot ",
                              3*i, mpfr_print_rnd_mode (r));
                      mpfr_out_str (stdout, 2, 0, x, GMP_RNDN);
                      printf ("\ninstead of 3 * 2^(%d)\n", i);
                      exit (1);
                    }
                }
            }
        }
    }

  mpfr_clear (x);

  tests_end_mpfr ();
  return 0;
}
