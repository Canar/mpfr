/* mpfr_print_raw -- print the internal binary representation of a 
                     floating-point number

Copyright (C) 1999 Free Software Foundation.

This file is part of the MPFR Library.

The MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Library General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at your
option) any later version.

The MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
License for more details.

You should have received a copy of the GNU Library General Public License
along with the MPFR Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#include <stdio.h>
#include "gmp.h"
#include "mpfr.h"
#include "gmp-impl.h"

void
#if __STDC__
mpfr_get_str_raw(char *digit_ptr, mpfr_srcptr x)
#else
mpfr_get_str_raw(digit_ptr, x)
     char *digit_ptr; 
     mpfr_srcptr x; 
#endif
{
  mp_limb_t *mx, wd, t; long ex, sx, k, l, p;

  mx = MPFR_MANT(x); 
  ex = MPFR_EXP(x); 
  p = MPFR_PREC(x); 

  /* TODO: utilite de gerer l'infini a ce niveau ? */

  if (MPFR_SIGN(x) < 0) { *digit_ptr = '-'; digit_ptr++; }
  sprintf(digit_ptr, "0."); digit_ptr += 2; 

  sx = 1+(p-1)/BITS_PER_MP_LIMB; /* number of significant limbs */
  for (k = sx - 1; k >= 0 ; k--)
    { 
      wd = mx[k]; 
      t = ((mp_limb_t)1) << (BITS_PER_MP_LIMB - 1); 
      for (l = BITS_PER_MP_LIMB - 1; l>=0; l--)
	{
	  if (wd & t) 
	    { *digit_ptr = '1'; digit_ptr++; } 
	  else 
	    { *digit_ptr = '0'; digit_ptr++; }
	  t >>= 1; 
	  if (--p==0) { *digit_ptr = '['; digit_ptr++; }
	}
    }
  sprintf(digit_ptr, "]E%ld", ex); 
}
 
void
#if __STDC__
mpfr_print_raw(mpfr_srcptr x)
#else
mpfr_print_raw(x)
     mpfr_srcptr x; 
#endif
{
  char *str; 

  if (MPFR_IS_NAN(x)) printf("NaN");
  else if (MPFR_IS_INF(x)) {
    if (MPFR_SIGN(x) == 1) { printf("Inf"); } else printf("-Inf"); 
  }
  else if (!MPFR_NOTZERO(x)) printf("0");
  else {
     /* 3 char for sign + 0 + binary point
	+ MPFR_ABSSIZE(x) * BITS_PER_MP_LIMB for mantissa
	+ 2 for brackets in mantissa
	+ 1 for 'E'
	+ 11 for exponent (including sign)
	= 17 + MPFR_ABSSIZE(x) * BITS_PER_MP_LIMB
      */
     str = (char *) (*_mp_allocate_func) ((17 + MPFR_ABSSIZE(x) * BITS_PER_MP_LIMB)*sizeof(char));
     mpfr_get_str_raw(str, x);

     printf("%s", str); 
     (*_mp_free_func) (str, (17 + MPFR_ABSSIZE(x) * BITS_PER_MP_LIMB)*sizeof(char));
  }
}

