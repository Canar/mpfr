/* Test file for mpfr_sin_cos.

Copyright 2000, 2001, 2002, 2003, 2004, 2006, 2007, 2008, 2009 Free Software Foundation, Inc.
Contributed by the Arenaire and Cacao projects, INRIA.

This file is part of the GNU MPFR Library.

The GNU MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MPFR Library; see the file COPYING.LESSER.  If not, see
http://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA. */

#include <stdio.h>
#include <stdlib.h>

#include "mpfr-test.h"

static void
large_test (char *X, int prec, int N)
{
  int i;
  mpfr_t x, s, c;

  mpfr_init2 (x, prec);
  mpfr_init2 (s, prec);
  mpfr_init2 (c, prec);
  mpfr_set_str (x, X, 10, MPFR_RNDN);

  for (i = 0; i < N; i++)
    mpfr_sin_cos (s, c, x, MPFR_RNDN);

  mpfr_clear (x);
  mpfr_clear (s);
  mpfr_clear (c);
}

static void
check53 (const char *xs, const char *sin_xs, const char *cos_xs,
         mpfr_rnd_t rnd_mode)
{
  mpfr_t xx, s, c;

  mpfr_inits2 (53, xx, s, c, (mpfr_ptr) 0);
  mpfr_set_str1 (xx, xs); /* should be exact */
  mpfr_sin_cos (s, c, xx, rnd_mode);
  if (mpfr_cmp_str1 (s, sin_xs))
    {
      printf ("mpfr_sin_cos failed for x=%s, rnd=%s\n",
              xs, mpfr_print_rnd_mode (rnd_mode));
      printf ("mpfr_sin_cos gives sin(x)=");
      mpfr_out_str(stdout, 10, 0, s, MPFR_RNDN);
      printf(", expected %s\n", sin_xs);
      exit (1);
    }
  if (mpfr_cmp_str1 (c, cos_xs))
    {
      printf ("mpfr_sin_cos failed for x=%s, rnd=%s\n",
              xs, mpfr_print_rnd_mode (rnd_mode));
      printf ("mpfr_sin_cos gives cos(x)=");
      mpfr_out_str(stdout, 10, 0, c, MPFR_RNDN);
      printf(", expected %s\n", cos_xs);
      exit (1);
    }
  mpfr_clears (xx, s, c, (mpfr_ptr) 0);
}

static void
check53sin (const char *xs, const char *sin_xs, mpfr_rnd_t rnd_mode)
{
  mpfr_t xx, s, c;

  mpfr_inits2 (53, xx, s, c, (mpfr_ptr) 0);
  mpfr_set_str1 (xx, xs); /* should be exact */
  mpfr_sin_cos (s, c, xx, rnd_mode);
  if (mpfr_cmp_str1 (s, sin_xs))
    {
      printf ("mpfr_sin_cos failed for x=%s, rnd=%s\n",
              xs, mpfr_print_rnd_mode (rnd_mode));
      printf ("mpfr_sin_cos gives sin(x)=");
      mpfr_out_str(stdout, 10, 0, s, MPFR_RNDN);
      printf(", expected %s\n", sin_xs);
      exit (1);
    }
  mpfr_clears (xx, s, c, (mpfr_ptr) 0);
}

static void
check53cos (const char *xs, const char *cos_xs, mpfr_rnd_t rnd_mode)
{
  mpfr_t xx, c, s;

  mpfr_inits2 (53, xx, s, c, (mpfr_ptr) 0);
  mpfr_set_str1 (xx, xs); /* should be exact */
  mpfr_sin_cos (s, c, xx, rnd_mode);
  if (mpfr_cmp_str1 (c, cos_xs))
    {
      printf ("mpfr_sin_cos failed for x=%s, rnd=%s\n",
              xs, mpfr_print_rnd_mode (rnd_mode));
      printf ("mpfr_sin_cos gives cos(x)=");
      mpfr_out_str(stdout, 10, 0, c, MPFR_RNDN);
      printf(", expected %s\n", cos_xs);
      exit (1);
    }
  mpfr_clears (xx, s, c, (mpfr_ptr) 0);
}

