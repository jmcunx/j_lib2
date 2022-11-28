/*
 * Copyright (c) 2020 2021 2022
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
 *
 */

#ifndef _MSDOS
#include <sys/param.h>
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef _MSDOS
#include <unistd.h>
#endif

#include <fcntl.h>
#include "j_lib2.h"

#ifdef OpenBSD
#define BSD_RAND
#endif
#ifdef __NetBSD_Version__
#define BSD_RAND
#endif
#ifdef __FreeBSD_version
#define BSD_RAND
#endif
#ifdef __DragonFly__
#define BSD_RAND
#endif

/*
 * j2_getseed() -- get a seed value
 */
unsigned int j2_getseed(void)
{
  unsigned int s = (unsigned int) 0;
  int fd, r;

  fd = open(FILE_URANDOM, O_RDONLY);

  if (fd >= 0)
    {
      r = read(fd, &s, sizeof(s));
      close(fd);
      if (r != sizeof(s))
	s = 0U;
    }
  if (s == 0U)
    s = (unsigned int) time(0);

  return(s);

} /* j2_getseed() */

/*
 * j2_randrange() -- returns a random number between a range
 */
unsigned int j2_randrange(unsigned int low, unsigned int max)
{
  unsigned int c = (unsigned int) 0;

#ifdef BSD_RAND
  c = (arc4random() % (max - low + 1)) + low; 
#else
  unsigned int s = (unsigned int) 0;
  s = j2_getseed();
  srand(s);
  c = (rand() % (max - low + 1)) + low; 
#endif

  return(c);

} /* j2_randrange() */
