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
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "j_lib2.h"

/*
 * j2_bye_last() -- When the last byte = x, replaces it with NULL 
 *                  and returns string length
 */
long int j2_bye_last(char *x, char lastc)

{
  int i;
  
  if ( x == (char *) NULL )
    return(0L);
  if (strlen(x) < 1)
    return(0L);
  
  i = strlen(x) - (size_t) 1;
  
  if (x[i] == lastc)
    x[i] = JLIB2_CHAR_NULL;
  
  return((long int) strlen(x));
  
}
