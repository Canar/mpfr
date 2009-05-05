/* tbuildopt.c -- test file for mpfr_buildopt_tls_p and
   mpfr_buildopt_decimal_p.

Copyright 2009 Free Software Foundation, Inc.
Contributed by the Arenaire and Cacao projects, INRIA.

The GNU MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MPFR Library; see the file COPYING.LIB.  If not, see
http://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA. */

#include <stdlib.h>
#include "mpfr-test.h"

static void
check_tls_p (void)
{
#ifdef MPFR_USE_THREAD_SAFE
  if (!mpfr_buildopt_tls_p())
    {
      printf ("Error: mpfr_buildopt_tls_p should return true\n");
      exit (1);
    }
#else
  if (mpfr_buildopt_tls_p())
    {
      printf ("Error: mpfr_buildopt_tls_p should return false\n");
      exit (1);
    }
#endif
}

static void
check_decimal_p (void)
{
#ifdef MPFR_WANT_DECIMAL_FLOATS
  if (!mpfr_buildopt_decimal_p())
    {
      printf ("Error: mpfr_buildopt_decimal_p should return true\n");
      exit (1);
    }
#else
  if (mpfr_buildopt_decimal_p())
    {
      printf ("Error: mpfr_buildopt_decimal_p should return false\n");
      exit (1);
    }
#endif
}

int
main (void)
{
  check_tls_p();
  check_decimal_p();

  return 0;
}
