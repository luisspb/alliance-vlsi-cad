/*
 * This file is part of the Alliance CAD System
 * Copyright (C) Laboratoire LIP6 - Département ASIM
 * Universite Pierre et Marie Curie
 * 
 * Home page          : http://www-asim.lip6.fr/alliance/
 * E-mail support     : mailto:alliance-support@asim.lip6.fr
 * 
 * This progam is  free software; you can redistribute it  and/or modify it
 * under the  terms of the GNU  General Public License as  published by the
 * Free Software Foundation;  either version 2 of the License,  or (at your
 * option) any later version.
 * 
 * Alliance VLSI  CAD System  is distributed  in the hope  that it  will be
 * useful, but WITHOUT  ANY WARRANTY; without even the  implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy  of the GNU General Public License along
 * with the GNU C Library; see the  file COPYING. If not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* Subroutines needed by GCC output code on some machines.  */
/* Compile this file with the Unix C compiler!  */

#include "config.h"

/* Don't use `fancy_abort' here even if config.h says to use it.  */
#ifdef abort
#undef abort
#endif

/* Define the C data type to use for an SImode value.  */

#ifndef SItype
#define SItype long int
#endif

/* Define the type to be used for returning an SF mode value
   and the method for turning a float into that type.
   These definitions work for machines where an SF value is
   returned in the same register as an int.  */

#ifndef SFVALUE  
#define SFVALUE int
#endif

#ifndef INTIFY
#define INTIFY(FLOATVAL)  (intify.f = (FLOATVAL), intify.i)
#endif

#ifdef GNULIB_NEEDS_DOUBLE
#define FLOAT_ARG_TYPE double
#define FLOATIFY(ARG)  ((float) (ARG))
#endif

#ifndef FLOATIFY
#define FLOATIFY(INTVAL)  ((INTVAL).f)
#endif

#ifndef FLOAT_ARG_TYPE
#define FLOAT_ARG_TYPE union flt_or_int
#endif

union flt_or_int { int i; float f; };


#ifdef L_eprintf
#include <stdio.h>
/* This is used by the `assert' macro.  */
void
__eprintf (string, expression, line, filename)
     char *string;
     char *expression;
     int line;
     char *filename;
{
  fprintf (stderr, string, expression, line, filename);
  fflush (stderr);
  abort ();
}
#endif

#ifdef L_umulsi3
SItype
__umulsi3 (a, b)
     unsigned SItype a, b;
{
  return a * b;
}
#endif

#ifdef L_mulsi3
SItype
__mulsi3 (a, b)
     SItype a, b;
{
  return a * b;
}
#endif

#ifdef L_udivsi3
SItype
__udivsi3 (a, b)
     unsigned SItype a, b;
{
  return a / b;
}
#endif

#ifdef L_divsi3
SItype
__divsi3 (a, b)
     SItype a, b;
{
  return a / b;
}
#endif

#ifdef L_umodsi3
SItype
__umodsi3 (a, b)
     unsigned SItype a, b;
{
  return a % b;
}
#endif

#ifdef L_modsi3
SItype
__modsi3 (a, b)
     SItype a, b;
{
  return a % b;
}
#endif

#ifdef L_lshrsi3
SItype
__lshrsi3 (a, b)
     unsigned SItype a, b;
{
  return a >> b;
}
#endif

#ifdef L_lshlsi3
SItype
__lshlsi3 (a, b)
     unsigned SItype a, b;
{
  return a << b;
}
#endif

#ifdef L_ashrsi3
SItype
__ashrsi3 (a, b)
     SItype a, b;
{
  return a >> b;
}
#endif

#ifdef L_ashlsi3
SItype
__ashlsi3 (a, b)
     SItype a, b;
{
  return a << b;
}
#endif

#ifdef L_divdf3
double
__divdf3 (a, b)
     double a, b;
{
  return a / b;
}
#endif

#ifdef L_muldf3
double
__muldf3 (a, b)
     double a, b;
{
  return a * b;
}
#endif

#ifdef L_negdf2
double
__negdf2 (a)
     double a;
{
  return -a;
}
#endif

#ifdef L_adddf3
double
__adddf3 (a, b)
     double a, b;
{
  return a + b;
}
#endif

#ifdef L_subdf3
double
__subdf3 (a, b)
     double a, b;
{
  return a - b;
}
#endif

#ifdef L_cmpdf2
SItype
__cmpdf2 (a, b)
     double a, b;
{
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  return 0;
}
#endif

#ifdef L_fixunsdfsi
#define HIGH_BIT_INT_COEFF  (1 << (BITS_PER_WORD - 1))
#define HIGH_BIT_COEFF  (2 * (double) (1 << (BITS_PER_WORD - 2)))

SItype
__fixunsdfsi (a)
     double a;
{
  if (a < HIGH_BIT_COEFF)
    return (SItype)a;
  /* Convert large positive numbers to smaller ones,
     then increase again after you have a fixed point number.  */
  else
    return ((SItype) (a - HIGH_BIT_COEFF)) + HIGH_BIT_INT_COEFF;
}
#endif