static void
check_nans (void)
{
  mpfr_t  x, s, c;

  mpfr_init2 (x, 123L);
  mpfr_init2 (s, 123L);
  mpfr_init2 (c, 123L);

  /* sin(NaN)==NaN, cos(NaN)==NaN */
  mpfr_set_nan (x);
  mpfr_sin_cos (s, c, x, MPFR_RNDN);
  MPFR_ASSERTN (mpfr_nan_p (s));
  MPFR_ASSERTN (mpfr_nan_p (c));

  /* sin(+Inf)==NaN, cos(+Inf)==NaN */
  mpfr_set_inf (x, 1);
  mpfr_sin_cos (s, c, x, MPFR_RNDN);
  MPFR_ASSERTN (mpfr_nan_p (s));
  MPFR_ASSERTN (mpfr_nan_p (c));

  /* sin(-Inf)==NaN, cos(-Inf)==NaN */
  mpfr_set_inf (x, -1);
  mpfr_sin_cos (s, c, x, MPFR_RNDN);
  MPFR_ASSERTN (mpfr_nan_p (s));
  MPFR_ASSERTN (mpfr_nan_p (c));

  /* check zero */
  mpfr_set_ui  (x, 0, MPFR_RNDN);
  mpfr_sin_cos (s, c, x, MPFR_RNDN);
  MPFR_ASSERTN (mpfr_cmp_ui (s, 0) == 0 && MPFR_IS_POS (s));
  MPFR_ASSERTN (mpfr_cmp_ui (c, 1) == 0);
  mpfr_neg (x, x, MPFR_RNDN);
  mpfr_sin_cos (s, c, x, MPFR_RNDN);
  MPFR_ASSERTN (mpfr_cmp_ui (s, 0) == 0 && MPFR_IS_NEG (s));
  MPFR_ASSERTN (mpfr_cmp_ui (c, 1) == 0);

  /* coverage test */
  mpfr_set_prec (x, 2);
  mpfr_set_ui (x, 4, MPFR_RNDN);
  mpfr_set_prec (s, 2);
  mpfr_set_prec (c, 2);
  mpfr_sin_cos (s, c, x, MPFR_RNDN);
  MPFR_ASSERTN (mpfr_cmp_si_2exp (s, -3, -2) == 0);
  MPFR_ASSERTN (mpfr_cmp_si_2exp (c, -3, -2) == 0);

  mpfr_clear (x);
  mpfr_clear (s);
  mpfr_clear (c);
}

static void
overflowed_sin_cos0 (void)
{
  mpfr_t x, y, z;
  int emax, inex, rnd, err = 0;
  mp_exp_t old_emax;

  old_emax = mpfr_get_emax ();

  mpfr_init2 (x, 8);
  mpfr_init2 (y, 8);
  mpfr_init2 (z, 8);

  for (emax = -1; emax <= 0; emax++)
    {
      mpfr_set_ui_2exp (z, 1, emax, MPFR_RNDN);
      mpfr_nextbelow (z);
      set_emax (emax);  /* 1 is not representable. */
      /* and if emax < 0, 1 - eps is not representable either. */
      RND_LOOP (rnd)
        {
          mpfr_set_si (x, 0, MPFR_RNDN);
          mpfr_neg (x, x, MPFR_RNDN);
          mpfr_clear_flags ();
          inex = mpfr_sin_cos (x, y, x, (mpfr_rnd_t) rnd);
          if (! mpfr_overflow_p ())
            {
              printf ("Error in overflowed_sin_cos0 (rnd = %s):\n"
                      "  The overflow flag is not set.\n",
                      mpfr_print_rnd_mode ((mpfr_rnd_t) rnd));
              err = 1;
            }
          if (! (mpfr_zero_p (x) && MPFR_SIGN (x) < 0))
            {
              printf ("Error in overflowed_sin_cos0 (rnd = %s):\n"
                      "  Got sin = ", mpfr_print_rnd_mode ((mpfr_rnd_t) rnd));
              mpfr_print_binary (x);
              printf (" instead of -0.\n");
              err = 1;
            }
          if (rnd == MPFR_RNDZ || rnd == MPFR_RNDD)
            {
              if (inex == 0)
                {
                  printf ("Error in overflowed_sin_cos0 (rnd = %s):\n"
                          "  The inexact value must be non-zero.\n",
                          mpfr_print_rnd_mode ((mpfr_rnd_t) rnd));
                  err = 1;
                }
              if (! mpfr_equal_p (y, z))
                {
                  printf ("Error in overflowed_sin_cos0 (rnd = %s):\n"
                          "  Got cos = ",
                          mpfr_print_rnd_mode ((mpfr_rnd_t) rnd));
                  mpfr_print_binary (y);
                  printf (" instead of 0.11111111E%d.\n", emax);
                  err = 1;
                }
            }
          else
            {
              if (inex == 0)
                {
                  printf ("Error in overflowed_sin_cos0 (rnd = %s):\n"
                          "  The inexact value must be non-zero.\n",
                          mpfr_print_rnd_mode ((mpfr_rnd_t) rnd));
                  err = 1;
                }
              if (! (mpfr_inf_p (y) && MPFR_SIGN (y) > 0))
                {
                  printf ("Error in overflowed_sin_cos0 (rnd = %s):\n"
                          "  Got cos = ",
                          mpfr_print_rnd_mode ((mpfr_rnd_t) rnd));
                  mpfr_print_binary (y);
                  printf (" instead of +Inf.\n");
                  err = 1;
                }
            }
        }
      set_emax (old_emax);
    }

  if (err)
    exit (1);
  mpfr_clear (x);
  mpfr_clear (y);
  mpfr_clear (z);
}

