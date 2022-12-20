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
/******************************************************************************
 * j_lib2m.h
 *
 * for canned messages
 *****************************************************************************/

#ifndef J_LIB2M_H

#define J_LIB2M_H "INCLUDED"

typedef unsigned long jm_counter;  /* allow 16 bit systems */

/*=============================================================================
* settings for jsplit/jcomb
=============================================================================*/
#define JS_MAX_SPLIT ((jm_counter) 9999999)
#define JS_MAX_SIZE  11           /* format v######.x   # < JS_MAX_SPLIT */
#define JS_FNAME     "v%07lu.x"   /* see jm_counter above if changed        */

/*=============================================================================
* Error Codes
=============================================================================*/
#ifndef EXIT_SUCCESS
#define	EXIT_SUCCESS	0	/* from stdlib.h */
#endif
#ifndef EXIT_FAILURE
#define	EXIT_FAILURE	1	/* from stdlib.h */
#endif

#define EXIT_LOGIC      2 /* prog ran fine BUT need to pass warning code     */
                          /* for a logical reason (Example: files different, */
                          /* or file open errors)                            */

#define COUNT_NUM unsigned long

#ifndef EXPAND_TAB_DEFAULT
#define EXPAND_TAB_DEFAULT 8
#endif

/*=============================================================================
* continue
=============================================================================*/
#ifndef PI
#  define PI ((double) 3.1415926535897932384626433832795)
#endif
#ifndef TAB_DEFAULT
#define TAB_DEFAULT 8
#endif

#ifndef MAX_LINES_PER_PAGE
#define MAX_LINES_PER_PAGE 60
#endif

#define FILE_NAME_STDIN  "-"
#define FILE_NAME_STDOUT "-"

/*** OS Specific Options ***/
#define ABS        abs        /* Function: absolute value of an integer  */
#define STRCASECMP strcasecmp /* Function: string compare  ignoring case */
#define SWITCH_CHAR   '-'
#define READ_OMODE O_RDONLY
#define READ_MODE "r"
#define WRITE_MODE "w"
#define UPDATE_MODE "r+"

/*** defaults ***/
#ifndef NULL
#define NULL '\0'
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FILE_URANDOM
#define FILE_URANDOM "/dev/urandom"
#endif
#ifndef FILE_RANDOM
#define FILE_RANDOM  "/dev/random"
#endif

/*** Arguments ***/
/*** MS-DOS, using'?' works except there when there is a one    ***/
/*** character file/dir in the current directory, so we use 'h' ***/
#define ARG_HELP       'h'  /* Show Help                      */
#define ARG_HELP_LONG  'H'  /* Show Long Help                 */

#define ARG_32_BIT        '2'  /* format for 32 bit                  */
#define ARG_7BIT_FILE     '7'  /* 7-bit ASCII                        */
#define ARG_8BIT_FILE     '8'  /* 8-bit Data File                    */
#define ARG_ABORT         'A'  /* Force Abort                        */
#define ARG_ACC_DATE      'a'  /* Last Access Date/Time              */
#define ARG_ALL           'a'  /* Turn on all options                */
#define ARG_UTF_8_ASCII   'a'  /* Convert UTF-8 to ASCII             */
#define ARG_BOLD          'B'  /* Show BOLD characters               */
#define ARG_BOM_NO        'B'  /* do NOT write BOM (Byte Order Mark) */
#define ARG_BYTE          'b'  /* Show byte counts                   */
#define ARG_CENT          'C'  /* degree is type Centigrade          */
#define ARG_COL           'C'  /* Column to start with               */
#define ARG_IS_CSV        'C'  /* input is a CSV file                */
#define ARG_SHOW_CONVERT  'C'  /* Write conversion details to file   */
#define ARG_CHANGED       'c'  /* Show changed data                  */
#define ARG_CHAR          'c'  /* Replace Character                  */
#define ARG_CHG_DATE      'c'  /* Last Status Change Date/Time       */
#define ARG_CITY          'c'  /* City to examine                    */
#define ARG_COUNT         'c'  /* Prefix output with line number     */
#define ARG_FMT_CSV       'c'  /* Format output as CSV               */
#define ARG_DUP_HEADING   'D'  /* Bypass duplicate heading           */
#define ARG_DELM_OUT      'D'  /* Output Field Delimiter             */
#define ARG_DECIMAL       'D'  /* Decimal Mode                       */
#define ARG_IN_DIR        'D'  /* Input Directory                    */
#define ARG_DETAIL_RPT    'd'  /* Print Detail Report                */
#define ARG_DATE          'd'  /* Date, YYYYMMDD                     */
#define ARG_DUPS          'd'  /* Duplicates                         */
#define ARG_DELM          'd'  /* Field Delimiter                    */
#define ARG_EXAMINE       'E'  /* Examine the file, do not convert   */
#define ARG_EXPAND        'E'  /* Expand tabs to spaces              */
#define ARG_END           'E'  /* End Line Number                    */
#define ARG_ERR           'e'  /* Output Error File                  */
#define ARG_FAHR          'F'  /* degree is type Fahrenheit          */
#define ARG_FIELD         'F'  /* Field to process                   */
#define ARG_FIRST_HEADG   'F'  /* First Record is a Heading          */
#define ARG_FLIP          'F'  /* change/flip character case         */
#define ARG_FRONT         'F'  /* Front Sprockets                    */
#define ARG_OUT_FMT       'F'  /* Output Format                      */
#define ARG_FORCE         'f'  /* force create files                 */
#define ARG_O_GLOBAL_HINT 'G'  /* Output Global data hints           */
#define ARG_I_GLOBAL_HINT 'g'  /* Input Global data hints            */
#define ARG_INVALID       'I'  /* Invalid Data File                  */
#define ARG_NOSHOW_IDOC   'I'  /* do NOT print these IDOC Numbers    */
#define ARG_ITERATIONS    'I'  /* Iterations                         */
#define ARG_INTEREST      'i'  /* interest rate                      */
#define ARG_SHOW_IDOC     'i'  /* do print only these IDOC Numbers   */
#define ARG_IGNORE        'i'  /* Ignore character case              */
#define ARG_INPUT         'i'  /* Input File                         */
#define ARG_JUSTLEFT      'J'  /* Left justifies the string          */
#define ARG_KELV          'K'  /* degree is type Kelvin              */
#define ARG_UNKNOWN_FILE  'K'  /* unknown Data File                  */
#define ARG_KEEP          'k'  /* keep value                         */
#define ARG_MIN_SIZE      'L'  /* Low value for File Split           */
#define ARG_MIN_VALUE     'L'  /* Low Value                          */
#define ARG_DATE_LOW      'L'  /* Low Date                           */
#define ARG_FNAME_INVERT  'L'  /* Show only file names when NO match */
#define ARG_LETTERS       'L'  /* show only ASCII letters            */
#define ARG_LINES_PG      'L'  /* lines per page                     */
#define ARG_LONG_LEN      'L'  /* print length of the longest line   */
#define ARG_LOWER         'l'  /* change character to lower case     */
#define ARG_SHOW_LINES    'l'  /* Show Line Number                   */
#define ARG_FMT_LIB       'l'  /* Generate response lib format       */
#define ARG_SHOW_LEVEL    'l'  /* Which conversion details to show   */
#define ARG_FNAME_ONLY    'l'  /* Show only file names               */
#define ARG_INCLUDE_NL    'l'  /* Include new line in counts         */
#define ARG_LIMIT_FILES   'l'  /* Limit the number of files created  */
#define ARG_LIST_MODE     'l'  /* How to show report                 */
#define ARG_ONLY_7BIT     'l'  /* show only ASCII 7bit characters    */
#define ARG_DATE_MAX      'M'  /* Maximum (High) Date                */
#define ARG_MAX_SIZE      'M'  /* Maximum Size                       */
#define ARG_MAX_VALUE     'M'  /* Maximum Value                      */
#define ARG_NOSHOW_MATNR  'M'  /* Bypass these Materials             */
#define ARG_LEFT_MARGIN   'm'  /* Left Margin                        */
#define ARG_LOAD_MEM      'm'  /* Load data to memory                */
#define ARG_MATCH_ONLY    'm'  /* show only data with a match        */
#define ARG_MAX_BYTES     'm'  /* Show Char Count                    */
#define ARG_MAX_COL       'm'  /* Maximum number of columns          */
#define ARG_MAX_LINES     'm'  /* stop search after num matches      */
#define ARG_MOD_DATE      'm'  /* Modification Date/Time             */
#define ARG_SHOW_MATNR    'm'  /* process ONLY these Materials       */
#define ARG_MOST          'm'  /* process at most                    */
#define ARG_SHORT_LINES   'N'  /* print line # of the shortest line  */
#define ARG_SHOW_NONASCII 'N'  /* Only show lines with non-ASCII char*/
#define ARG_NUMB_FIX      'N'  /* corrects Number Format             */
#define ARG_NL_ASCII      'n'  /* add new line to output             */
#define ARG_ADDNL         'n'  /* add new line to output             */
#define ARG_NUMB          'n'  /* # of lines to print                */
#define ARG_SHOW_NUM      'n'  /* Show only count of matches         */
#define ARG_NO_RPT        'n'  /* Do not create a report             */
#define ARG_OCT           'O'  /* Octal Mode                         */
#define ARG_OUT_DIR       'O'  /* Output Directory                   */
#define ARG_ONLY_LINE     'O'  /* show Only line # of matched lines  */
#define ARG_OUT           'o'  /* Output File                        */
#define ARG_PARM          'P'  /* file to get parameters             */
#define ARG_PRINT_FEED    'P'  /* Print a form feed                  */
#define ARG_USE_PI        'p'  /* use PI in calculations             */
#define ARG_PREFIX        'p'  /* Prefix text line with type         */
#define ARG_PATERN_FILE   'p'  /* Pattern File Name                  */
#define ARG_PRINCIPAL     'p'  /* Principal Amount                   */
#define ARG_PRINT_UTF8    'p'  /* print 'real' UTF-8 character       */
#define ARG_PRT_FORMAT    'p'  /* Output Format                      */
#define ARG_PAUSE         'p'  /* Pause for for microseconds         */
#define ARG_QUIET         'q'  /* Quiet Mode                         */
#define ARG_RANK          'R'  /* degree is type Rankine             */
#define ARG_REAR          'R'  /* Rear  Sprockets                    */
#define ARG_RTW           'R'  /* remove trailing spaces             */
#define ARG_RUNMODE       'R'  /* How to execute                     */
#define ARG_URAND         'R'  /* use rand() to generate random data */
#define ARG_RANDOM        'r'  /* use /dev/urandom as input          */
#define ARG_RANDOM_SPLIT  'r'  /* Randon size on split               */
#define ARG_REVERSE       'r'  /* reverse output                     */
#define ARG_REPORT        'r'  /* Report File                        */
#define ARG_RESET         'r'  /* Reset                              */
#define ARG_FILE_SIZE     's'  /* File Size                          */
#define ARG_MSG_NO_FILE   's'  /* Bypass display of file issues      */
#define ARG_SHORT_LEN     's'  /* print length of the longest line   */
#define ARG_SHOW_STAT     's'  /* do print only these IDOC Statuses  */
#define ARG_STATE         's'  /* US State 2 character abbreviation  */
#define ARG_STATS         's'  /* Show run stats at end              */
#define ARG_SLEEP         's'  /* sleep seconds                      */
#define ARG_STRIP_CHARS   's'  /* Remove these characters from string*/
#define ARG_DAYLIGHT      'S'  /* Force Daylight Savings             */
#define ARG_NOSHOW_STAT   'S'  /* do NOT print these IDOC Statuses   */
#define ARG_STATS_ONLY    'S'  /* Print only stats                   */
#define ARG_START         'S'  /* start print at line #              */
#define ARG_TAB_SPACE     'T'  /* Expand tabs to # characters        */
#define ARG_TITLE         't'  /* Report Title                       */
#define ARG_TEXT          't'  /* Process text mode                  */
#define ARG_TRANSLATE     't'  /* Character translation File         */
#define ARG_TIMEOUT       't'  /* Timeout for xmessage               */
#define ARG_UPPER         'U'  /* change character to upper case     */
#define ARG_UTF8_FILE     'U'  /* UTF-8 Data File                    */
#define ARG_ASCII_UTF_8   'u'  /* Convert ASCII to UTF-8             */
#define ARG_UNIQ          'u'  /* Show unique only                   */
#define ARG_UNSORTED      'u'  /* list is unsorted                   */
#define ARG_VERSION       'V'  /* Show Version Information           */
#define ARG_VERTICAL      'v'  /* Vertical Display                   */
#define ARG_VERBOSE       'v'  /* Verbose                            */
#define ARG_INVERT        'v'  /* Invert Match                       */
#define ARG_ADD_SPACE     'w'  /* Add Spaces                         */
#define ARG_WHITE_SPACE   'w'  /* Ignore white space                 */
#define ARG_WHEEL         'w'  /* Wheel Size                         */
#define ARG_WIDTH         'w'  /* Wheel Size                         */
#define ARG_NO_SHOW_FNAME 'w'  /* Never show file name on each line  */
#define ARG_WORD_COUNT    'w'  /* Show work count                    */
#define ARG_SHOW_FNAME    'W'  /* Show file name on each line        */
#define ARG_LONG_LINES    'X'  /* print line # of the longest line   */
#define ARG_DEBUG_MODE    'X'  /* turn on debug logic                */
#define ARG_HEX           'x'  /* Hex   Mode                         */
#define ARG_EXENAME       'x'  /* Executable Name                    */
#define ARG_YEARS         'y'  /* number of years                    */
#define ARG_ZORTECH       'z'  /* format Zortech c                   */

