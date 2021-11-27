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
#include "j_lib2.h"

#define SIZ_YYYY 5
#define SIZ_YY   3

/*
 * j2_ds_date_time() -- break to date/time portion
 */
void j2_ds_date_time(char **date_part, char **time_part, char *date_time)
{
  char *all, *t;
  int i, sp;

  if (date_time == (char *) NULL)
    return;
  if (strlen(date_time) < 1)
    return;

  all = strdup(date_time);
  t = (char *) NULL;
  j2_rtw(all);
  j2_justleft(all);

  for (i = 0, sp = -1; all[i] != JLIB2_CHAR_NULL; i++)
    {
      if (all[i] == ' ')
	{
	  sp = i;
	  break;
	}
    }

  /*** load time data ***/
  if (sp > 0)
    {
      t = &(all[sp + 1]);
      j2_rtw(t);
      j2_justleft(t);
      (*time_part) = strdup(t);
      all[sp] = JLIB2_CHAR_NULL;
    }
  else
    {
      switch (strlen(all))
	{
	  case 12:  /* YYMMDDhhmmss        */
	    (*time_part) = strdup(&(all[6]));
	    all[6] = JLIB2_CHAR_NULL;
	    break;
	  case 14:  /* YYYYMMDDhhmmss      */
	    (*time_part) = strdup(&(all[8]));
	    all[8] = JLIB2_CHAR_NULL;
	    break;
	  case 15:  /* YYMMDDhhmmsslll     */
	    (*time_part) = strdup(&(all[6]));
	    all[6] = JLIB2_CHAR_NULL;
	    break;
	  case 17:  /* YYYYMMDDhhmmsslll   */
	    (*time_part) = strdup(&(all[8]));
	    all[8] = JLIB2_CHAR_NULL;
	    break;
	  default:
	    /* leave (*time_part) as null */
	    break;
	}
    }

  /*** load date part ***/
  (*date_part) = strdup(all);

  /*** done ***/
  free(all);

} /* j2_ds_date_time() */

/*
 * j2_time_split() -- splits a time string into a structure
 *                    can adjust for PM
 */
int j2_time_split(struct s_j2_datetime *d, char *t_string)
{
  char hh[3], mm[3], ss[3], ml[4];
  double sec;
  int i, colon_found, ssize, c1, c2;
  int rstat = (int) TRUE;
  char *pmm = (char *) NULL;
  char *pss = (char *) NULL;
  char *t   = (char *) NULL;

  if (t_string == (char *) NULL)
    return((int) TRUE); /* this is OK */

  j2_clr_str(hh, JLIB2_CHAR_NULL, 3);
  j2_clr_str(mm, JLIB2_CHAR_NULL, 3);
  j2_clr_str(ss, JLIB2_CHAR_NULL, 3);
  j2_clr_str(ml, JLIB2_CHAR_NULL, 4);

  /* allocate work string, initial checks */
  t      = strdup(t_string);
  ssize  = strlen(t);
  j2_rtw(t);
  j2_justleft(t);
  if (ssize == 0)
    {
      free(t);
      return((int) TRUE); /* this is OK */
    }

  colon_found = j2_count_c(TIME_SEPERATOR, t);

  /* we have a time string, try and split */
  if (colon_found == 0)
    {
      switch (ssize)
	{
	  case 9: /* hhmmsslll */
	    ml[0]      = t[6];
	    ml[1]      = t[7];
	    ml[2]      = t[8];
	    /* fall through to 6 */
	  case 6: /* hhmmss    */
	    ss[0]      = t[4];
	    ss[1]      = t[5];
	    /* fall through to 4 */
	  case 4: /* hhmm      */
	    hh[0] = t[0];
	    hh[1] = t[1];
	    mm[0] = t[2];
	    mm[1] = t[3];
	    if (j2_is_numr(hh) && j2_is_numr(mm) && j2_is_numr(ss))
	      {
		d->hh      = atoi(hh);
		d->minutes = atoi(mm);
		d->ss      = atoi(ss);
		d->mil     = atoi(ml);
	      }
	    break;
	  default:
	    if (ssize > 6)
	      {
		hh[0]      = t[0];
		hh[1]      = t[1];
		mm[0]      = t[2];
		mm[1]      = t[3];
		sec        = atof(&(t[4]));
		if (j2_is_numr(hh) && j2_is_numr(mm))
		  { /* seconds have PM/AM attached, so best of luck */
		    d->hh      = atoi(hh);
		    d->minutes = atoi(mm);
		    d->ss      = sec;
		    d->mil     = (sec * 1000) - (d->ss * 1000); /* avoids rounding */
		  }
	      }
	    break;
	}
    }
  else
    {
      c1 = 0;
      c2 = 0;
      for (i = 0; t[i] != JLIB2_CHAR_NULL; i++)
	{
	  if (t[i] == TIME_SEPERATOR)
	    {
	      if (c1 == 0)
		c1 = i;
	      else
		c2 = i;
	    }
	}
      if (c1 == 0)
	rstat = (int) FALSE;
      else
	{
	  pmm = &(t[(c1 + 1)]);
	  t[c1] = JLIB2_CHAR_NULL;
	  if (c2 != 0)
	    {
	      pss = &(t[(c2 + 1)]);
	      t[c2] = JLIB2_CHAR_NULL;
	    }
	  d->hh      = atoi(t);
	  d->minutes = atoi(pmm);
	  if (c2 != 0)
	    {
	      sec        = atof(pss);
	      d->ss      = sec;
	      d->mil     = (sec * 1000) - (d->ss * 1000); /* avoids rounding */
	    }
	}
    }

  if ((d->hh > 24) || (d->minutes > 59) || (d->ss > 59))
    rstat = (int) FALSE;
  else
    {
      if ( (d->hh == 24) && ((d->minutes > 0) || (d->ss > 0)) )
	rstat = (int) FALSE;
    }

  if (d->hh < 13)
    {
      if (strstr(t_string, "PM") == (char *) NULL)
	{
	  if (strstr(t_string, "pm") != (char *) NULL)
	    d->hh += 12;
	}
      else
	d->hh += 12;
    }

  free(t);
  return(rstat);

} /* j2_time_split() */