static void
tiny (void)
{
  mpfr_t x, s, c;
  int i, inex;

  mpfr_inits2 (64, x, s, c, (mpfr_ptr) 0);

  for (i = -1; i <= 1; i += 2)
    {
      mpfr_set_si (x, i, MPFR_RNDN);
      mpfr_set_exp (x, mpfr_get_emin ());
      inex = mpfr_sin_cos (s, c, x, MPFR_RNDN);
      MPFR_ASSERTN (inex != 0);
      MPFR_ASSERTN (mpfr_equal_p (s, x));
      MPFR_ASSERTN (!mpfr_nan_p (c) && mpfr_cmp_ui (c, 1) == 0);
    }

  mpfr_clears (x, s, c, (mpfr_ptr) 0);
}

/* bug found in nightly tests */
static void
test20071214 (void)
{
  mpfr_t a, b;
  int inex;

  mpfr_init2 (a, 4);
  mpfr_init2 (b, 4);

  mpfr_set_ui_2exp (a, 3, -4, MPFR_RNDN);
  inex = mpfr_sin_cos (a, b, a, MPFR_RNDD);
  MPFR_ASSERTN(mpfr_cmp_ui_2exp (a, 11, -6) == 0);
  MPFR_ASSERTN(mpfr_cmp_ui_2exp (b, 15, -4) == 0);
  MPFR_ASSERTN(inex == 10);

  mpfr_set_ui_2exp (a, 3, -4, MPFR_RNDN);
  inex = mpfr_sin_cos (a, b, a, MPFR_RNDU);
  MPFR_ASSERTN(mpfr_cmp_ui_2exp (a, 3, -4) == 0);
  MPFR_ASSERTN(mpfr_cmp_ui (b, 1) == 0);
  MPFR_ASSERTN(inex == 5);

  mpfr_set_ui_2exp (a, 3, -4, MPFR_RNDN);
  inex = mpfr_sin_cos (a, b, a, MPFR_RNDN);
  MPFR_ASSERTN(mpfr_cmp_ui_2exp (a, 3, -4) == 0);
  MPFR_ASSERTN(mpfr_cmp_ui (b, 1) == 0);
  MPFR_ASSERTN(inex == 5);

  mpfr_clear (a);
  mpfr_clear (b);
}