/*** text Literals ***/
#define MSG_OK_01   "SUCCESS S01 -- Files are the same\n"

#define MSG_ERR_E000    "Try '%s %c%c' for more information\n"
#define MSG_ERR_E001    "ERROR E001: Cannot open '%s' for read, file processing bypassed\n"
#define MSG_ERR_E002    "ERROR E002: Cannot open '%s' for write, processing aborted\n"
#define MSG_ERR_E003    "ERROR E003: Cannot allocate memory when processing file %s, processing aborted\n"
#define MSG_ERR_E004    "ERROR E004: value %ld invalid value for %c%c\n"
#define MSG_ERR_E004R   "ERROR E004: value %d invalid value for %c%c\n"
#define MSG_ERR_E004LU  "ERROR E004: value %lu invalid value for %c%c\n"
#define MSG_ERR_E004L   "ERROR E004: value %lld invalid value for %c%c\n"
#define MSG_ERR_E004LD  "ERROR E004: value %lf invalid value for %c%c\n"
#define MSG_ERR_E005    "ERROR E005: need one or more files to process\n"
#define MSG_ERR_E006    "ERROR E006: '%s' is an invalid value for %c%c\n"
#define MSG_ERR_E007    "ERROR E007: '%s' is an invalid value for %c%c, must be > %d and < %d\n"
#define MSG_ERR_E008    "ERROR E008: '%s' is an invalid value for %c%c, must be numeric\n"
#define MSG_ERR_E009    "ERROR E009: Environment Variable '%s' value '%s' invalid\n"
#define MSG_ERR_E010    "ERROR E010: cannot open %s for %s\n"
#define MSG_ERR_E011    "ERROR E011: Invalid File Name\n"
#define MSG_ERR_E012    "ERROR E012: Files are Different\n"
#define MSG_ERR_E013    "ERROR E013: need one executable/library file name\n"
#define MSG_ERR_E014    "ERROR E014: Environment Variable 'LIB' not set\n"
#define MSG_ERR_E015    "ERROR E015: Maximum array sized of %d reached\n"
#define MSG_ERR_E016    "ERROR E016: File %s cannot be found or no access\n"
#define MSG_ERR_E017    "ERROR E017: inconsistent arguments for '%c%c' and '%c%c'\n"
#define MSG_ERR_E018    "ERROR E018: %c%s invalid argument\n"
#define MSG_ERR_E019    "ERROR E019: Cannot generate file name, size greater than %d\n"
#define MSG_ERR_E020    "ERROR E020: Cannot allocate %d bytes of memory for Record %d, bypassed\n"
#define MSG_ERR_E020L   "ERROR E020: Cannot allocate %ld bytes of memory for Record %ld, bypassed\n"
#define MSG_ERR_E021    "ERROR E021: Cannot Open file\n"
#define MSG_ERR_E022    "ERROR E022: Required Argument '%c%c' missing\n"
#define MSG_ERR_E023    "ERROR E023: Cannot allocate memory when processing file %s, file bypassed\n"
#define MSG_ERR_E025    "ERROR E025: File %s cannot be created, already exists\n"
#define MSG_ERR_E026    "ERROR E026: File %s cannot be read\n"
#define MSG_ERR_E028    "ERROR E028: too many files specified\n"
#define MSG_ERR_E029    "ERROR E029: Sprocket list empty\n"
#define MSG_ERR_E030    "ERROR E030: Sprocket '%s' not numeric\n"
#define MSG_ERR_E031    "ERROR E031: Too many Sprockets specified, max: %d\n"
#define MSG_ERR_E032    "ERROR E032: Sprocket value of %d must be greater than %d\n"
#define MSG_ERR_E033    "ERROR E033: Wheel Size value of %d must be greater than %d\n"
#define MSG_ERR_E034    "ERROR E034: '%s' is an invalid option\n"
#define MSG_ERR_E035    "ERROR E035: Required Argument missing\n" /* see # 22 above */
#define MSG_ERR_E036    "ERROR E036: Cannot allocate memory for argument %c%c\n"
#define MSG_ERR_E037    "ERROR E037: Invalid File Name : %s\n"
#define MSG_ERR_E038    "ERROR E038: Translate File load problem\n"
#define MSG_ERR_E039    "ERROR E039: unable to load record %d\n"
#define MSG_ERR_E040    "ERROR E040: Translate File not specified\n"
#define MSG_ERR_E041    "ERROR E041: Invalid File Type Found (NOT 7-bit ASCII, 8-bit ASCII or UTF-8)\n"
#define MSG_ERR_E042    "ERROR E042: Cannot allocate memory to create a temporary file name\n"
#define MSG_ERR_E043    "ERROR E043: Cannot allocate %ld bytes of memory for Record %d, file:\n"
#define MSG_ERR_E044    "ERROR E044: '%s' data only 1 byte long, found %ld bytes\n"
#define MSG_ERR_E045    "ERROR E045: '%s' data not 2 bytes long, found %ld bytes\n"
#define MSG_ERR_E046    "ERROR E046: cannot allocate %ld bytes of memory for translate file\n"
#define MSG_ERR_E047    "ERROR E047: Cannot allocate %lu bytes of memory for Record %lu\n"
#define MSG_ERR_E048    "ERROR E048: Record %d, %s hex string (%s) too long\n"
#define MSG_ERR_E049    "ERROR E049: delimiter '%s' invalid\n"
#define MSG_ERR_E050    "ERROR E050: Rec %ld hex string too large\n"
#define MSG_ERR_E051    "ERROR E051: Unexpected Process Mode\n"
#define MSG_ERR_E052    "ERROR E052: Need search pattern\n"
#define MSG_ERR_E053    "ERROR E053: %c%c '%s' invalid for timeout\n"
#define MSG_ERR_E054    "ERROR E054: %c%c '%d' invalid for timeout\n"
#define MSG_ERR_E055    "ERROR E055: Write Error on File '%s' : %s\n"
#define MSG_ERR_E056    "ERROR E056: Open Error on File '%s' : %s\n"
#define MSG_ERR_E057    "ERROR E057: Read Failure on File '%s'\n"
#define MSG_ERR_E058    "ERROR E058: Expecting exactly %d File(s) to process, found %d\n"
#define MSG_ERR_E059    "ERROR E059: Files to be processed are the same files:\n"
#define MSG_ERR_E060    "ERROR E060: non-unique key found, rec # %ld on file:\n"
#define MSG_ERR_E061    "ERROR E061: sort order bad, rec # %ld on file:\n"
#define MSG_ERR_E062    "ERROR E062: field mismatch rec %ld, want %d fields but have %d fields. File:\n"
#define MSG_ERR_E063    "ERROR E063: Invalid Run Mode specified\n"
#define MSG_ERR_E064    "ERROR E064: Run Mode '%s' invalid for %c%c\n"
#define MSG_ERR_E065    "ERROR E065: record %ld format invalid\n"
#define MSG_ERR_E066    "ERROR E066: '%d' is an invalid value for %c%c, must be > %d\n"
#define MSG_ERR_E067    "ERROR E067: Terminal not found for stdin OR stdout\n"
#define MSG_ERR_E068    "ERROR E068: inconsistent arguments for '%c%c', '%c%c' and '%c%c'\n"
#define MSG_ERR_E069    "ERROR E069: Cannot locate a Translate File\n"
#define MSG_ERR_E070    "ERROR E070: '%s' invalid, must be numeric\n"
#define MSG_ERR_E071    "ERROR E071: %s '%s' invalid\n"
#define MSG_ERR_E072    "ERROR E072: %c%c invalid, can only specify a period or a comma\n"
#define MSG_ERR_E073    "ERROR E073: '%s' invalid for %c%c, must be exactly %s character(s) in size\n"
#define MSG_ERR_E074    "ERROR E074: 'Too many Arguments specified for %c%c\n"
#define MSG_ERR_E075    "ERROR E075: cannot determine valid Day of Month from : %02d/%02d/%04d\n"
#define MSG_ERR_E076    "ERROR E076: cannot locate a table entry for: %02d/%02d/%04d from File:\n    %s\n"
#define MSG_ERR_E077    "ERROR E077: %s is NOT a directory\n"
#define MSG_ERR_E078    "ERROR E078: Argument %c%c cannot only be specified once\n"
#define MSG_ERR_E079    "ERROR E079: %s is not a Dir\n"
#define MSG_ERR_E080    "ERROR E080: cannot allocate initial memory : %s\n"
#define MSG_ERR_E081    "ERROR E081: Required Argument '%c%c' is NOT numeric (%s)\n"
#define MSG_ERR_E082    "ERROR E082: Required Argument '%c%c' invalid length (%s)\n"
#define MSG_ERR_E083    "ERROR E083: Required Argument '%c%c' must be between %d and %d, but is %d\n"
#define MSG_ERR_E084    "ERROR E084: Value for %c%c (%ld) less than the Value for %c%c (%ld)\n"
#define MSG_ERR_E085    "ERROR E085: Value for %c%c greater than 0\n"
#define MSG_ERR_E086    "ERROR E086: Rec %ld - Start Date greater than End Date, see\n"
#define MSG_ERR_E087    "ERROR E087: Rec %ld - Invalid Date/Time found '%s'\n"
#define MSG_ERR_E088LL  "ERROR E088: Minimum Value %lld must be less than Maximum Value %lld\n"

