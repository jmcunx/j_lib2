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
#include <stdlib.h>
#include <string.h>

#include "j_lib2.h"

/*
 * j2_bye_char() -- removes all occurances of a specific a char from a string
 */
int j2_bye_char(char *buffer, char c)

{
  char *temp_str;
  int i, j, num_c = 0;
  int found = (int) FALSE;
#ifdef OpenBSD
  size_t len;
#endif
  
  if (c == JLIB2_CHAR_NULL)
    return(0);
  
  i = strlen(buffer) + 2;
  temp_str = calloc(i, sizeof(char));
  if (temp_str == (char *) NULL)
    return(-1);
  
  for ( i=0, j=0; buffer[i] != JLIB2_CHAR_NULL; i++)
    {
      if (buffer[i] == c)
	{
	  ++num_c;
	  found = (int) TRUE;
	}
      else
	{
	  temp_str[j] = buffer[i];
	  ++j;
	}
    }

  if (found == (int) FALSE)
    {
      free(temp_str);
      return(num_c);
    }

  /* note: size of buffer will never increase and   */
  /*       we removed at least 1 embedded character */
#ifdef OpenBSD
  len = strlen(temp_str) + 1;
  strlcpy(buffer, temp_str, len);
#else
  strcpy(buffer, temp_str);
#endif

  free(temp_str);
  return(num_c);

}