#ifdef L_fixdfsi
SItype
__fixdfsi (a)
     double a;
{
  return (SItype) a;
}
#endif

#ifdef L_floatsidf
double
__floatsidf (a)
     SItype a;
{
  return (double) a;
}
#endif

#ifdef L_addsf3
SFVALUE
__addsf3 (a, b)
     FLOAT_ARG_TYPE a, b;
{
  union flt_or_int intify;
  return INTIFY (FLOATIFY (a) + FLOATIFY (b));
}
#endif

#ifdef L_negsf2
SFVALUE
__negsf2 (a)
     FLOAT_ARG_TYPE a;
{
  union flt_or_int intify;
  return INTIFY (-FLOATIFY (a));
}
#endif

#ifdef L_subsf3
SFVALUE
__subsf3 (a, b)
     FLOAT_ARG_TYPE a, b;
{
  union flt_or_int intify;
  return INTIFY (FLOATIFY (a) - FLOATIFY (b));
}
#endif

#ifdef L_cmpsf2
SItype
__cmpsf2 (a, b)
     FLOAT_ARG_TYPE a, b;
{
  if (FLOATIFY (a) > FLOATIFY (b))
    return 1;
  else if (FLOATIFY (a) < FLOATIFY (b))
    return -1;
  return 0;
}
#endif

#ifdef L_mulsf3
SFVALUE
__mulsf3 (a, b)
     FLOAT_ARG_TYPE a, b;
{
  union flt_or_int intify;
  return INTIFY (FLOATIFY (a) * FLOATIFY (b));
}
#endif

#ifdef L_divsf3
SFVALUE
__divsf3 (a, b)
     FLOAT_ARG_TYPE a, b;
{
  union flt_or_int intify;
  
  return INTIFY (FLOATIFY (a) / FLOATIFY (b));
}
#endif

#ifdef L_truncdfsf2
SFVALUE
__truncdfsf2 (a)
     double a;
{
  union flt_or_int intify;
  return INTIFY (a);
}
#endif

#ifdef L_extendsfdf2
double
__extendsfdf2 (a)
     FLOAT_ARG_TYPE a;
{
  return FLOATIFY (a);
}
#endif

#ifdef L_bb
int __avoid_ranlib_warning;  /* Don't let symbol table be empty.  */

#if defined (sun) && defined (mc68000)
struct bb
{
  int initialized;
  char *filename;
  int *counts;
  int ncounts;
  int zero_word;
  int *addresses;
};

__bb_init_func (blocks)
	struct bb *blocks;
{
  extern int ___tcov_init;

  if (! ___tcov_init)
    ___tcov_init_func ();

  ___bb_link (blocks->filename, blocks->counts, blocks->ncounts);
}

#endif
#endif

/* frills for C++ */

#ifdef L_builtin_new
typedef void (*vfp)();

extern vfp __new_handler;

char *
__builtin_new (sz)
     long sz;
{
  char *p;

  p = (char *)malloc (sz);
  if (p == 0)
    (*__new_handler) ();
  return p;
}
#endif

#ifdef L_builtin_New
typedef void (*vfp)();

static void
default_new_handler ();

vfp __new_handler = default_new_handler;

char *
__builtin_vec_new (p, maxindex, size, ctor)
     char *p;
     int maxindex, size;
     void (*ctor)();
{
  int i, nelts = maxindex + 1;
  char *rval;

  if (p == 0)
    p = (char *)__builtin_new (nelts * size);

  rval = p;

  for (i = 0; i < nelts; i++)
    {
      (*ctor) (p);
      p += size;
    }

  return rval;
}

vfp
__set_new_handler (handler)
     vfp handler;
{
  vfp prev_handler;

  prev_handler = __new_handler;
  if (handler == 0) handler = default_new_handler;
  __new_handler = handler;
  return prev_handler;
}

vfp
set_new_handler (handler)
     vfp handler;
{
  return __set_new_handler (handler);
}

static void
default_new_handler ()
{
  /* don't use fprintf (stderr, ...) because it may need to call malloc.  */
  write (2, "default_new_handler: out of memory... aaaiiiiiieeeeeeeeeeeeee!\n", 65);
  /* don't call exit () because that may call global destructors which
     may cause a loop.  */
  _exit (-1);
}
#endif

#ifdef L_builtin_del
typedef void (*vfp)();

void
__builtin_delete (ptr)
     char *ptr;
{
  if (ptr)
    free (ptr);
}

void
__builtin_vec_delete (ptr, maxindex, size, dtor, auto_delete_vec, auto_delete)
     char *ptr;
     int maxindex, size;
     void (*dtor)();
     int auto_delete;
{
  int i, nelts = maxindex + 1;
  char *p = ptr;

  ptr += nelts * size;

  for (i = 0; i < nelts; i++)
    {
      ptr -= size;
      (*dtor) (ptr, auto_delete);
    }

  if (auto_delete_vec)
    free (p);
}

#endif