#define MSG_ERR_FNAME "           File %d: %s\n"
#define MSG_ERR_FNAMN "           File: %s\n"

#define MSG_WARN_W001 "W001: Bypass File '%s', type %s\n"
#define MSG_WARN_W002 "W002: Open Error Bypass File '%s' : %s\n"
#define MSG_WARN_W003 "W003: Write Error on File '%s' : %s\n"
#define MSG_WARN_W004 "W004: could not open %s, default to zero mode\n"
#define MSG_WARN_W005 "W005: Warning, one of more cols truncated or invalid\n"
#define MSG_WARN_W006 "W006: Warning, Record %ld, Pos/Field %ld truncated, value: old '%s' new '%s'\n"
#define MSG_WARN_W007 "W007: Warning, Record %ld, Pos/Field %ld INVALID, value '%s'\n"
#define MSG_WARN_W008 "W008: %s is a directory\n"
#define MSG_WARN_W009 "W009: %s File Type Unknown\n"
#define MSG_WARN_W010 "W010: %s File Type Character Special\n"
#define MSG_WARN_W011 "W011: %s File Type Block Special\n"
#define MSG_WARN_W012 "W012: %s File Type Cannot be determined\n"
#define MSG_WARN_W013 "W013: %s File Type undetermined\n"
#define MSG_WARN_W014 "W014: Run Mode not yet supported, processing bypassed\n"
#define MSG_WARN_W015 "W015: Warning, %ld Record(s) has Invalid Values\n"
#define MSG_WARN_W016 "W016: Record # %ld Bypassed, Invalid Value\n"
#define MSG_WARN_W017 "W017: Bypassed file, already exists: %s\n"
#define MSG_WARN_W018 "W018: Open %s failed, will use time() : %s\n"
#define MSG_WARN_W019 "W019: Read of %s failed, default to time()\n"
#define MSG_WARN_W020 "W020: Unable to parse IDOC %s, approx rec # %ld, File %s\n"
#define MSG_WARN_W021 "W021: format unknown for file %s\n"
#define MSG_WARN_W022 "W022: Unsupported table %s, change parse_matnr_kotabnr() in %s\n"
#define MSG_WARN_W023 "W023: Bypassing split not enabled for: %s\n"
#define MSG_WARN_W024 "W024: Will use a call to random(3) to get overwrite characters\n"
#define MSG_WARN_W025 "W025: Will now try %s to get overwrite characters\n"
#define MSG_WARN_W026 "W026: Bypassed Duplicate:  %-10s        - Record # %ld\n"
#define MSG_WARN_W027 "W027: Bypassed Filter:     %-10s        - Record # %ld\n"
#define MSG_WARN_W028 "W028: Bypassed Acct Group: %-10s - %4s - Record # %ld\n"
#define MSG_WARN_W029 "W029: Rec %ld - outlier, bypassing\n"
#define MSG_WARN_W030 "W030: Bypassed Record %ld, invalid format\n"
  
#define MSG_INFO_I001 "I001: %s -- Processing '%s'\n"
#define MSG_INFO_I002 "I002: %s -- Reads %ld : Writes %ld\n"
#define MSG_INFO_I003 "I003: Reads %-9ld : Writes %-9ld : File: %s\n"
#define MSG_INFO_I004 "I004: Reads %-9ld : Unique values Found %-ld : File: %s\n"
#define MSG_INFO_I005 "I005: Reads %-ld : File: %s\n"
#define MSG_INFO_I006 "I006: Appending %s\n"
#define MSG_INFO_I007 "I007:        to %s\n"
#define MSG_INFO_I008 "I008: File: %s\n      may not exist or error occurred\n"
#define MSG_INFO_I009 "I009: Reads:  %ld : IDOCs Found %ld : Input  File: %s\n"
#define MSG_INFO_I010 "I010: Writes: %ld : Total IDOCs %ld : Output File: %s\n"
#define MSG_INFO_I011 "I011: Listing '%s'\n"
#define MSG_INFO_I012 "I012:         match: '%s'\n"
#define MSG_INFO_I013 "I013: Reads:  %ld : BOMs  Found %ld : Input  File: %s\n"
#define MSG_INFO_I014 "I014: Writes: %ld : Total BOMs  %ld : Output File: %s\n"
#define MSG_INFO_I015 "I015: Start Records Found:      %ld\n"
#define MSG_INFO_I016 "I016: Start Records no End:     %ld\n"
#define MSG_INFO_I017 "I017: End   Records Found:      %ld\n"
#define MSG_INFO_I018 "I018: End   Records no Start:   %ld\n"
#define MSG_INFO_I019 "I019: Matched Records Found:    %ld\n"
#define MSG_INFO_I020 "I020: Matched with an Opp Code  %ld\n"
#define MSG_INFO_I021 "I021: Matched w/blank Opp Code  %ld\n"
#define MSG_INFO_I022 "I022: Note, Write counts excludes the Heading Record\n"
#define MSG_INFO_I023 "I023:            Lines Read:  %9ld\n"
#define MSG_INFO_I024 "I024:            Bytes Read:                      %9ld\n"
#define MSG_INFO_I025 "I025:     7 bit ASCII Found:  %9ld -- Bytes: %9ld\n"
#define MSG_INFO_I026 "I026:     8 bit ASCII Found:  %9ld -- Bytes: %9ld\n"
#define MSG_INFO_I027 "I027:  Invalid (ctrl) Found:  %9ld -- Bytes: %9ld\n"
#define MSG_INFO_I028 "I028:           UTF-8 Found:  %9ld -- Bytes: %9ld\n"
#define MSG_INFO_I029 "I029:  Overlong UTF-8 Found:  %9ld -- Bytes: %9ld\n"
#define MSG_INFO_I030 "I030:  Unallocd UTF-8 Found:  %9ld -- Bytes: %9ld\n"
#define MSG_INFO_I031 "I031:   Invalid UTF-8 Found:  %9ld -- Bytes: %9ld\n"
#define MSG_INFO_I032 "I032:       Undefined Found:  %9ld -- Bytes: %9ld\n"
#define MSG_INFO_I033 "I033:             BOM Found:  %9ld -- Bytes: %9ld\n"
#define MSG_INFO_I034 "I034:           IDOCs Found:  %9ld\n"
#define MSG_INFO_I035 "I035:         Lines Written:  %9ld\n"
#define MSG_INFO_I036 "I036:        IDOCs Bypassed:  %9ld\n"
#define MSG_INFO_I037 "I037:     Statuses Bypassed:  %9ld\n"
#define MSG_INFO_I038 "I038:    Materials Bypassed:  %9ld\n"
#define MSG_INFO_I039 "I039: %s -- Pass %d of %d\n"
#define MSG_INFO_I040 "I040: Characters Translated:  %9ld\n"
#define MSG_INFO_I041 "I041:         Bytes Written:                      %9ld\n"
#define MSG_INFO_I042 "I042:        Skipped Writes:                      %9ld\n"

