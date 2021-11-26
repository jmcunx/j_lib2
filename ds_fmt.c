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
#include "j_lib2.h"

/*
 * j2_ds_fmt() -- converts a String Date to one of these formats:
 *                        type            to String
 *                        --------------- -----------
 *                        DATE_FMT_US_2   MM/DD/YY
 *                        DATE_FMT_US_4   MM/DD/YYYY
 *                        DATE_FMT_YYYY   YYYY/MM/DD
 *                        DATE_FMT_YY     YY/MM/DD
 *                        DATE_FMT_EU_2   DD/MM/YY
 *                        DATE_FMT_EU_4   DD/MM/YYYY
 *                        DATE_STR_YY     YYMMDD
 *                        DATE_STR_YYYY   YYYYMMDD
 *                the in date can be almost any format, will return
 *                FALSE if the date does not look valid.
 *                In type is used to determine if US or European
 */
#ifdef COHERENT
int j2_ds_fmt(date_format, date_s, out_type, fmt)
  char *date_format;
  char *date_s;
  int out_type;
  int fmt;
#else
int j2_ds_fmt(char *date_format, char *date_s, int out_type, int fmt)
#endif
{
  struct s_j2_datetime d;

  if ( ! j2_ds_split(&d, date_s, fmt) )
    {
      date_format[0] = JLIB2_CHAR_NULL;
      return((int) FALSE);
    }
  
  switch (out_type)
    {
    case DATE_FMT_US_2: /* MM/DD/YY */
#ifdef SNPRINTF
      SNPRINTF(date_format, 9, "%02d%c%02d%c%02d",
	      d.month,DATE_SEPERATOR,d.dd,DATE_SEPERATOR,d.yy);
#else
      sprintf(date_format, "%02d%c%02d%c%02d",
	      d.month,DATE_SEPERATOR,d.dd,DATE_SEPERATOR,d.yy);
#endif
      break;
    case DATE_FMT_US_4: /* MM/DD/YYYY */
#ifdef SNPRINTF
      SNPRINTF(date_format, 11, "%02d%c%02d%c%04d",
	      d.month,DATE_SEPERATOR,d.dd,DATE_SEPERATOR,d.yyyy);
#else
      sprintf(date_format, "%02d%c%02d%c%04d",
	      d.month,DATE_SEPERATOR,d.dd,DATE_SEPERATOR,d.yyyy);
#endif
      break;
    case DATE_FMT_YYYY:  /* YYYY/MM/DD */
#ifdef SNPRINTF
      SNPRINTF(date_format, 11, "%04d%c%02d%c%02d",
	      d.yyyy,DATE_SEPERATOR,d.month,DATE_SEPERATOR,d.dd);
#else
      sprintf(date_format, "%04d%c%02d%c%02d",
	      d.yyyy,DATE_SEPERATOR,d.month,DATE_SEPERATOR,d.dd);
#endif
      break;
    case DATE_FMT_YY: /* YY/MM/DD */
#ifdef SNPRINTF
      SNPRINTF(date_format, 9, "%02d%c%02d%c%02d",
	      d.yy,DATE_SEPERATOR,d.month,DATE_SEPERATOR,d.dd);
#else
      sprintf(date_format, "%02d%c%02d%c%02d",
	      d.yy,DATE_SEPERATOR,d.month,DATE_SEPERATOR,d.dd);
#endif
      break;
    case DATE_FMT_EU_2:  /* DD/MM/YY */
#ifdef SNPRINTF
      SNPRINTF(date_format, 9, "%02d%c%02d%c%02d",
	      d.dd,DATE_SEPERATOR,d.month,DATE_SEPERATOR,d.yy);
#else
      sprintf(date_format, "%02d%c%02d%c%02d",
	      d.dd,DATE_SEPERATOR,d.month,DATE_SEPERATOR,d.yy);
#endif
      break;
    case DATE_FMT_EU_4: /* DD/MM/YYYY */
#ifdef SNPRINTF
      SNPRINTF(date_format, 11, "%02d%c%02d%c%04d",
	      d.dd,DATE_SEPERATOR,d.month,DATE_SEPERATOR,d.yyyy);
#else
      sprintf(date_format, "%02d%c%02d%c%04d",
	      d.dd,DATE_SEPERATOR,d.month,DATE_SEPERATOR,d.yyyy);
#endif
      break;
    case DATE_STR_YY  :  /* YYMMDD */
#ifdef SNPRINTF
      SNPRINTF(date_format, 7, "%02d%02d%02d", d.yy,d.month,d.dd);
#else
      sprintf(date_format, "%02d%02d%02d", d.yy,d.month,d.dd);
#endif
      break;
    case DATE_STR_YYYY: /* YYYYMMDD */
#ifdef SNPRINTF
      SNPRINTF(date_format, 9, "%04d%02d%02d", d.yyyy,d.month,d.dd);
#else
      sprintf(date_format, "%04d%02d%02d", d.yyyy,d.month,d.dd);
#endif
      break;
    default:
      date_format[0] = JLIB2_CHAR_NULL;
      return((int) FALSE);
    }

  return((int) TRUE);

} /* j2_ds_fmt() */

/*
 * j2_dl_fmt() -- converts a Long Date to a string then calls j2_dl_fmt()
 */
#ifdef COHERENT
int j2_dl_fmt(date_format, date_l, out_type)
  char *date_format;
  long date_l;
  int out_type;
#else
int j2_dl_fmt(char *date_format, long date_l, int out_type)
#endif
{
  char ds[50];

  memset(ds, JLIB2_CHAR_NULL, 50);
#ifdef SNPRINTF
  SNPRINTF(ds, 49, "%ld",date_l);
#else
  sprintf(ds, "%ld",date_l);
#endif

  return( j2_ds_fmt(date_format, ds, out_type, DATE_IN_FMT_NOT) );

} /* dl_fmt() */

