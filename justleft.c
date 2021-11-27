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

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "j_lib2.h"

/*
 * j2_justleft() -- left justifies a string (removes beginning white
 *                  space) returns -1 on failure, strlen on success
 */
long int j2_justleft(char *s)

{
  char *temp_s;
  int i;
#ifdef OpenBSD
  size_t len;
#endif
  
  if (s == (char *) NULL)
    return(0L); /* NULL pointer, pretend 0 */

  if (strlen(s) < 2)
    {
      if (isspace((*s)))
	{
	  (*s) = JLIB2_CHAR_NULL;
	  return(0L);
	}
      else
	return((long int) strlen(s));
    }
  
#ifdef OpenBSD
  len = strlen(s) + 1;
  temp_s = strndup(s, len);
#else
  temp_s = strdup(s);
#endif

  if ( temp_s == (char *) NULL )
    return(-1L); /* not enough memory */
  
  for (i=0; temp_s[i] != JLIB2_CHAR_NULL; i++)
    {
      if (! isspace((int) temp_s[i]) )
	break;
    }
 
#ifdef OpenBSD
  strlcpy(s,&(temp_s[i]),len);
#else
  strcpy(s,&(temp_s[i]));
#endif

  free(temp_s);
  
  return((long int) strlen(s));

}