#define MSG_INFO_I043 "I043: Input  File: %s\n"
#define MSG_INFO_I044 "I044: Output File: %s\n"
#define MSG_INFO_I045 "I045: File  Reads: %-ld\n"
#define MSG_INFO_I046 "I046: Total Reads: %-ld    Total Writes %-ld\n"
#define MSG_INFO_I047 "I047: Seed:  %u\n"
#define MSG_INFO_I048 "I048: Index: %ld\n"
#define MSG_INFO_I049 "I049: Reads %-9ld : Writes %-9ld : <--- Total\n"

#define MSG_INFO_I051 "I051: For Record Number: %ld\n"
#define MSG_INFO_I052 "I052: %10s %02d/%02d/%04d %02d:%02d:%02d %ld\n"
#define MSG_INFO_I053 "I053: Column Data not found for rec %ld\n"
#define MSG_INFO_I054 "I054: Column Data for record  %ld, total columns: %ld\n"
#define MSG_INFO_I055 "I055:     Column   %3ld: %s\n"
#define MSG_INFO_I056 "I056: Field Type         %s\n"

#define MSG_INFO_I060 "Detail for IDOC: %s\n"
#define MSG_INFO_I061 "           Type: %s\n"
#define MSG_INFO_I062 "       Material: %s\n"
#define MSG_INFO_I063 "       Document: %s\n"
#define MSG_INFO_I064 "      Condition: %s\n"
#define MSG_INFO_I065 "        Created: %s %s\n"
#define MSG_INFO_I066 "From SAP System: %s\n"
#define MSG_INFO_I067 "I067: Process Only these Materials:\n"
#define MSG_INFO_I068 "I068: Do NOT Process these Materials:\n"
#define MSG_INFO_I069 "I069: Bypassed IDOC %s, Material %s NOT in Filter\n"
#define MSG_INFO_I070 "I070: Bypassed IDOC %s, Material %s is in Bypass Filter\n"
#define MSG_INFO_I071 "I071: Selected IDOC %s due to Material %s\n"
#define MSG_INFO_I072 "I072:    Lines Reads:  %9ld - File %s\n"
#define MSG_INFO_I073 "I073:  Parents Found:  %9ld\n"
#define MSG_INFO_I074 "I074:     IDOC Found:  %9ld\n"
#define MSG_INFO_I075 "I075:       Selected:  %9ld\n"
#define MSG_INFO_I076 "I076:       Bypassed:  %9ld\n"
#define MSG_INFO_I077 "I077: Items Selected:  %9ld\n"
#define MSG_INFO_I078 "I078: Items Bypassed:  %9ld\n"
#define MSG_INFO_I079 "I079: Items    Total:  %9ld\n"
#define MSG_INFO_I080 "I080:   Lines Writes:  %9ld - File %s\n"

#define MSG_INFO_I081 "I081: Number of Input Files          %d\n"
#define MSG_INFO_I082 "I082: Remove non-ASCII characters  ? %s\n"
#define MSG_INFO_I083 "I083: Input  Files in csv format   ? %s\n"
#define MSG_INFO_I084 "I084: Output File  in csv format   ? %s\n"
#define MSG_INFO_I085 "I085: Non-csv Field Delimiter        '%c'\n"
#define MSG_INFO_I086 "I086: Errors written to file       ? %s\n"
#define MSG_INFO_I087 "I087: Force Create Output          ? %s\n"
#define MSG_INFO_I088 "I088: Maximum Field Size             %s\n"
#define MSG_INFO_I089 "I089: Maximum Field Size             %d\n"
#define MSG_INFO_I090 "I090: Output written to file       ? %s\n"
#define MSG_INFO_I091 "I091: Force these columns as Text    %s\n"
#define MSG_INFO_I092 "I092: Verbose Level                  %d\n"
#define MSG_INFO_I093 "I093: Print Space on Empty Columns ? %s\n"
#define MSG_INFO_I094 "I094: Decimal Point is a             '%c'\n"
#define MSG_INFO_I095 "I095:             column  as Text    %d\n"
#define MSG_INFO_I096 "I096:     Read Bytes:  %9ld - File %s\n"
#define MSG_INFO_I097 "I097:    Write Bytes:  %9ld - File %s\n"
#define MSG_INFO_I098 "I098: Random Numbers Written  : %-llu\n"
#define MSG_INFO_I099 "I099: Sleeping                : %-u second(s)\n"
#define MSG_INFO_I100 "I100: Pause after printing    : %-u Random Numbers\n"
#define MSG_INFO_I101 "I101: Minimum Value to Print  : %-llu\n"
#define MSG_INFO_I102 "I102: Maximum Value to Print  : %-llu\n"
#define MSG_INFO_I103 "I103: Number of Items to Print: %-u\n"
#define MSG_INFO_I104 "I104: Pause Seconds           : %-u\n"
#define MSG_INFO_I105 "I105: Verbose Level           : %-d\n"

#define MSG_RPT_R01 "Column Statistics:\n"
#define MSG_RPT_R02 "Data for Record # %ld:\n"
#define MSG_RPT_R03 "    col   type        Pos   Size  New Size Min / Max\n"
#define MSG_RPT_R04 "    col   type        Pos   Size  New Size Data Value\n"
#define MSG_RPT_R05 "    ----- ----------- ----- ----- -------- ---------------------------------\n"
#define MSG_RPT_R06 "    %5d %s %5ld %5ld %8ld %s / %s\n"
#define MSG_RPT_R07 "    %5d %s %5ld %5ld %8ld %s\n"

#define MSG_RPT_R08 "Column Parameter Information:\n"
#define MSG_RPT_R09 "    Col Type    Format Mode    Field/Pos      Size  New Size Name\n"
#define MSG_RPT_R10 "    ----------- -------------- --------- --------- --------- ------------------\n"
#define MSG_RPT_R11 "    %-11s %-14s %9ld %9ld %9ld %s\n"

#define MSG_RPT_R12 "Splitting %s file %s\n"
#define MSG_RPT_R13 "          into multiple files with a maximum\n"
#define MSG_RPT_R14 "          of %lu %s per file,\n"
#define MSG_RPT_R15 "          limiting files created to %lu\n\n"
#define MSG_RPT_R16 "%s  in/out counts:\n"
#define MSG_RPT_R17 "    I/O type       I/O %s  File Name\n"
#define MSG_RPT_R18 "    --------- --------------- ------------------\n"
#define MSG_RPT_R19 "    %9s %15lu %s\n"
#define MSG_RPT_R20 "    ========= =============== ==================\n"
#define MSG_RPT_R21 "          Output Size Randomized using range of %lu to %lu\n"

#define LIT_INFO_01  "\tBuild: %s %s\n"
#define LIT_INFO_02  "j_lib2 built:"
#define LIT_ENV_01   "Environment Variables:\n"
#define LIT_ENV_02   "\t%-15s : Default (%c%c) %s\n"
#define LIT_ENV_03   "File does not exist"
#define LIT_ENV_04   "Cannot access"
#define LIT_INFO_END "******* End of Report *******"

#define LIT_HINT_DECIMAL    "Numeric Decimal Point"
#define LIT_HINT_THOUSAND   "Numeric Thousand Separator"
#define LIT_HINT_DATE_SEP   "Date Separator"
#define LIT_HINT_DATE_FMT   "Date Format"
#define LIT_TRANS_START     "START Translate Table"
#define LIT_TRANS_END       "END   Translate Table"
#define LIT_SKIP_PRINT      "Print to output skipped"

