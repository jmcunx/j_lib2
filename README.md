## jmc Library

github has no option to select the ISC license.<br>
**This is licensed using the [ISC Licence](https://en.wikipedia.org/wiki/ISC_license).**

Objects in this library goes back decades, some started out on MS-DOS
and a little known Unix called IN/ix (a 16 but Unix on a proprietary
8086 clone).

To build, execute gen_make.sh to generate a Makefile for most
BSD/Linux systems and IBM AIX.  makefile.dos can be used for MS-DOS
Systems under Microsoft c.

[GNU automake](https://en.wikipedia.org/wiki/Automake)
only confuses me, so I came up with my own method which
is a real hack.  But works for me.

Objects included and a brief description:

* j2_bye_emb(3) -- remove embedded white space
* j2_bye_last(3) -- remove 'last' character on a string
* j2_chg_char(3) -- change a specific character
* j2_clr_str(3) -- clear a string and append NULL
* j2_count_c(3) -- get count of a specific character
* j2_date_is_valid(3) -- Validate Date String
* j2_d_get_yyyy(3) -- Determine the 4 digit year
* j2_d_init(3) -- Initialize Date/Time structure
* j2_d_isleap(3) -- Is the year a Leap Year ?
* j2_dl_fmt(3) -- Format a Date/Time Integer Value for Display
* j2_dl_split(3) -- Split a Date/Time Integer Value
* j2_dl_valid(3) -- Validate Date/Time Integer Value
* j2_ds_fmt(3) -- Format a Date/Time String for Display
* j2_ds_split(3) -- Split a Date/Time string
* j2_d_to_sec(3) -- Converts a date to the # of seconds 
* j2_expand_tab(3) -- Expand tabs to spaces in a string
* j2_f_exist(3) -- see if a file exists
* j2_file_typ(3) -- determine file type
* j2_fix_numr(3) -- fix number format
* j2_get_build(3) -- Returns a string with Library Build Date
* j2_get_prgname(3) -- get program name from argv
* j2_getseed(3) -- Get a seed value for rand()
* j2_is_all_spaces(3) -- is a string all white space ?
* j2_is_numr(3) -- Is the string all numeric ?
* j2_is_space_embedded(3) -- Does a string any embedded white space ?
* j2_justleft(3) -- left justifies a string
* j2_randrange(3) -- Get a random number between an Integer Range
* j2_rtw(3) -- remove trailing white space
* j2_secs_to_str(3) -- Converts seconds to a "run time" string
* j2_strlwr(3) -- change a string to all lower case
* j2_str_to_secs(3) -- Converts a "run time" string to Seconds
* j2_strupr(3) -- change a string to upper case
* j2_today(3) -- get current system date/time

