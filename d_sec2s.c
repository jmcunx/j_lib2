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

#ifndef _MSDOS
#include <sys/param.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

#include "j_lib2.h"

/*
 * j2_secs_to_str() 
 *    converts seconds into a time string formatted as DDD HH:MM:SS, 
 *    note if DDD turns out to be greater than 999 it will be replaced 
 *    by '***'
 */
void j2_secs_to_str(char *buffer, long int secs, size_t smax)

{
  time_t ddd, hh, mm, ss;

  ddd = (secs / ( (time_t) 86400) );
  ss  = (secs % ( (time_t) 86400) );
  hh  = (ss  / ( (time_t) 3600) );
  ss  = (ss  % ( (time_t) 3600) );
  mm  = (ss  / ( (time_t) 60) );
  ss  = (ss  % ( (time_t) 60) );

  if (ddd > ( (time_t) 999) )
    SNPRINTF(buffer, smax, "*** %02lu%c%02lu%c%02lu",
            (unsigned long) hh,TIME_SEPERATOR,
            (unsigned long) mm,TIME_SEPERATOR,
            (unsigned long) ss);
  else
    SNPRINTF(buffer, smax, "%03lu %02lu%c%02lu%c%02lu",
            (unsigned long) ddd,
            (unsigned long) hh,TIME_SEPERATOR,
            (unsigned long) mm,TIME_SEPERATOR,
            (unsigned long) ss);

}