#define LIT_ARROW_03      "-->"
#define LIT_ARROW_04      "--->"
#define LIT_ARROW_06      "----->"
#define LIT_ARROW_07      "------>"
#define LIT_ARROW_08      "------->"
#define LIT_ARROW_09      "-------->"
#define LIT_C80           "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
#define LIT_D80           "================================================================================"
#define LIT_DLINE_14      "=============="
#define LIT_DLINE_15      "================"
#define LIT_DLINE_16      "================"
#define LIT_DLINE_17      "================="
#define LIT_DLINE_30      "=============================="
#define LIT_DLINE_80      "==============================================================================="
#define LIT_DLINE_132     "===================================================================================================================================="
#define LIT_L80           "--------------------------------------------------------------------------------"
#define LIT_ULINE_02      "--"
#define LIT_ULINE_03      "---"
#define LIT_ULINE_04      "----"
#define LIT_ULINE_05      "-----"
#define LIT_ULINE_06      "------"
#define LIT_ULINE_07      "-------"
#define LIT_ULINE_08      "--------"
#define LIT_ULINE_09      "---------"
#define LIT_ULINE_10      "----------"
#define LIT_ULINE_11      "-----------"
#define LIT_ULINE_12      "------------"
#define LIT_ULINE_13      "-------------"
#define LIT_ULINE_15      "---------------"
#define LIT_ULINE_16      "----------------"
#define LIT_ULINE_17      "-----------------"
#define LIT_ULINE_19      "-------------------"
#define LIT_ULINE_21      "---------------------"
#define LIT_ULINE_22      "----------------------"
#define LIT_ULINE_23      "-----------------------"
#define LIT_ULINE_28      "----------------------------"
#define LIT_ULINE_29      "-----------------------------"
#define LIT_ULINE_30      "------------------------------"
#define LIT_ULINE_44      "-------------------------------------------"
#define LIT_ULINE_80      "-------------------------------------------------------------------------------"
#define LIT_ULINE_132     "-----------------------------------------------------------------------------------------------------------------------------------"
#define LIT_7_BIT         "7-bit"
#define LIT_8_BIT         "8-bit"
#define LIT_ASCII         "ASCII"
#define LIT_BOM1          "BOM?"
#define LIT_BYTE          "Byte"
#define LIT_BYTES         "Bytes"
#define LIT_CDCT_5        "cd/ct"
#define LIT_CENT          "Centigrade"
#define LIT_CHAR          "Char"
#define LIT_CHAR_TYPE     "Char Type"
#define LIT_COMMAND       "Command"
#define LIT_CONVERTED     "Converted"
#define LIT_COUNTRY       "Country"
#define LIT_CURRENCY      "Currency"
#define LIT_DATE          "Date"
#define LIT_DECIMAL_P     "decimal point"
#define LIT_DELIMITER     "delimiter"
#define LIT_DETAIL_C      "Detail"
#define LIT_DIST_C        "Dist.C"
#define LIT_DIFFERENT     "Fields Different"
#define LIT_EIGHT         "eight"
#define LIT_END_C3        "END"
#define LIT_ERROR         "ERROR"
#define LIT_ERRORS        "Errors...."
#define LIT_FAHR          "Fahrenheit"
#define LIT_FAILED        "Failed"
#define LIT_FILE          "File"
#define LIT_FILE_NAME     "File Name"
#define LIT_FILE_STATS    "File Stats"
#define LIT_FILE_SIZE     "File Size"
#define LIT_FILTER_D      "Do NOT Process these Keys"
#define LIT_FILTER_F      "Key Filter File"
#define LIT_FILTER_N      "No Filter"
#define LIT_FILTER_P      "Process only these Keys"
#define LIT_FILTER_T      "Filter Type"
#define LIT_FOR           "for"
#define LIT_HEX           "Hex"
#define LIT_IDOC          "IDOC #"
#define LIT_IDOC_STAT     "IDOC Status"
#define LIT_IDOC_TYPE     "IDOC Type"
#define LIT_INTEREST      "Interst"
#define LIT_INVALID       "Invalid"
#define LIT_KELV          "Kelvin"
#define LIT_LBINARY       "binary"
#define LIT_LBYTES        "bytes"
#define LIT_LEVEL         "Level"
#define LIT_LINES         "Lines"
#define LIT_LINES_READ    "Lines Read"
#define LIT_LINES_WRITES  "Lines Written"
#define LIT_LIST          "List"
#define LIT_LLINES        "lines"
#define LIT_LOAN          "Loan"
#define LIT_LTEXT         "text"
#define LIT_MAIN          "Main"
#define LIT_MATERIAL      "Material"
#define LIT_MATERIAL_DOC  "matnr/doc"
#define LIT_MAX           "Max Size"
#define LIT_MAX_NUM       "Max Line"
#define LIT_MIN           "Min Size"
#define LIT_MIN_NUM       "Min Line"
#define LIT_MODE          "Mode"
#define LIT_NASCII        "NON-ASCII"
#define LIT_NEW           "New"
#define LIT_NO            "No"
#define LIT_NO_MATCH      "NO MATCH"
#define LIT_NO_NEED       "No Need"
#define LIT_NOT           "Not"
#define LIT_NULL          "<null>"
#define LIT_OF            "of"
#define LIT_ONE           "one"
#define LIT_OLD           "Old"
#define LIT_OR            "or"
#define LIT_PAGE          "Page:"
#define LIT_POS           "Pos"
#define LIT_POSITION      "Position"
#define LIT_QUIT          "Quit"
#define LIT_RANK          "Rankine"
#define LIT_RATE          "Rate"
#define LIT_READ          "read"
#define LIT_RECORD        "Record"
#define LIT_RERUN         "Rerun"
#define LIT_REV           "Revision"
#define LIT_SAME          "Fields Same"
#define LIT_STATUS_2      "st"
#define LIT_START_C5      "START"
#define LIT_STATUS        "Status"
#define LIT_STDERR        "(standard error)"
#define LIT_STDIN         "(standard input)"
#define LIT_STDOUT        "(standard output)"
#define LIT_SUCCEEDED     "Succeeded"
#define LIT_TAB_INFO      "Tab Stop: %d\n"
#define LIT_TABLE_3       "tbl"
#define LIT_TIME          "Time"
#define LIT_TIME_DT       "Tm / Dto"
#define LIT_TOTAL         "Total"
#define LIT_TRANSLATED    "translated"
#define LIT_TWO           "two"
#define LIT_TYPE          "Type"
#define LIT_UNDEFINED     "undefined"
#define LIT_UNKN          "Unkn"
#define LIT_UNKNOWN       "unknown"
#define LIT_UNLIMITED     "unlimited"
#define LIT_UTF8          "UTF-8"
#define LIT_UTF8_UNICODE  "UTF-8/UNICODE"
#define LIT_WORDS         "Words"
#define LIT_WRITTEN       "written"
#define LIT_YEARS         "Years"
#define LIT_YES           "Yes"

#define LIT_ACC_DT        "Access Date/Time"
#define LIT_MOD_DT        "Mod Date/Time"
#define LIT_STA_DT        "Stat Chg Date/Time"

#define LIT_BYP_ABORTED       "Bypassed Call Aborted"
#define LIT_BYP_BLOCK_SPECIAL "Bypassed Block Special"
#define LIT_BYP_CHAR_SPEC     "Bypassed Character Special"
#define LIT_BYP_DIRECTORY     "Bypassed Directory"
#define LIT_BYP_FIFO          "Bypassed FIFO"
#define LIT_BYP_MISSING       "Bypassed File Missing"
#define LIT_BYP_NO_INFO       "Bypassed cannot get info"
#define LIT_BYP_PIPE          "Bypassed Pipe"
#define LIT_BYP_SOCKET        "Bypassed Socket"
#define LIT_BYP_SYMB_LINK     "Symbol Link"
#define LIT_BYP_UNDEFINED     "Bypassed Undefined issue"
#define LIT_BYP_UNKNOWN       "Bypassed Unknown Type"

#define LIT_MATNR_SHOW    "Only print these Materials from file:"
#define LIT_MATNR_NOSHOW  "Do NOT print these Materials from file:"
#define LIT_IDOC_SHOW     "Only print these IDOCs from file:"
#define LIT_IDOC_NOSHOW   "Do NOT print these IDOCs from file:"
#define LIT_STAT_SHOW     "Only print these Statuses from file:"
#define LIT_STAT_NOSHOW   "Do NOT print these Statuses from file:"
#define LIT_CMSG_INV      "Invalid"
#define LIT_CMSG_NULL     "Invalid null"
#define LIT_CMSG_RET      "Return, valid (DOS)"
#define LIT_CMSG_NL       "Valid New Line"
#define LIT_CMSG_DELM     "Valid Delimiter"
#define LIT_CMSG_A8       "Invalid, Extended ASCII"
#define LIT_CMSG_A7       "Valid 7-ASCII"
#define LIT_CMSG_U8       "Valid UTF-8"
#define LIT_CMSG_U8F      "Valid UTF-8, but Forms"
#define LIT_CMSG_U8I      "Invalid UTF-8"
#define LIT_CMSG_U8L      "Invalid UTF-8, overlong"
#define LIT_CMSG_U8P      "Valid UTF-8, but private"
#define LIT_CMSG_U8U      "Invalid UTF-8, Unalloc"
#define LIT_TALLF         "Total all Files"

#define LIT_YN            "(y/n)"
#define LIT_RETURN        "<RETURN>"
#define LIT_ASCII_UTF     "(ASCII/UTF-8 ...)"

#define LIT_A2UC_HELP_01 "Convert an ASCII File / UNICODE UTF-8 Data.\n"
#define LIT_RPT_01       "BOM (Byte Order Mark) written"
#define LIT_RPT_02       "ASCII -- UTF-8/UNICODE Translation Table"
#define LIT_RPT_03       "First record missing"
#define LIT_TITLE_PM_TO_UNICODE  "Convert Text File to UTF-8 (UNICODE)"
#define LIT_TITLE_PM_TO_ASCII    "Convert Text File to ASCII"
#define LIT_TITLE_PM_VALIDATE    "Analyze character type in a Text File"
#define LIT_TITLE_CONVERT        "Character Conversion Detail"
#define LIT_TITLE_STAT           "Processing Stats"
#define LIT_TITLE_FTRAN          "Used Translate File:"
#define LIT_DETAIL_INFO          "Detail Info"

