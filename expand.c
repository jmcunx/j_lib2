/*
 * Copyright (c) 2005 2006 2007 ... 2020 2021
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
#include <stdlib.h>

#ifndef __FreeBSD_version
#ifndef OpenBSD
#include <malloc.h>
#endif
#endif

#include "j_lib2.h"

/*
 * j2_expand_tab() -- expand tabs to spaces into a new string
 */
#ifdef COHERENT
int j2_expand_tab(tab_size, out_buf_size, out_buf, in_buf)
  int tab_size;
  size_t *out_buf_size;
  char **out_buf;
  char *in_buf;
#else
int j2_expand_tab(int tab_size, size_t *out_buf_size, char **out_buf, char *in_buf)
#endif

{

  long remd;
  long col, next_col;
  size_t new_size = 0;
  char *wbuf;

  if ((*out_buf) == (char *) NULL)
    (*out_buf_size) = (size_t) 0;

  /*** check for empty in_buf ***/
  if (in_buf == (char *) NULL)
    {
      if ( (*out_buf) != (char *) NULL )
	free(*out_buf);
      (*out_buf)      = (char *) NULL;
      (*out_buf_size) = (size_t) 0;
      return((int) TRUE);
    }

  /*** Verify Tab Size, if invalid replace with space ***/
  if (tab_size < 1)
    tab_size = 8;

  /*** if tab size = 1, do a simple replace and exit ***/
  if (tab_size == 1)
    {
      if ((*out_buf) != (char *) NULL)
	free((*out_buf));
      (*out_buf) = strdup(in_buf);
      j2_chg_char((char) TAB_CHAR, ' ', (*out_buf), 0);
      (*out_buf_size) = strlen((*out_buf));
      return((int) TRUE);
    }

  /*** Need to expand tabs                          ***/
  /*** Do we need more memory ?  if so, allocate it ***/
  new_size = ( strlen(in_buf) * tab_size) + 100;

  if (new_size > (*out_buf_size))
    {
      (*out_buf) = malloc((new_size * sizeof(char)) );
      if ((*out_buf) == (char *) NULL)
	return((int) FALSE);
      (*out_buf_size) = new_size;
    }

  j2_clr_str((*out_buf), JLIB2_CHAR_NULL, new_size);

  /*** Create new string ***/
  wbuf = (*out_buf);
  for ( col = 0; (*in_buf) != JLIB2_CHAR_NULL; in_buf++)
    {
      switch (*in_buf)
	{
	  case TAB_CHAR:
	    remd     = (col + 1) % tab_size;
	    next_col = (col + 1) / tab_size;
	    if (remd > 0L)
	      remd = 1L;
	    next_col = (next_col + remd) * tab_size;
	    for ( ; col < next_col; col++)
	      wbuf[col] = ' ';
	    break;
	  default:
	    wbuf[col] = (*in_buf);
	    col++;
	    wbuf[col] = JLIB2_CHAR_NULL;
	}
    }

  /*** Done ***/
  return((int) TRUE);

} /* END: j2_expand_tab() */

