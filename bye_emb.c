/*
 * Copyright (c) 2014 2015 2016 ... 2020 2021
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

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "j_lib2.h"

/*
 * remove embedded spaces from a string
 */
#ifdef COHERENT
long int j2_bye_emb(s)
  char *s;
#else
long int j2_bye_emb(char *s)
#endif
{
  char *n = (char *) NULL;
  int cfound = (int) FALSE;
  size_t len, i, j;

  if (s == (char *) NULL)
    return(-1L);

  len = strlen(s);
  if (len <  3)
    return(strlen(s));

  /* allocate space for new string */
  n = calloc((len + 2), sizeof(char));
  if (n == (char *) NULL)
    return(-1L);

  (*n) = (*s);
  for (i = 1, j = 1; s[i] != JLIB2_CHAR_NULL; i++)
    {
      if (cfound == (int) FALSE)
	{
	  if (! isspace(s[i]) )
	    cfound = (int) TRUE;
	  n[j] = s[i];
	  j++;
	  continue;
	}
      if ( isspace(s[i]) && isspace(s[(i - 1)]) )
	continue;
      n[j] = s[i];
      j++;
    }

  /* DONE, replace original string */
#ifdef OpenBSD
  strlcpy(s, n, len);
#else
  strcpy(s, n);
#endif

  free(n);

  return((long int) strlen(s));

}