/*** brief help text ***/
#define USG_MSG_ARG_DUP_HEADING          "\t%c%c val\t\t: Bypass subsequent print if 'val' found in the record\n"
#define USG_MSG_USAGE                    "usage:\t%s [OPTIONS] [FILES ...]\n"
#define USG_MSG_USAGE_1                  "usage:\t%s [OPTIONS]\n"
#define USG_MSG_USAGE_2                  "usage:\t%s [OPTIONS] FILE_1 FILE_2\n"
#define USG_MSG_USAGE_3                  "usage:\t%s [OPTIONS] FILE_1 [FILE_2 ...]\n"
#define USG_MSG_USAGE_4                  "usage:\t%s OPTIONS\n"
#define USG_MSG_USAGE_5                  "usage:\t%s [OPTIONS] [FILE]\n"
#define USG_MSG_USAGE_6                  "usage:\t%s [OPTIONS] temperature1 [temperature2...]\n"
#define USG_MSG_OPTIONS                  "Options\n"
#define USG_MSG_ARG_BOLD                 "\t%c%c num\t\t: Overrstike caracters 'num' times\n"
#define USG_MSG_ARG_ERR                  "\t%c%c file\t\t: Write errors to file 'file', default stderr\n"
#define USG_MSG_ARG_HELP                 "\t%c%c\t\t: Show brief help and exit\n"
#define USG_MSG_ARG_HELP_LONG            "\t%c%c\t\t: Show detail help and exit\n"
#define USG_MSG_ARG_INPUT                "\t%c%c file\t\t: Read data from file 'file', default stdin\n"
#define USG_MSG_ARG_INPUT_1              "\t%c%c file\t\t: use this file instead of file '~/%s'\n"
#define USG_MSG_ARG_INPUT_2              "\t%c%c file\t\t: Read data from file 'file'\n"
#define USG_MSG_ARG_INVALID              "\t%c%c file\t\t: Write 'Invalid' Records to 'file'\n"
#define USG_MSG_ARG_INVALID_1            "\t%c%c\t\t: Print Invalid (ctrl) characters\n"
#define USG_MSG_ARG_PATERN_FILE          "\t%c%c file\t\t: Obtain search text from 'file'\n"
#define USG_MSG_ARG_PATERN_FIL1          "\t%c%c kfile\t: Obtain search keys from 'kfile'\n"
#define USG_MSG_ARG_OUT                  "\t%c%c file\t\t: Write output to file 'file', default stdout\n"
#define USG_MSG_ARG_OUT_DIR              "\t%c%c dir\t\t: Create split output files in Directory 'dir'\n"
#define USG_MSG_ARG_PARM                 "\t%c%c file\t\t: Obtain some Column parameters from this file\n"
#define USG_MSG_ARG_VERSION              "\t%c%c\t\t: Show revision information and exit\n"
#define USG_MSG_ARG_VERBOSE_1            "\t%c%c\t\t: Show headings for file being processed\n"
#define USG_MSG_ARG_VERBOSE_2            "\t%c%c\t\t: Show line # that failed\n"
#define USG_MSG_ARG_VERBOSE_3            "\t%c%c\t\t: Show detail Gear Inch Information\n"
#define USG_MSG_ARG_VERBOSE_4            "\t%c%c\t\t: Show detail File Stats\n"
#define USG_MSG_ARG_VERBOSE_5            "\t%c%c\t\t: show run stats on stderr\n"
#define USG_MSG_ARG_VERBOSE_6            "\t%c%c\t\t: Print column headings\n"
#define USG_MSG_ARG_VERBOSE_7            "\t%c%c\t\t: Print 7bit, 8bit, UTF-8 and ctrl characters\n"
#define USG_MSG_ARG_VERBOSE_8            "\t%c%c\t\t: verbose level, each time specified level increases\n"
#define USG_MSG_ARG_QUIET                "\t%c%c\t\t: quiet, do not print results.\n"
#define USG_MSG_ARG_QUIET_1              "\t%c%c\t\t: do not show processing stats.\n"
#define USG_MSG_ARG_QUIET_2              "\t%c%c\t\t: do not show file headings.\n"
#define USG_MSG_ARG_QUIET_3              "\t%c%c\t\t: do not print file open errors\n"
#define USG_MSG_ARG_QUIET_4              "\t%c%c\t\t: print summary\n"
#define USG_MSG_ARG_RANDOM_SPLIT         "\t%c%c\t\t: Split files using a Random Max Value\n"
#define USG_MSG_ARG_RANDOM_1             "\t%c%c\t\t: Use %s or if missing, %s\n"
#define USG_MSG_ARG_RANDOM_2             "\t\t\t: to overrite data instead of using zeros\n"
#define USG_MSG_ARG_URAND                "\t%c%c\t\t: Use rand(3) to generate Random Data\n"
#define USG_MSG_ARG_FIELD                "\t%c%c\t\t: Field number to examine/count\n"
#define USG_MSG_ARG_DELM                 "\t%c%c c\t\t: Field delimiter, the actual character OR\n"
#define USG_MSG_ARG_DELM_C               "\t\t\t  the decimal # representing the character.\n"
#define USG_MSG_ARG_DELM_D               "\t\t\t  Default '%c'\n"
#define USG_MSG_ARG_DELM_I               "\t%c%c c\t\t: Input File Field Delimiter, the actual character OR\n"
#define USG_MSG_ARG_DELM_O               "\t%c%c c\t\t: Output File Field Delimiter, the actual character OR\n"
#define USG_MSG_ARG_DELM_A               "\t\t\t  the decimal # representing the character.\n"
#define USG_MSG_ARG_DELM_B               "\t\t\t  Ex: 7 = '^G', 9 = TAB, 124 = '|' or just '|'.\n"
#define USG_MSG_ARG_DELM_BEL             "\t\t\t  If not specified the default is BEL '^G'.\n"
#define USG_MSG_ARG_DELM_U               "\t\t\t  If not specified, defaults to '|'.\n"
#define USG_MSG_ARG_DELM_V               "\t\t\t  Will be treated as a 7-bit ASCII character.\n"
#define USG_MSG_ARG_DELM_W               "\t\t\t  If not specified, assumes a flat file.\n"
#define USG_MSG_ARG_DELM_X               "\t\t\t  Must be a value < 128 (ie: < 0x80)\n"
#define USG_MSG_ARG_DELM_Y               "\t\t\t  If specified, this char is assumed to be 7-bit ASCII\n"
#define USG_MSG_ARG_DELM_Z               "\t\t\t  If not specified, assumes a flat, fixed length file.\n"
#define USG_MSG_ARG_LOWER                "\t%c%c\t\t: Change all characters to Lower Case.\n"
#define USG_MSG_ARG_UPPER                "\t%c%c\t\t: Change all characters to Upper Case.\n"
#define USG_MSG_ARG_FLIP                 "\t%c%c\t\t: Change (flip) case of all characters.\n"
#define USG_MSG_ARG_CHAR                 "\t%c%c x\t\t: replace non-ASCII with character 'x'\n"
#define USG_MSG_ARG_CHAR_1A              "\t%c%c x\t\t: replace non-ASCII with character 'x' instead\n"
#define USG_MSG_ARG_CHAR_1B              "\t\t\t  of the default character '%c' on output\n"
#define USG_MSG_ARG_ADDNL                "\t%c%c x\t\t: add a new line after display of 'x' bytes\n"
#define USG_MSG_ARG_ADDNL_1A             "\t%c%c\t\t: add a new line to the 'out' file to make sure no\n"
#define USG_MSG_ARG_ADDNL_1B             "\t\t\t  characters exceed 80 bytes.  Default, no new-line\n"
#define USG_MSG_ARG_CHAR_1C              "\t%c%c x\t\t: overwrite data in file with character 'x',\n"
#define USG_MSG_ARG_CHAR_1D              "\t\t\t  If 'x' longer than 1 byte and numeric, \n"
#define USG_MSG_ARG_CHAR_1E              "\t\t\t  decimal value 'x' is converted to a character.\n"
#define USG_MSG_ARG_CHAR_1F              "\t\t\t  If not specified, NULL is used.\n"
#define USG_MSG_SHOW_STATS               "\t%c%c\t\t: Display run stats on stderr\n"
#define USG_MSG_ARG_TAB_SPACE_A          "\t%c%c num\t\t: Expand tabs to 'num' spaces.\n"
#define USG_MSG_ARG_TAB_SPACE_B          "\t\t\t  default, do NOT expand tabs\n"
#define USG_MSG_ARG_LINES_PG             "\t%c%c num\t\t: use 'num' as lines per page, default %d lines\n"
#define USG_MSG_ARG_SHOW_LINES           "\t%c%c\t\t: Display Line Number\n"
#define USG_MSG_ARG_RTW                  "\t%c%c\t\t: Remove Trailing White space\n"
#define USG_MSG_ARG_JUSTLEFT             "\t%c%c\t\t: Remove Starting White space (left justify)\n"
#define USG_MSG_ARG_WHITE                "\t%c%c\t\t: Ignore White space\n"
#define USG_MSG_ARG_BOM_NO               "\t%c%c\t\t: do NOT write BOM (Byte Order Mark)\n"
#define USG_MSG_ARG_BOM_NO_1             "\t%c%c\t\t: Flag the BOM (Byte Order Mark)\n"
#define USG_MSG_ARG_BOM_W                "\t%c%c\t\t: Write BOM (Byte Order Mark) if found\n"
#define USG_MSG_ARG_COL                  "\t%c%c col\t\t: start line processing at column 'col'\n"
#define USG_MSG_ARG_COL1                 "\t%c%c col\t\t: Numeric Value is in column 'col' or at Position 'col'\n"
#define USG_MSG_ARG_MAX                  "\t%c%c max\t\t: process 'max' characters per line from start\n"
#define USG_MSG_ARG_MAX_1                "\t%c%c max\t\t: write Maximum characters per file\n"
#define USG_MSG_ARG_MIN_2                "\t%c%c min\t\t: Split file into 'min' bytes/lines per output file\n"
#define USG_MSG_ARG_MAX_2                "\t%c%c max\t\t: Split file into 'max' bytes/lines per output file\n"
#define USG_ARG_FMT_LIB                  "\t%c%c\t\t: Create a Library Response File\n"
#define USG_MSG_ARG_EXENAME              "\t%c%c file\t\t: Name of the Executable File\n"
#define USG_MSG_ARG_REPORT               "\t%c%c file\t\t: Name of the log report file\n"
#define USG_MSG_ARG_32_BIT               "\t%c%c\t\t: Format for 32 bit\n"
#define USG_MSG_ARG_ZORTECH              "\t%c%c\t\t: Format for Zortech c\n"
#define USG_MSG_ARG_START                "\t%c%c b\t\t: Start dump at byte 'b'\n"
#define USG_MSG_ARG_START_1              "\t%c%c #\t\t: Start display at line '#', default is line %ld\n"
#define USG_MSG_ARG_MAX_BYTES            "\t%c%c n\t\t: Stop dump after showing 'n' bytes\n"
#define USG_MSG_ARG_MAX_LINES            "\t%c%c n\t\t: Stop display after showing 'n' lines\n"
#define USG_MSG_ARG_LOAD_MEM             "\t%c%c\t\t: Load file data into memory, bit quicker\n\t\t\t  but could overflow\n"
#define USG_MSG_ARG_HEX                  "\t%c%c\t\t: Hexadecimal Dump (default)\n"
#define USG_MSG_ARG_OCT                  "\t%c%c\t\t: Octal Dump\n"
#define USG_MSG_ARG_DECIMAL              "\t%c%c\t\t: Decimal Dump\n"
#define USG_MSG_ARG_DECIMAL_P            "\t%c%c c\t\t: Decimal Point for Numbers, actual character OR\n"
#define USG_MSG_ARG_DECIMAL_P1           "\t\t\t  Ex: 46 = '.' or 44 = ',' or just '.' or ','\n"
#define USG_MSG_ARG_DECIMAL_PZ           "\t\t\t  If not specified, defaults to '.'\n"
#define USG_MSG_ARG_VERTICAL             "\t%c%c\t\t: Vertical display\n"
#define USG_MSG_ARG_FRONT                "\t%c%c n,n,n,...,n\t: Front Sprocket tooth count, comma seperated\n"
#define USG_MSG_ARG_REAR                 "\t%c%c n,n,n,...,n\t: Rear  Sprocket tooth count, comma seperated\n"
#define USG_MSG_ARG_WHEEL                "\t%c%c n\t\t: Wheel Size, if < 100 assume inches, > 100 assume cm\n"
#define USG_MSG_ARG_TITLE                "\t%c%c \"string\"\t: Optional Title\n"
#define USG_MSG_ARG_TITLE_1              "\t%c%c\t\t: Print Column Titles on Output (if titles exist)\n"
#define USG_MSG_ARG_TITLE_2              "\t%c%c\t\t: Print Column Headings, default No Headings\n"
#define USG_MSG_ARG_USE_PI               "\t%c%c\t\t: use PI in calculations, default is not to use PI\n"
#define USG_MSG_ARG_FORCE                "\t%c%c\t\t: force create of files when found\n"
#define USG_MSG_ARG_TEXT                 "\t%c%c\t\t: Process in text mode\n"
#define USG_MSG_ARG_TEXT_1               "\t%c%c\t\t: Split in text mode\n"
#define USG_MSG_ARG_PREFIX               "\t%c%c\t\t: Prefix Text Line with status\n"
#define USG_MSG_ARG_COUNT                "\t%c%c\t\t: prefix output with line number\n"
#define USG_MSG_ARG_COUNT_1              "\t%c%c\t\t: prefix output with number found\n"
#define USG_MSG_ARG_SHOW_NUM             "\t%c%c\t\t: Display only count of lines matched\n"
#define USG_MSG_ARG_NUMB                 "\t%c%c #\t\t: Display '#' lines, default is to display %ld lines\n"
#define USG_MSG_ARG_NUMB_1               "\t%c%c #, %c#\t: Display '#' lines, default is to display %ld lines\n"
#define USG_MSG_ARG_END_1                "\t%c%c #\t\t: End display at line '#'\n"
#define USG_MSG_ARG_STATS_ONLY           "\t%c%c\t\t: Only print File Stats\n"
#define USG_MSG_ARG_COL_CHAR_N1          "\t%c%c type,pos,size[,new_size][,format][,title]\n"
#define USG_MSG_ARG_COL_CHAR_N2          "\t\t\t: Column, type, location, size.  Type: 'c/d/n' for char,\n"
#define USG_MSG_ARG_COL_CHAR_N3          "\t\t\t  date, number.  pos can be either a column number or\n"
#define USG_MSG_ARG_COL_CHAR_N4          "\t\t\t  a field location, depending upon argument '%c%c'.\n"
#define USG_MSG_ARG_COL_CHAR_N5          "\t\t\t  More than one of these are allowed, argument order\n"
#define USG_MSG_ARG_COL_CHAR_N6          "\t\t\t  determines format of the Output File.\n"
#define USG_MSG_ARG_I_GLOBAL_HINT        "\t%c%c string\t: Input Format Hints\n"
#define USG_MSG_ARG_O_GLOBAL_HINT        "\t%c%c string\t: Output Format Hints\n"
#define USG_MSG_ARG_TRANSLATE            "\t%c%c file\t\t: Character translation File\n"
#define USG_MSG_ARG_TRANSLATE_1          "\t\t\t  Default Translate File for UTF-8 to ASCII:\n"
#define USG_MSG_ARG_TRANSLATE_2          "\t\t\t  Default Translate File for ASCII to UTF-8:\n"
#define USG_MSG_ARG_TRANSLATE_3          "\t%c%c file\t\t: Optional, character Translation File\n"
#define USG_MSG_ARG_ABORT_1              "\t%c%c\t\t: Abort process if an invalid file type is found\n"
#define USG_MSG_ARG_UTF_8_ASCII          "\t%c%c\t\t: Convert UTF-8 (UNICODE) to ASCII\n"
#define USG_MSG_ARG_UTF_8_ASCII_1        "\t%c%c\t\t: Remove all non-ASCII Characters\n"
#define USG_MSG_ARG_ASCII_UTF_8          "\t%c%c\t\t: Convert ASCII to UTF-8\n"
#define USG_MSG_ARG_EXAMINE              "\t%c%c\t\t: Examine the file, do not convert\n"
#define USG_MSG_ARG_SHOW_CONVERT         "\t%c%c file\t\t: Write convert details to file 'file'\n"
#define USG_MSG_ARG_SHOW_LEVEL_1         "\t%c%c level\t: Which conversion details to display\n"
#define USG_MSG_ARG_7BIT_FILE            "\t%c%c file\t\t: Write '7-bit' ASCII Records to 'file'\n"
#define USG_MSG_ARG_7BIT_FILE_1          "\t%c%c\t\t: Print '7-bit' ASCII characters\n"
#define USG_MSG_ARG_8BIT_FILE            "\t%c%c file\t\t: Write '8-bit' ASCII Records to 'file'\n"
#define USG_MSG_ARG_8BIT_FILE_1          "\t%c%c\t\t: Print '8-bit' ASCII (invalid) characters\n"
#define USG_MSG_ARG_UTF8_FILE            "\t%c%c file\t\t: Write 'UTF-8' Records to 'file'\n"
#define USG_MSG_ARG_UTF8_FILE_1          "\t%c%c\t\t: Print 'UTF-8' characters\n"
#define USG_MSG_ARG_UNKNOWN_FILE         "\t%c%c file\t\t: Write 'Unknown' Character Records to 'file'\n"
#define USG_MSG_ARG_UNIQ                 "\t%c%c\t\t: Show only unique lines, lines with one occurrence.\n"
#define USG_MSG_ARG_DUPS                 "\t%c%c\t\t: Show lines that occur more than once.\n"
#define USG_MSG_ARG_WIDTH                "\t%c%c width\t: process size 'width' characters per line\n"
#define USG_MSG_ARG_SHOW_FNAME           "\t%c%c\t\t: Show file name on all lines found\n"
#define USG_MSG_ARG_NO_SHOW_FNAME        "\t%c%c\t\t: Never show file name on lines found\n"
#define USG_MSG_ARG_FNAME_ONLY           "\t%c%c\t\t: Show Only File Name if match found\n"
#define USG_MSG_ARG_ONLY_LINE            "\t%c%c\t\t: show Only line # of matched lines\n"
#define USG_MSG_ARG_INVERT               "\t%c%c\t\t: Invert Match, show lines with no match\n"
#define USG_MSG_ARG_FNAME_INVERT         "\t%c%c\t\t: Invert, show only File Names with no match\n"
#define USG_MSG_ARG_MSG_NO_FILE          "\t%c%c\t\t: Do not display Open File error messages\n"
#define USG_MSG_ARG_REVERSE              "\t%c%c\t\t: Reverse, show lines in reverse order\n"
#define USG_MSG_ARG_FIRST_HEADG          "\t%c%c\t\t: First Record is a Heading\n"
#define USG_MSG_ARG_IS_CSV               "\t%c%c\t\t: Input is a csv file\n"
#define USG_MSG_ARG_FMT_CSV              "\t%c%c\t\t: Format output as a csv file\n"
#define USG_MSG_ARG_LEFT_MARGIN          "\t%c%c n\t\t: write a left margin of n spaces, default 0\n"
#define USG_MSG_ARG_MAX_SIZE             "\t%c%c n\t\t: Maximum Line Size, default no maximum\n"
#define USG_MSG_ARG_MAX_SIZE_1           "\t%c%c n\t\t: Maximum Field Size, default no maximum\n"
#define USG_MSG_ARG_MAX_VALUE            "\t%c%c n\t\t: Maximum Value\n"
#define USG_MSG_ARG_RESET                "\t%c%c\t\t: Do NOT reset page number between files\n"
#define USG_MSG_ARG_STRIP_CHARS          "\t%c%c string\t: Strip ctaracters in 'string' from field\n"
#define USG_MSG_ARG_CITY                 "\t%c%c string\t: City/Town to process\n"
#define USG_MSG_ARG_STATE                "\t%c%c XX\t\t: State abbreviation, 2 characters uppercase\n"
#define USG_MSG_ARG_IN_DIR               "\t%c%c dir\t\t: Optional, where sunrise/set tables are located\n"
#define USG_MSG_ARG_DATE                 "\t%c%c YYYYMMDD\t: Optional, use this date instead of System Date\n"
#define USG_MSG_ARG_IGNORE               "\t%c%c\t\t: Ignore character case.\n"
#define USG_MSG_ARG_IGNORE_1             "\t%c%c\t\t: Ignored, for compatibility with other Utilities\n"
#define USG_MSG_ARG_MAX_COL              "\t%c%c max\t\t: maximum number of colums to process, default %d\n"
#define USG_MSG_ARG_MOD_DATE             "\t%c%c\t\t: Show Last Modify Date/Time\n"
#define USG_MSG_ARG_ACC_DATE             "\t%c%c\t\t: Show Last Access Date/Time\n"
#define USG_MSG_ARG_CHG_DATE             "\t%c%c\t\t: Show Last Status Change Date/Time\n"
#define USG_MSG_ARG_FILE_SIZE            "\t%c%c\t\t: Show File Size in Bytes\n"

