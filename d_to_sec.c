/*
 * Copyright (c) 1999 2001 2002 ... 2021 2022
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

/*
 * d_to_sec.c -- Converts a date/time to # of seconds since
 *               Jan 1, 1970
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include "j_lib2.h"

/*
 * j2_count_years()
 */
time_t j2_count_years(int year)

{
  int i, days = 0;

  for (days=0, i = 1971; i <= year; i++)
    {
      if (j2_d_isleap(i - 1))
        days += 366;
      else
        days += 365;
    }

  return((time_t) days * SECS_DAY);
  
} /* j2_count_years() */

/*
 * j2_count_days()
 */
time_t j2_count_days(int year, int month, int day)

{
  time_t sec = (time_t) 0;
  int d = 0;
  int i;

  for (d = 0, i = 1; i < month; i++)
    {
      switch (i)
        {
          case 2:
            if (j2_d_isleap(year))
              d += 29;
            else
              d += 28;
            break;
          case 4:
          case 6:
          case 9:
          case 11:
            d += 30;
            break;
          default:
            d += 31;
            break;
        }
    }


  d += day - 1;

  sec += ((time_t) SECS_DAY * (time_t) d);

  return(sec);
  
} /* j2_count_days() */

/*
 * j2_d_to_sec() -- converts date/time to seconds since Jan 1, 1970
 */
long int j2_d_to_sec(struct s_j2_datetime *d)

{
  time_t secs_since;

  if (d->yyyy < 1970)
    return((time_t) -1);
  if (d->yyyy > LIMIT_TO_SEC_YY)
    return((time_t) -1);
  if (d->yyyy == LIMIT_TO_SEC_YY)
    {
      if (d->month != LIMIT_TO_SEC_MM)
        return((time_t) -1);
      if (d->dd > LIMIT_TO_SEC_DD)
        return((time_t) -1);
    }

  secs_since = j2_count_years(d->yyyy);
  secs_since += j2_count_days(d->yyyy, d->month, d->dd);

  if (d->hh > 0)
    secs_since += ((time_t) d->hh * (time_t) 3600);

  if (d->minutes > 0)
    secs_since += ((time_t) d->minutes * (time_t) 60);

  if (d->ss > 0)
    secs_since += (time_t) d->ss;

  return((long int) secs_since);

} /* cnv_secs() */

