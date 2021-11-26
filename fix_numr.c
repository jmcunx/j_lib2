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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "j_lib2.h"

/*
 * j2_fix_numr() -- make sure the string is numeric and if so move the
 *                  trailing minus to the beginning of the string
 *                  removing the thousand character
 */
int j2_fix_numr(char *buffer, char thousand, char decimal_point)

{
  char *b = (char *) NULL;
  char *w = (char *) NULL;
  unsigned int u;
  int cd         = 0;
  int ct         = 0;
  int count_neg  = 0;
  int rc = TRUE;

  if (buffer == (char *) NULL)
    return(FALSE);
  switch(strlen(buffer))
    {
      case 0:
        return(FALSE);
      case 1:
	u = (unsigned int) (*b);
	if ( (u > (unsigned int) 57) || ((unsigned int) u < 48) )
	  {
	    rc = FALSE;
	    goto leave_j2_fix_numr;
	  }
        break;
    }

  w = strdup(buffer);
  if (w == (char *) NULL)
    return(FALSE);

  j2_rtw(w);
  j2_justleft(w);

  for (cd = 0, ct = 0, count_neg = 0, b=w; (*b) != JLIB2_CHAR_NULL; b++)
    {
      if (isspace((*b)) == TRUE)
      	{
      	  rc = FALSE;
      	  goto leave_j2_fix_numr;
      	}
      if ((*b) == thousand)
        {
          ct++;
          continue;
        }
      if ((*b) ==  '-')
        {
          count_neg++;
          continue;
        }
      if ((*b) == decimal_point)
        {
          cd++;
          continue;
        }
      u = (unsigned int) (*b);
      if ( (u > (unsigned int) 57) || ((unsigned int) u < 48) )
      	{
      	  rc = FALSE;
      	  goto leave_j2_fix_numr;
      	}
    }

  if (count_neg > 1)  /* more than 1 negative sign  */
    {
      rc = FALSE;
      goto leave_j2_fix_numr;
    }
  if (cd > 1)  /* more than 1 decimal points */
    {
      rc = FALSE;
      goto leave_j2_fix_numr;
    }

  /* remove thousand characters */
  if (ct > 0)
    {
      b = strdup(w);
      cd = strlen(w);
      memset(w, JLIB2_CHAR_NULL, (unsigned int) cd);
      if (w == (char *) NULL)
      	{
      	  rc = FALSE;
      	  goto leave_j2_fix_numr;
      	}
      for (cd = 0, ct = 0; b[cd] != JLIB2_CHAR_NULL; cd++)
        {
          if (b[cd] == thousand)
            continue;
          w[ct] = b[cd];
          ct++;
        }
      free(b);
      b = (char *) NULL;
    }

  if (count_neg < 1)
    goto leave_j2_fix_numr;
  if ((*w) == '-')
    {
      count_neg = 0;  /* neg sign at the correct place */
      goto leave_j2_fix_numr;
    }

leave_j2_fix_numr:
  if (rc == TRUE)
    {
      cd = strlen(buffer);
      memset(buffer, JLIB2_CHAR_NULL, (unsigned int) cd);
      if (count_neg < 1)
	strcpy(buffer, w);
      else
        {
          cd = strlen(w) - 1;
          w[cd] = JLIB2_CHAR_NULL;
          buffer[0] = '-';
          strcpy(&(buffer[1]), w);
        }
    }
  if (w != (char *) NULL)
    free(w);
  return(rc);

} /* j2_fix_numr() */