#define USG_MSG_ARG_LETTERS              "\t%c%c\t\t: Show only ASCII letters/numbers\n"
#define USG_MSG_ARG_ONLY_7BIT            "\t%c%c\t\t: Show only ASCII letters/numbers/special\n"
#define USG_MSG_ARG_ALL                  "\t%c%c\t\t: Turn all displays on\n"
#define USG_MSG_ARG_ALL_1                "\t%c%c\t\t: Process all Valid Records\n"
#define USG_MSG_ARG_BYTE                 "\t%c%c\t\t: print byte counts\n"
#define USG_MSG_ARG_BYTE_1               "\t%c%c\t\t: treat all data as 1 byte characters\n"
#define USG_MSG_ARG_EXPAND               "\t%c%c\t\t: Expand TABs to spaces\n"
#define USG_MSG_ARG_EXPAND_1             "\t%c%c n\t\t: Expand TABs to 'n' spaces, default = 8\n"
#define USG_MSG_ARG_INCLUDE_NL           "\t%c%c\t\t: print newline counts (# of records)\n"
#define USG_MSG_ARG_LONG_LEN             "\t%c%c\t\t: print length of the longest line\n"
#define USG_MSG_ARG_SHORT_LINES          "\t%c%c\t\t: print line number of the shortest line\n"
#define USG_MSG_ARG_SHORT_LEN            "\t%c%c\t\t: print length of the shortest line\n"
#define USG_MSG_ARG_WORD_COUNT           "\t%c%c\t\t: print word counts\n"
#define USG_MSG_ARG_LONG_LINES           "\t%c%c\t\t: print line number of the longest line\n"
#define USG_MSG_ARG_LIMIT_FILES          "\t%c%c num\t\t: Limit the number of files created\n"
#define USG_MSG_ARG_DEBUG_MODE           "\t%c%c\t\t: write debug information to stderr\n"
#define USG_MSG_ARG_CHANGED              "\t%c%c\t\t: output data where columns are different\n"
#define USG_MSG_ARG_MATCH_ONLY           "\t%c%c\t\t: output data that have matched records\n"
#define USG_MSG_ARG_RUNMODE              "\t%c%c mode\t\t: How to execute, valid run modes:\n"
#define USG_MSG_ARG_RUNMODE_V000         "\t%c%c mode\t\t: Force Run Mode, valid run modes (ABAP reports):\n"
#define USG_MSG_ARG_RUNMODE_V01a         "\t\t\t    ZLMR_SHOW_MM_IDOC -- Default Input Format\n"
#define USG_MSG_ARG_RUNMODE_V01b         "\t\t\t    ZFVBOMCP          -- convert from ZFVBOMCP\n"
#define USG_MSG_ARG_RUNMODE_V999         "\t\t\t    if not specified, automatically determine format\n"
#define USG_MSG_ARG_NL_ASCII             "\t%c%c\t\t: do NOT treat New Line characters as 7-bit ASCII\n"
#define USG_MSG_ARG_NOSHOW_STAT          "\t%c%c file\t\t: do NOT Print these IDOC Statuses\n"
#define USG_MSG_ARG_SHOW_STAT            "\t%c%c file\t\t: Print only these IDOC Statuses\n"
#define USG_MSG_ARG_NOSHOW_IDOC          "\t%c%c file\t\t: do NOT Print these IDOC Numbers\n"
#define USG_MSG_ARG_SHOW_IDOC            "\t%c%c file\t\t: Print only these IDOC Numbers\n"
#define USG_MSG_ARG_NOSHOW_MATNR         "\t%c%c file\t\t: do NOT Print these Materials\n"
#define USG_MSG_ARG_NOSHOW_MATNR_1       "\t%c%c file|matnr\t: do NOT Print these Material(s)\n"
#define USG_MSG_ARG_SHOW_MATNR           "\t%c%c file\t\t: Print only these Materials\n"
#define USG_MSG_ARG_SHOW_MATNR_1         "\t%c%c file|matnr\t: Print only these Material(s)\n"
#define USG_MSG_ARG_PRINT_UTF8           "\t%c%c\t\t: Print 'real' UTF-8 character instead of '*'\n"
#define USG_MSG_ARG_ITERATIONS           "\t%c%c n\t\t: Iterations for overwrites\n"
#define USG_MSG_ARG_ITERATIONS_1         "\t%c%c n\t\t: Pause after processing 'n' Objects\n"
#define USG_MSG_ARG_KEEP                 "\t%c%c\t\t: do NOT translate valid UTF-8 characters\n"
#define USG_MSG_ARG_KEEP_1               "\t%c%c\t\t: do NOT replace non-ASCII characters\n"
#define USG_MSG_ARG_PAUSE                "\t%c%c n\t\t: Pause for 'n' microseconds\n"
#define USG_MSG_ARG_PRT_FORMAT           "\t%c%c c\t\t: Optional Output Format, where 'c' is:\n"
#define USG_MSG_ARG_PRT_FORMAT_A_DEG     "\t\t\t    'a' = '32.00'\n"
#define USG_MSG_ARG_PRT_FORMAT_B_DEG     "\t\t\t    'b' = '32'\n"
#define USG_MSG_ARG_PRT_FORMAT_C_DEG     "\t\t\t    'c' = '32.00x'  (x = Degree Unit)\n"
#define USG_MSG_ARG_PRT_FORMAT_D_DEG     "\t\t\t    'd' = '32x'     (x = Degree Unit)\n"
#define USG_MSG_ARG_PRT_FORMAT_E_DEG     "\t\t\t    'e' = '32.00x'  (x = Degree Unit)\n"
#define USG_MSG_ARG_PRT_FORMAT_F_DEG     "\t\t\t    'f' = '32x'     (x = Degree Unit)\n"
#define USG_MSG_ARG_PRT_FORMAT_Z_DEG     "\t\t\t  Default show verbose Output\n"
#define USG_MSG_ARG_PRT_FORMAT_A_SUN     "\t%c%c c\t\t: Optional Output Format, where 'c' is the format type.\n"
#define USG_MSG_ARG_PRT_FORMAT_Z_SUN     "\t\t\t  See manual for details (too many to list here).\n"
#define USG_MSG_ARG_ADD_SPACE            "\t%c%c\t\t: write a space instead of an empty value\n"
#define USG_MSG_ARG_SHOW_NONASCII        "\t%c%c\t\t: Show only non-ASCII Lines\n"
#define USG_MSG_ARG_NUMB_FIX             "\t%c%c\t\t: Correct Number Format\n"
#define USG_MSG_ARG_DAYLIGHT             "\t%c%c mm\t\t: Force datlight savings for display\n"
#define USG_MSG_ARG_DETAIL_RPT           "\t%c%c\t\t: Print Detail Report\n"
#define USG_MSG_ARG_NO_RPT               "\t%c%c\t\t: Do NOT create a Report\n"
#define USG_MSG_ARG_TEXT_COL             "\t%c%c n,n,n,n,...\t: Treat columns 'n' as text (0 = all Text)\n"

