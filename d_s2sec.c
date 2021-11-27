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
 * j2_str_to_secs()
 *    converts a time string formatted as DDD HH:MM:SS to seconds (assumes 
 *    DDD can be greater that 3 digits).  strtok() not used because this 
 *    string could be used (created) via strtok().  MUST assume there is 
 *    *one* space seperating Days from Time
 */
long int j2_str_to_secs(char *buffer)
{
  char *day_part = (char *) NULL;
  char *time_part = (char *) NULL;
  time_t secs = (time_t) 0;

  day_part = strdup(buffer);
  if (day_part == (char *) NULL)
    return(secs);

  for (secs=0; day_part[secs] != JLIB2_CHAR_NULL; secs++)
    {
      if (day_part[secs] == ' ')
        {
          day_part[secs] = JLIB2_CHAR_NULL;
          ++secs;
          time_part = &(day_part[secs]);
          break;
        }
    }

  if (time_part != (char *) NULL)
    {
      time_part[2] = JLIB2_CHAR_NULL;
      time_part[5] = JLIB2_CHAR_NULL;
      secs = atol(day_part) * 86400L;
      secs += (atol(time_part) * 3600L);
      secs += (atol(&(time_part[3])) * 60L);
      secs += (atol(&(time_part[6])));
    }

  free(day_part);
  return((long int) secs);

}
