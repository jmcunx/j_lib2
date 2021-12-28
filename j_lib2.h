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

/*
* j_lib2 Header
*/
#ifndef J_LIB2_H

#define J_LIB2_H "INCLUDED"

#define JLIB2_DIR_SEP '/'
#define JLIB2_INT_NULL   ((int) '\0')
#define JLIB2_CHAR_NULL  ((char) '\0')
#define JLIB2_UCHAR_NULL ((unsigned char) '\0' )
#ifndef NULL
#define NULL '\0'
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TAB_CHAR
#define TAB_CHAR 0x09
#endif

#ifdef _MSDOS
#define SNPRINTF _snprintf
#define SSIZE_T unsigned long int
#endif

#ifndef SNPRINTF
#define SNPRINTF snprintf
#endif
#ifndef SSIZE_T
#define SSIZE_T ssize_t
#endif

#ifndef FILE_URANDOM
#define FILE_URANDOM "/dev/urandom"
#endif
#ifndef FILE_RANDOM
#define FILE_RANDOM  "/dev/random"
#endif

/*** second/date conversions ***/
#define SECS_DAY  86400L /* Seconds per day */

#ifdef _MSDOS
#define LIMIT_TO_SEC_YY 9999
#define LIMIT_TO_SEC_MM 12
#define LIMIT_TO_SEC_DD 31
#define SIZE_GETLINE_BUF 256
#endif
#ifdef _AIX
#define LIMIT_TO_SEC_YY 9999
#define LIMIT_TO_SEC_MM 12
#define LIMIT_TO_SEC_DD 31
#define HAS_GETLINE 1
#endif
#ifdef __NetBSD_Version__
#define LIMIT_TO_SEC_YY 9999
#define LIMIT_TO_SEC_MM 12
#define LIMIT_TO_SEC_DD 31
#define HAS_GETLINE 1
#endif
#ifdef OpenBSD
#define LIMIT_TO_SEC_YY 9999
#define LIMIT_TO_SEC_MM 12
#define LIMIT_TO_SEC_DD 31
#define HAS_GETLINE 1
#endif
#ifdef linux  /* linux now 64 bit time_t */
#define LIMIT_TO_SEC_YY 9999
#define LIMIT_TO_SEC_MM 12
#define LIMIT_TO_SEC_DD 31
#define HAS_GETLINE 1
#endif

#ifndef LIMIT_TO_SEC_YY
#define LIMIT_TO_SEC_YY 2038
#define LIMIT_TO_SEC_MM 1
#define LIMIT_TO_SEC_DD 18
#endif

/*** values returned by file_type() ***/
#define J2_CANT_GET      0
#define J2_UNKNOWN       1
#define J2_DIRECTORY     2  /* S_IFDIR  */
#define J2_REGULAR       3  /* S_IFREG  */
#define J2_CHAR_SPECIAL  4  /* S_IFCHR  */
#define J2_BLOCK_SPECIAL 5  /* S_IFBLK  */
#define J2_PIPE          6  /* S_IFPIP  */
#define J2_SOCKET        7  /* S_IFSOCK */
#define J2_SYMB_LINK     8  /* S_IFLNK  */
#define J2_FIFO          9  /* S_IFIFO  */

/*** date/time area ***/
#define DATE_TIME_SIZE_STR  18  /* for YYYYMMDDHHmmSSLLL */
#define CENTURY_CURRENT     19
#define CENTURY_NEXT        20
#define CUTOFF_YY           90  /* if less than this year use CENTURY_21 */

/* Format Types used by d_type() */
#define DATE_SIZE_MAX  27    /* largest size of a date string              */
#define DATE_IN_FMT_E   1    /* in date format DD/MM/YY or DD/MM/YYYY      */
#define DATE_IN_FMT_U   2    /* in date format MM/DD/YY or MM/DD/YYYY      */
#define DATE_IN_FMT_J   3    /* in date format YY/MM/DD or YYYY/MM/DD      */
#define DATE_IN_FMT_NOT 4    /* in date not formatted, YYYYMMDD YYMMDD ... */

/*** date format defines ***/
#define DATE_FMT_US_2     1     /*  string MM/DD/YY               */
#define DATE_FMT_US_4     2     /*  string MM/DD/YYYY             */
#define DATE_FMT_YYYY     3     /*  string YYYY/MM/DD             */
#define DATE_FMT_YY       4     /*  string YY/MM/DD               */
#define DATE_FMT_EU_2     5     /*  string DD/MM/YY               */
#define DATE_FMT_EU_4     6     /*  string DD/MM/YYYY             */
#define DATE_STR_YY       7     /*  string YYMMDD                 */
#define DATE_STR_YYYY     8     /*  string YYYYMMDD               */

#define NEG_SIGN         '-'
#define THOUSAND_SEP     ','
#define DECIMAL_POINT    '.'
#ifndef DATE_SEPERATOR
#  define DATE_SEPERATOR '/'
#endif
#ifndef TIME_SEPERATOR
#  define TIME_SEPERATOR ':'
#endif

/*** structures ***/
struct s_j2_datetime
{
  int month;    /* Month,           01 --12             */
  int dd;       /* Day of Month,    01 -- [28|29|30|31] */
  int yy;       /* two digit year,  00 -- 99            */
  int yyyy;     /* four digit year, 0000 -- 9999        */
  int hh;       /* Hour of the day, 00 -- 23            */
  int minutes;  /* minutes,         00 -- 59            */
  int ss;       /* seconds,         00 -- 59            */
  int mil;      /* milliseconds,    000 -- 999          */
  int tm_isdst; /* Daylight ?  0 = no, > 0 = yes        */
} ;

/*** prototypes ***/
int  j2_bye_char(char *, char );
int  j2_expand_tab(int, size_t *, char **, char *);
int  j2_f_exist(char *);
int  j2_file_typ(char *);
int  j2_is_numr(char *);
long int j2_bye_emb(char *);
long int j2_bye_last(char *, char);
long int j2_chg_char(char, char, char *, SSIZE_T);
long int j2_clr_str(char *, char, int);
long int j2_justleft(char *);
long int j2_rtw(char *);
long int j2_fix_delm(char, char **, char *);
char *j2_get_prgname(char *, char *);
char *j2_today(struct s_j2_datetime *);
void j2_strupr(char *);
void j2_strlwr(char *);
int j2_is_space_embedded(char *);
int j2_fix_numr(char *, char, char);
int j2_is_all_spaces(char *);
long int j2_count_c(char, char *);
void j2_d_init(struct s_j2_datetime *);
int j2_d_isleap(int);
int j2_d_get_yyyy(int);
int j2_dl_fmt(char *, long, int);
int j2_ds_fmt(char *, char *, int, int);
int j2_date_is_valid(struct s_j2_datetime *);
int j2_dl_valid(long);
void j2_ds_date_time(char **, char **, char *);
int j2_dl_split(struct s_j2_datetime *, long, int);
int j2_ds_split(struct s_j2_datetime *, char *, int);
long int j2_str_to_secs(char *);
void j2_secs_to_str(char *, long int, size_t);
long int j2_d_to_sec(struct s_j2_datetime *);
char *j2_get_build(void);
unsigned int j2_getseed(void);
unsigned int j2_randrange(unsigned int, unsigned int);
SSIZE_T j2_getline(char **buf, size_t *n, FILE *);

#define j2_bye_nl(x)    j2_bye_last((x), '\n')
#define j2_bye_ctlm(x)  j2_bye_last((x), '\r')

#endif /*  J_LIB2_H  */