#define USG_MSG_ARG_LIST_MODE        "\t%c%c 1|2\t\t: Base output on FILE1 (1) or FILE2 (2)\n"
#define USG_MSG_ARG_FAHR             "\t%c%c\t\t: Convert from degrees Fahrenheit\n"
#define USG_MSG_ARG_CENT             "\t%c%c\t\t: Convert from degrees Centigrade\n"
#define USG_MSG_ARG_KELV             "\t%c%c\t\t: Convert from degrees Kelvin\n"
#define USG_MSG_ARG_RANK             "\t%c%c\t\t: Convert from degrees Rankine\n"
#define USG_MSG_ARG_TIMEOUT          "\t%c%c n\t\t: Default Global Timeout for xmessage\n"
#define USG_MSG_ARG_UNSORTED         "\t%c%c\t\t: Data is unsorted, use slow option\n"
#define USG_MSG_ARG_PRINT_FEED       "\t%c%c\t\t: Print a form feed between pages\n"
#define USG_MSG_ARG_INTEREST         "\t%c%c num\t\t: Interest Rate\n"
#define USG_MSG_ARG_PRINCIPAL        "\t%c%c num\t\t: Principal Amount\n"
#define USG_MSG_ARG_YEARS            "\t%c%c num\t\t: Number of Years\n"

#define USG_MSG_ARG_OUT_FMT_DH       "\t%c%c n\t\t: Print the date using format 'n' where 'n' is:\n"
#define USG_MSG_ARG_OUT_FMT_D0       "\t\t\t    %d  Use Format YYYYMMDD \n"
#define USG_MSG_ARG_OUT_FMT_D1       "\t\t\t    %d  Use Format YYYY/MM/DD \n"
#define USG_MSG_ARG_OUT_FMT_D2       "\t\t\t    %d  Use Format YYYY-MM-DD \n"
#define USG_MSG_ARG_OUT_FMT_D3       "\t\t\t    %d  Use Format MM/DD/YYYY \n"
#define USG_MSG_ARG_OUT_FMT_D4       "\t\t\t    %d  Use Format DD-MM-YYYY \n"

#define USG_MSG_ARG_DATE_LOW         "\t%c%c date\t\t: Low Date Value for Range Print.\n"
#define USG_MSG_ARG_DATE_MAX         "\t%c%c date\t\t: Maximum (High) Date for Date Range Print.\n"
#define USG_MSG_ARG_SLEEP            "\t%c%c s\t\t: Sleep 's' seconds between iterations.\n"
#define USG_MSG_ARG_MIN_VALUE        "\t%c%c n\t\t: Minumum Value\n"
#define USG_MSG_ARG_MOST             "\t%c%c n\t\t: Print no more than 'n' entries\n"

#endif  /* J_LIB2M_H */
