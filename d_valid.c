/*
 * Copyright (c) 1994 1995 1996 ... 2020 2021
 *     John McCue <jmccue@jmcunx.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef COHERENT
#ifndef _MSDOS
#include <sys/param.h>
#endif
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "j_lib2.h"

#define SIZ_YYYY 5

/*
 * j2_date_is_valid() -- determines if a date is valid
 */
#ifdef COHERENT
int j2_date_is_valid(d)
  struct s_j2_datetime *d;
#else
int j2_date_is_valid(struct s_j2_datetime *d)
#endif
{
  char cyyyy[SIZ_YYYY];
  int test_yy;

  if (d->yyyy < 0)
    return((int) FALSE);
  if (d->yyyy > 9999)
    return((int) FALSE);
  if (d->yy > 99)
    return((int) FALSE);
  if (d->yy < 0)
    return((int) FALSE);
  if (d->month < 1)
    return((int) FALSE);
  if (d->month > 12)
    return((int) FALSE);
  if (d->dd < 1)
    return((int) FALSE);

#ifdef SNPRINTF
  SNPRINTF(cyyyy, SIZ_YYYY, "%d",d->yyyy);
#else
  sprintf(cyyyy, "%d",d->yyyy);
#endif

  if(d->yyyy > 999)
    {
      test_yy = atoi(&(cyyyy[2]));
    }
  else
    {
      if (d->yyyy > 99)
	test_yy = atoi(&(cyyyy[1]));
      else
	test_yy = atoi(cyyyy);
    }
  if (test_yy != d->yy)
    return(FALSE);

  switch (d->month)
    {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        if (d->dd > 31)
          return((int) FALSE);
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        if (d->dd > 30)
          return((int) FALSE);
        break;
      case 2:
	if (j2_d_isleap(d->yyyy))
	  {
	    if (d->dd > 29)
	      return((int) FALSE);
	  }
	else
	  {
	    if (d->dd > 28)
	      return((int) FALSE);
	  }
        break;
      default:
        return((int) FALSE);
    }

  return((int) TRUE);

} /* j2_date_is_valid() */

/*
 * j2_dl_valid() -- determines if a long date is valid
 */
#ifdef COHERENT
int j2_dl_valid(d)
  long d;
#else
int j2_dl_valid(long d)
#endif
{

  struct s_j2_datetime ds;

  if ( ! j2_dl_split(&ds, d, DATE_IN_FMT_NOT) )
    return((int) FALSE);

  return(j2_date_is_valid(&ds));

} /* j2_dl_validl() */

