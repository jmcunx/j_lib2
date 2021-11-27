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
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "j_lib2.h"

/*
 * j2_file_typ() -- Determines File Type
 */
int j2_file_typ(char *file_name)

{

  struct stat file_stat;
  int file_type;

  if (stat(file_name, &file_stat))
    return(J2_CANT_GET);

  file_type = (int) (file_stat.st_mode & S_IFMT);

  switch (file_type)
    {
      case (int) S_IFREG:
	file_type = J2_REGULAR;
	break;
      case (int) S_IFDIR:
	      file_type = J2_DIRECTORY;
	      break;
#ifdef S_IFCHR
      case (int) S_IFCHR:
	      file_type = J2_CHAR_SPECIAL;
	      break;
#endif
#ifdef S_IFBLK
      case (int) S_IFBLK:
	      file_type = J2_BLOCK_SPECIAL;
	      break;
#endif
#ifdef S_IFLNK
      case (int) S_IFLNK:
	      file_type = J2_SYMB_LINK;
	      break;
#endif
#ifdef S_IFPIP
      case (int) S_IFPIP:
	      file_type = J2_PIPE;
	      break;
#endif
#ifdef S_IFSOCK
#if S_IFSOCK != S_IFPIP
      case (int) S_IFSOCK:
	      file_type = J2_SOCKET;
	      break;
#endif
#endif
#ifdef S_IFIFO
#if S_IFIFO != S_IFPIP
      case (int) S_IFIFO:
	      file_type = J2_FIFO;
	      break;
#endif
#endif
      default:
	      file_type = J2_UNKNOWN;
    }

  return(file_type);

}
