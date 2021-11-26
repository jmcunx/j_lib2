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

#ifndef COHERENT
#ifndef _MSDOS
#include <sys/param.h>
#endif
#endif

#include <string.h>
#include "j_lib2.h"

/*
 * j2_d_isleap() -- Leap Year, True or False
 */
#ifdef COHERENT
int j2_d_isleap(year_yyyy)
  int year_yyyy;
#else
int j2_d_isleap(int year_yyyy)
#endif
{

  if ((year_yyyy % 4) == 0)
    {
      if (((year_yyyy % 100) == 0) && ((year_yyyy % 400) != 0))
	return(FALSE);
      else
	return(TRUE);
    }

  return(FALSE);

}