/* check that mpfr_sin_cos and test_mpfr_sincos_fast agree */
static void
test_mpfr_sincos_fast (void)
{
  mpfr_t x, y, z, yref, zref, h;
  mp_prec_t p = 1000;
  int i, inex, inexref;
  mpfr_rnd_t r;

  mpfr_init2 (x, p);
  mpfr_init2 (y, p);
  mpfr_init2 (z, p);
  mpfr_init2 (yref, p);
  mpfr_init2 (zref, p);
  mpfr_init2 (h, p);
  mpfr_set_ui_2exp (h, 1, -3, MPFR_RNDN);
  mpfr_set_ui (x, 0, MPFR_RNDN);
  for (i = 0; i < 100; i++)
    {
      mpfr_urandomb (h, RANDS);
      mpfr_add (x, x, h, MPFR_RNDN);
      r = RND_RAND ();
      inexref = mpfr_sin_cos (yref, zref, x, r);
      inex = mpfr_sincos_fast (y, z, x, r);
      if (mpfr_cmp (y, yref))
        {
          printf ("mpfr_sin_cos and mpfr_sincos_fast disagree\n");
          printf ("x="); mpfr_dump (x);
          printf ("rnd=%s\n", mpfr_print_rnd_mode (r));
          printf ("yref="); mpfr_dump (yref);
          printf ("y="); mpfr_dump (y);
          exit (1);
        }
      if (mpfr_cmp (z, zref))
        {
          printf ("mpfr_sin_cos and mpfr_sincos_fast disagree\n");
          printf ("x="); mpfr_dump (x);
          printf ("rnd=%s\n", mpfr_print_rnd_mode (r));
          printf ("zref="); mpfr_dump (zref);
          printf ("z="); mpfr_dump (z);
          exit (1);
        }
      if (inex != inexref)
        {
          printf ("mpfr_sin_cos and mpfr_sincos_fast disagree\n");
          printf ("x="); mpfr_dump (x);
          printf ("rnd=%s\n", mpfr_print_rnd_mode (r));
          printf ("inexref=%d inex=%d\n", inexref, inex);
          exit (1);
        }
    }
  mpfr_clear (x);
  mpfr_clear (y);
  mpfr_clear (z);
  mpfr_clear (yref);
  mpfr_clear (zref);
  mpfr_clear (h);
}

/* tsin_cos prec [N] performs N tests with prec bits */
int
main (int argc, char *argv[])
{
  tests_start_mpfr ();

  if (argc > 1)
    {
      if (argc != 3 && argc != 4)
        {
          fprintf (stderr, "Usage: tsin_cos x prec [n]\n");
          exit (1);
        }
      large_test (argv[1], atoi (argv[2]), (argc > 3) ? atoi (argv[3]) : 1);
      goto end;
    }

  test_mpfr_sincos_fast ();

  check_nans ();

  /* worst case from PhD thesis of Vincent Lefe`vre: x=8980155785351021/2^54 */
  check53 ("4.984987858808754279e-1", "4.781075595393330379e-1",
           "8.783012931285841817e-1", MPFR_RNDN);
  check53 ("4.984987858808754279e-1", "4.781075595393329824e-1",
           "8.783012931285840707e-1", MPFR_RNDD);
  check53 ("4.984987858808754279e-1", "4.781075595393329824e-1",
           "8.783012931285840707e-1", MPFR_RNDZ);
  check53 ("4.984987858808754279e-1", "4.781075595393330379e-1",
           "8.783012931285841817e-1", MPFR_RNDU);
  check53 ("1.00031274099908640274",  "8.416399183372403892e-1",
           "0.540039116973283217504", MPFR_RNDN);
  check53 ("1.00229256850978698523",  "8.427074524447979442e-1",
           "0.538371757797526551137", MPFR_RNDZ);
  check53 ("1.00288304857059840103",  "8.430252033025980029e-1",
           "0.537874062022526966409", MPFR_RNDZ);
  check53 ("1.00591265847407274059",  "8.446508805292128885e-1",
           "0.53531755997839769456",  MPFR_RNDN);

  /* check one argument only */
  check53sin ("1.00591265847407274059", "8.446508805292128885e-1", MPFR_RNDN);
  check53cos ("1.00591265847407274059", "0.53531755997839769456",  MPFR_RNDN);

  overflowed_sin_cos0 ();
  tiny ();
  test20071214 ();

 end:
  tests_end_mpfr ();
  return 0;
}