/*
 * j2_date_split_fmt() -- splits date based on a delimiter
 */
int j2_date_split_fmt(struct s_j2_datetime *d, char *dstr, char *delim, int date_type)
{
  char yy[SIZ_YY];
  char *f1 = (char *) NULL;
  char *f2 = (char *) NULL;
  char *f3 = (char *) NULL;
  char *f4 = (char *) NULL;
  char fmt_yyyy[SIZ_YYYY];

  j2_clr_str(yy, JLIB2_CHAR_NULL, 3);

  /* split on delim */
  f1 = strtok(dstr, delim);
  if (f1 != (char *) NULL)
    {
      f2 = strtok((char *) NULL, delim);
      if (f2 != (char *) NULL)
	{
	  f3 = strtok((char *) NULL, delim);
	  if (f3 != (char *) NULL)
	    f4 = strtok((char *) NULL, delim);
	}
    }

  /* make sure we at least seem OK */
  if (f4 != (char *) NULL)
    return((int) FALSE);
  if (f3 == (char *) NULL)
    return((int) FALSE);
  if (f2 == (char *) NULL)
    return((int) FALSE);
  if (f1 == (char *) NULL)
    return((int) FALSE);
  if ( ! j2_is_numr(f1) )
    return((int) FALSE);
  if ( ! j2_is_numr(f2) )
    return((int) FALSE);
  if ( ! j2_is_numr(f2) )
    return((int) FALSE);

  /* seems fine, continue on */
  if (strlen(f1) == 4) /* must be YYYY-MM-DD */
    {
      yy[0]    = f1[2];
      yy[1]    = f1[3];
      d->yyyy  = atoi(f1);
      d->month = atoi(f2);
      d->dd    = atoi(f3);
      d->yy    = atoi(yy);
      return((int) TRUE);
    }

  /* some other format, so we need date_type */
  switch (date_type)
    {
      case DATE_IN_FMT_J:  /* YY/MM/DD or YYYY/MM/DD */
	d->dd    = atoi(f3);
	d->month = atoi(f2);
	if (strlen(f1) == 2)
	  d->yy   = atoi(f1);
	else
	  d->yyyy = atoi(f1);
	break;
	break;
      case DATE_IN_FMT_E:  /* DD/MM/YY or DD/MM/YYYY */
	d->month = atoi(f2);
	d->dd    = atoi(f1);
	if (strlen(f3) == 2)
	  d->yy   = atoi(f3);
	else
	  d->yyyy = atoi(f3);
	break;
      default:             /* default to MM/DD/YY or MM/DD/YYYY */
	d->month = atoi(f1);
	d->dd    = atoi(f2);
	if (strlen(f3) == 2)
	  d->yy   = atoi(f3);
	else
	  d->yyyy = atoi(f3);
	break;
    }

  /* format other year item */
  if (d->yy == 0)
    {
      if ((d->yyyy < 10000) && (d->yyyy > -1))
	{
	  SNPRINTF(fmt_yyyy, SIZ_YYYY, "%04d", d->yyyy);
	  d->yy = atoi((&(fmt_yyyy[2])));
	}
      else
	d->yy = d->yyyy % 1000;
    }
  else
    {
      if (d->yyyy == 0)
	d->yyyy   = j2_d_get_yyyy(d->yy);
    }

  /* done */
  return((int) TRUE);

} /* j2_date_split_fmt() */

