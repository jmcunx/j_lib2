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
#include <sys/types.h>

#ifndef OpenBSD
#include <sys/timeb.h>
#endif
#include <time.h>

#ifdef __FreeBSD_version
#include <sys/time.h>
#define BSD_TODAY 1
#endif

#ifdef OpenBSD
#include <sys/time.h>
#define BSD_TODAY 1
#endif

#ifdef __NetBSD_Version__
#include <sys/time.h>
#define BSD_TODAY 1
#endif

#include "j_lib2.h"

#define SFMT 15

/*
 * j2_today() -- get todays date
 */
#ifdef COHERENT
char *j2_today(dt)
  struct s_j2_datetime *dt;
#else
char *j2_today(struct s_j2_datetime *dt)
#endif

{

  static char fmt[SFMT];
  struct tm     *str_tm;

#ifdef BSD_TODAY
  struct timeval tp;
  struct timezone tzp;
#else
  struct timeb  time_buf;
#endif

#ifdef BSD_TODAY
  gettimeofday(&tp, &tzp);
  str_tm = localtime(&(tp.tv_sec));
#else
  ftime(&time_buf);
  str_tm = localtime(&(time_buf.time));
#endif

  j2_clr_str(fmt, JLIB2_CHAR_NULL, 15);
  
  (str_tm->tm_mon)++;
  
  dt->yyyy     = str_tm->tm_year + 1900;
  dt->month    = str_tm->tm_mon;
  dt->dd       = str_tm->tm_mday;
  dt->yy       = str_tm->tm_year;
  dt->hh       = str_tm->tm_hour;
  dt->minutes  = str_tm->tm_min;
  dt->ss       = str_tm->tm_sec;
  dt->tm_isdst = str_tm->tm_isdst;

#ifdef BSD_TODAY
  dt->mil      = (int) 0;
#else
  dt->mil      = time_buf.millitm;
#endif

  if ((dt->yyyy    < 10000) &&
      (dt->month   < 100)   &&
      (dt->dd      < 100)   &&
      (dt->hh      < 100)   &&
      (dt->minutes < 100)   &&
      (dt->ss      < 100))  /* prevent overflow */
    {
#ifdef SNPRINTF
      SNPRINTF(fmt,SFMT,"%04d%02d%02d%02d%02d%02d",
	      dt->yyyy, dt->month,   dt->dd, 
	      dt->hh,   dt->minutes, dt->ss);
#else
      sprintf(fmt,"%04d%02d%02d%02d%02d%02d",
	      dt->yyyy, dt->month,   dt->dd, 
	      dt->hh,   dt->minutes, dt->ss);
#endif
    }
  
  return(fmt);

}
