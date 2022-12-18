/*
 * Copyright (c) 1994 1995 1996 ... 2021 2022
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

#ifndef _MSDOS
#include <sys/param.h>
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
#ifdef linux
#include <sys/time.h>
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
void j2_today(struct s_j2_datetime *dt)

{

  struct tm     *str_tm;
  
#ifdef BSD_TODAY
  struct timeval tp;
  struct timezone tzp;
#else
#ifdef linux
  struct timeval tp;
  struct timezone tzp;
#else
  struct timeb  time_buf;
#endif
#endif

#ifdef BSD_TODAY
  gettimeofday(&tp, &tzp);
  str_tm = localtime(&(tp.tv_sec));
#else
#ifdef linux
  gettimeofday(&tp, &tzp);
  str_tm = localtime(&(tp.tv_sec));
#else
  ftime(&time_buf);
  str_tm = localtime(&(time_buf.time));
#endif
#endif
  
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
  dt->mil      = (int) (tp.tv_usec / 1000);
#else
#ifdef linux
  dt->mil      = (int) (tp.tv_usec / 1000);
#else
  dt->mil      = time_buf.millitm;
#endif
#endif

}