/*
 * j2_date_split() -- splits a date string into a structure
 */
int j2_date_split(struct s_j2_datetime *d, char *d_string, int fmt)
{

  char mm[3], dd[3], yy[3], yyyy[5];
  int i, ssize;
  int rstat = (int) TRUE;
  char delim[2];
  char *dstr = (char *) NULL;

  if (d_string == (char *) NULL)
    return((int) FALSE);
  j2_clr_str(mm,    JLIB2_CHAR_NULL, 3);
  j2_clr_str(dd,    JLIB2_CHAR_NULL, 3);
  j2_clr_str(yy,    JLIB2_CHAR_NULL, 3);
  j2_clr_str(yyyy,  JLIB2_CHAR_NULL, 5);
  j2_clr_str(delim, JLIB2_CHAR_NULL, 2);
  dstr = strdup(d_string);
  j2_rtw(dstr);
  j2_justleft(dstr);

  ssize = strlen(dstr);
  if (ssize < 1)
    {
      if (dstr != (char *) NULL)
	free(dstr);
      return((int) FALSE);
    }

  /* find delimiter (if any) */
  i = j2_count_c(DATE_SEPERATOR, dstr);
  if (i > 0)
    delim[0] = DATE_SEPERATOR;
  else
    {
      i = j2_count_c('-', dstr);
      if (i > 0)
	delim[0] = '-';
    }

  /* process if no delimiter is found */
  if (delim[0] == JLIB2_CHAR_NULL)
    {
      if (j2_is_numr(dstr))
	{
	  switch (ssize)
	    {
	      case 6: /* YYMMDD */
		yy[0] = dstr[0];
		yy[1] = dstr[1];
		mm[0] = dstr[2];
		mm[1] = dstr[3];
		dd[0] = dstr[4];
		dd[1] = dstr[5];
		d->month  = atoi(mm);
		d->dd     = atoi(dd);
		d->yy     = atoi(yy);
		d->yyyy   = j2_d_get_yyyy(d->yy);
		break;
	      case 8: /* YYYYMMDD */
		yyyy[0]   = dstr[0];
		yyyy[1]   = dstr[1];
		yyyy[2]   = dstr[2];
		yyyy[3]   = dstr[3];
		yy[0]     = dstr[2];
		yy[1]     = dstr[3];
		mm[0]     = dstr[4];
		mm[1]     = dstr[5];
		dd[0]     = dstr[6];
		dd[1]     = dstr[7];
		d->month  = atoi(mm);
		d->dd     = atoi(dd);
		d->yy     = atoi(yy);
		d->yyyy   = atoi(yyyy);
		break;
	      default:
		rstat = (int) FALSE;
	    }
	}
      else
	rstat = (int) FALSE;
    }
  else
    rstat = j2_date_split_fmt(d, dstr, delim, fmt);
 
  /* done */
  if (dstr != (char *) NULL)
    free(dstr);
  return(rstat);

} /* j2_date_split() */

/*
 * j2_ds_split() -- split a date/time string
 */
int j2_ds_split(struct s_j2_datetime *d, char *date_time, int fmt)
{

  char *datestr = (char *) NULL;
  char *timestr = (char *) NULL;
  int rstat = (int) TRUE;

  j2_d_init(d);

  if (date_time == ((char *) NULL))
    return((int) FALSE);

  /* split date/time on space */
  j2_ds_date_time(&datestr, &timestr, date_time);
  if (datestr == (char *) NULL)
    rstat = (int) FALSE;

  /* load date/time data */
  if (rstat == (int) TRUE)
    rstat = j2_time_split(d, timestr);
  if (rstat == (int) TRUE)
    rstat = j2_date_split(d, datestr, fmt);

  /*** DONE ***/
  if (j2_date_is_valid(d) == (int) FALSE)
    {
      j2_d_init(d);
      rstat = (int) FALSE;
    }

  if (datestr != (char *) NULL)
    free(datestr);
  if (timestr != (char *) NULL)
    free(timestr);
  return(rstat);

} /* j2_ds_split() */

/*
 * j2_dl_split() -- splits a "long" date time into its components,
 */
int j2_dl_split(struct s_j2_datetime *d, long date_num, int fmt)
{
  char date_time[DATE_TIME_SIZE_STR];

  SNPRINTF(date_time, DATE_TIME_SIZE_STR, "%ld", date_num);

  return(j2_ds_split(d, date_time, fmt));

} /* j2_dl_split() */
