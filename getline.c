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
#ifndef _WIN32
#ifndef _MSDOS
#include <sys/param.h>
#endif
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "j_lib2.h"

/*
 * j2_getline() -- rewrote "jmc_get_rec()" from j_lib1.
 *                 Now it is a front end to getline(3) or a hack for
 *                 systems without getline(3)
 */
SSIZE_T j2_getline(char **buf, size_t *n, FILE *fp)
{
#ifdef HAS_GETLINE
  return(getline(buf, n, fp));
#else
  
  if ((*buf) == (char *) NULL)
    {
      (*n) = SIZE_GETLINE_BUF + 1;
      (*buf) = (char *) malloc(((*n) * sizeof(char)));
      if ((*buf) == (char *) NULL)
	return(-1);
      j2_clr_str((*buf), (*n), JLIB2_CHAR_NULL);
    }
    
  if (fgets((*buf), (*n), fp) == (char *) NULL)
    return(-1);
  return((SSIZE_T) strlen((*buf)));
  
#endif
  
} /* j2_getline() */
