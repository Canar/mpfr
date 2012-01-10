/* mpfr_sgn -- Sign of a floating point number.

Copyright 2003, 2004, 2006, 2007, 2008, 2009, 2010, 2011, 2012 Free Software Foundation, Inc.
Contributed by the Arenaire and Caramel projects, INRIA.

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

#include "mpfr-impl.h"

int
(mpfr_sgn) (mpfr_srcptr a)
{
  if (MPFR_UNLIKELY (MPFR_IS_SINGULAR (a)))
    {
      if (MPFR_LIKELY (MPFR_IS_ZERO (a)))
        return 0;
      if (MPFR_UNLIKELY (MPFR_IS_NAN (a)))
        {
          MPFR_SET_ERANGE ();
          return 0;
        }
      /* Remains infinity, handled by the return below. */
    }
  return MPFR_INT_SIGN (a);
}
