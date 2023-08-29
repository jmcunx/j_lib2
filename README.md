## jmc Library

**Note:** Starting October 12 2023, GitHub is forcing me to use
my Cell Phone for 2FA to allow access to my repositories.  I do
not want Microsoft to have access to my phone.  So updates to
this project will no longer occur on GitHub.  I will make a note
of where source can be retrieved from on my Gemini Capsule once
everything is moved off of GitHub.
Capsule: gemini://gem.sdf.org/jmccue/ or mirror gemini://sdf.org/jmccue/

Objects in this library goes back decades, some started out on MS-DOS
and a little known Unix called IN/ix (a 16 but Unix on a proprietary
8086 clone).

To build, execute gen\_make.sh to generate a Makefile for most
BSD/Linux systems and IBM AIX.  makefile.dos can be used for MS-DOS
Systems under Microsoft c.

[GNU automake](https://en.wikipedia.org/wiki/Automake)
only confuses me, so I came up with my own method which
is a real hack.  But works for me.

Objects included and a brief description:

* j2\_bye\_emb(3) -- remove embedded white space
* j2\_bye\_last(3) -- remove 'last' character on a string
* j2\_chg\_char(3) -- change a specific character
* j2\_clr\_str(3) -- clear a string and append NULL
* j2\_count\_c(3) -- get count of a specific character
* j2\_date\_is\_valid(3) -- Validate Date String
* j2\_d\_get\_yyyy(3) -- Determine the 4 digit year
* j2\_d\_init(3) -- Initialize Date/Time structure
* j2\_d\_isleap(3) -- Is the year a Leap Year ?
* j2\_dl\_fmt(3) -- Format a Date/Time Integer Value for Display
* j2\_dl\_split(3) -- Split a Date/Time Integer Value
* j2\_dl\_valid(3) -- Validate Date/Time Integer Value
* j2\_ds\_fmt(3) -- Format a Date/Time String for Display
* j2\_ds\_split(3) -- Split a Date/Time string
* j2\_d\_to\_sec(3) -- Converts a date to the # of seconds 
* j2\_expand\_tab(3) -- Expand tabs to spaces in a string
* j2\_f\_exist(3) -- see if a file exists
* j2\_file\_typ(3) -- determine file type
* j2\_fix\_numr(3) -- fix number format
* j2\_get\_build(3) -- Returns a string with Library Build Date
* j2\_get\_prgname(3) -- get program name from argv
* j2\_getseed(3) -- Get a seed value for rand()
* j2\_is\_all\_spaces(3) -- is a string all white space ?
* j2\_is\_numr(3) -- Is the string all numeric ?
* j2\_is\_space\_embedded(3) -- Does a string contain any embedded white space ?
* j2\_justleft(3) -- Left Justifies a string
* j2\_randrange(3) -- Get a random number between an Integer Range
* j2\_rtw(3) -- Remove Trailing White Space
* j2\_secs\_to\_str(3) -- Converts seconds to a "run time" string
* j2\_strlwr(3) -- change a string to all lower case
* j2\_str\_to\_secs(3) -- Converts a "run time" string to Seconds
* j2\_strupr(3) -- change a string to upper case
* j2\_today(3) -- get current system date/time

* man\_tr.txt -- Used to install Manuals on various Operating Systems
* makefile.dos -- Microsoft c Makefile for nmake
* clibopt.txt -- Microsoft c Linker Response File, Compact Model
* hlibopt.txt -- Microsoft c Linker Response File, Hugh Model
* llibopt.txt -- Microsoft c Linker Response File, Large Model
* mlibopt.txt -- Microsoft c Linker Response File, Medium Model
* slibopt.txt -- Microsoft c Linker Response File, Small Model
* tlibopt.txt -- Microsoft c Linker Response File, Tiny Model
