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

#include <stdio.h>
#include <ctype.h>

#include "j_lib2.h"

/*
 * j2_is_space_emdedded() -- checks to see if a string has embedded white 
 *                           space.  leading spaces is considered embedded 
 *                           spaces
 */
#ifdef COHERENT
int j2_is_space_embedded(s)
  char *s;
#else
int j2_is_space_embedded(char *s)
#endif
{
  unsigned int i; 

  if (s == (char *) NULL)
    return((int) FALSE); /* NULL pointer */

  for (i = 0; (*s) != JLIB2_CHAR_NULL; s++, i++)
    {
      if ( ! isspace((*s)) )
	{
	  if (i > 0)
	    return((int) TRUE); /* leading spaces */
          break;
	}
    }

  for ( ; (*s) != JLIB2_CHAR_NULL; s++)
    {
      if ( isspace((*s)) )
          break;
    }

  for ( ; (*s) != JLIB2_CHAR_NULL; s++)
    {
      if ( ! isspace((*s)) )
	return((int) TRUE); /* embedded spaces */
    }

  return((int) FALSE);

} /* end: j2_is_space_embedded() */
