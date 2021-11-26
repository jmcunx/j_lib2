#!/bin/sh
#
############################################################################
# Copyright (c) 2011 2012 2013 2014 2015 2016 2017 2018 
#     John McCue <jmccue@jmcunx.com>
# 
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
# 
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
############################################################################
#
# generate a Makefile for librart j_lib2 on UN*X Type Systems
#
# cheap configuration to generate a Makefile.
# Autoconfig still confuses me, and this is for
# a simple utility anyway.
#
# see messages
#  grep '[EIWS][0-9]' gen_make.sh | grep -v '$si_name' | grep -v '^#' | sed 's/"//g;s/emsg=//;s/showhelp //' | rtw -J | sed 's/^echo//' | rtw -J | grep -v grep  | rtw -J | sort
#

if test -r /etc/os-release
then
    . /etc/os-release
fi

#------------------------------------------------------------------------------
# showhelp() -- display help
#------------------------------------------------------------------------------
showhelp()
{
    msg="$1"

cat << EOF
$sname
Generate a Makefile for specific UN*X Systems.

Arguments, there is only 1 argument:
    [Y|N] -- Build the object with long help.
             For some objects this is ignored.

Environment Variables:
    \$CC      : Which c compiler to use. Ex: cc or gcc or clang
    \$OS      : Force a build for a specfic OS, default: `uname -s`
    \$PREFIX  : Used to determine were the binaries and man files 'should'
               be installed.  If not set the default will be /usr/local
    \$DESTDIR : Used to determine were the binaries and man files will 
               be installed.  If not set the default will be /usr/local
               This can be different that \$PREFIX if you want to 
               install to a different directory.  Useful if you want 
               to build a binary tarball (package).
    \$SHARED  : If set to 'N', shared libraries will NOT be build.
               Default is to build Shared Libraries (.so)
               Note, due to my access on AIX, shared libs are never built.
If the above is not set, they will be determined
automatically.
EOF

    if test "$msg" != ""
    then
	echo ''
	echo "$msg"
    fi

} # END: showhelp()

#------------------------------------------------------------------------------
# gen_modl() -- generate build section
#------------------------------------------------------------------------------
gen_modl()
{
    echo ''
    echo '#------------------------------------------------------------------------------'
    echo "# Module Build for $OS"
    echo '#------------------------------------------------------------------------------'

    for uf in *.c
    do
	bname=`echo $uf | sed 's/\.c$//'`
	echo "$bname\$(OBJ):	$bname.c \$(ALL_H)"
	echo "	\$(CC) \$(CFLAGS) $bname.c"
	echo ''
    done

} # END: gen_modl

#------------------------------------------------------------------------------
# gen_install() -- generate install section
#------------------------------------------------------------------------------
gen_install()
{
    genins_read=""
    genins_man=""

    if test "$all_read" != ""
    then
	    genins_read="instread"
    fi

    genins_man="instman"

    #--- readme files
    if test "$genins_read" != ""
    then
	echo 'instread:	all'
	for uf in `echo $all_read`
	do
	    if test -f "$uf"
	    then
		echo "	$oinstall \$(OWNER) \$(GROUP) 644 \$(READINS)     $uf N"
	    fi
	done
    fi

    #--- Manuals
    if test "$genins_man" != ""
    then
	echo 'instman:	man'
	for uman in `ls *.man | sed 's/\.man$//'`
	do
	    uman_out=`grep "^$uman" < "$man_tr" | awk 'BEGIN{FS="|"}{print $2}'`
	    if test "$uman_out" = ""
	    then
		uman_out="$uman"
	    fi
	    if test "$gzip_man" = "Y"
	    then
		echo "$uman_out" \
			| awk '{printf("\tZXZXZX $(OWNER) $(GROUP) 644 $(PRODMAN) %s$(MAN_EXT)$(GZ) N\n",$1)}' \
			| sed "s%ZXZXZX%$oinstall%"
	    else
		echo "$uman_out" \
			| awk '{printf("\tZXZXZX $(OWNER) $(GROUP) 644 $(PRODMAN) %s$(MAN_EXT) N\n",$1)}' \
			| sed "s%ZXZXZX%$oinstall%"
	    fi
	done
    fi
    echo ''

    #--- libraries / includes
    echo 'instbin:	all'
    echo "	$oinstall \$(OWNER) \$(GROUP) 644 \$(PRODUCTION)/include  j_lib2.h N"
    echo "	$oinstall \$(OWNER) \$(GROUP) 644 \$(PRODUCTION)/include  j_lib2m.h N"
    echo "	$oinstall \$(OWNER) \$(GROUP) 644 \$(PRODUCTION)/\$(INST_LIB) libj_lib2\$(LIB_EXT) N"
    if test "$need_shared" = "Y"
    then
	echo "	$oinstall \$(OWNER) \$(GROUP) 644 \$(PRODUCTION)/\$(INST_LIB) libj_lib2\$(SO_EXT) N"
	if test -f "/etc/redhat-release"
	then
	    echo '	-chcon -t textrel_shlib_t $(PRODUCTION)/$(INST_LIB)/libj_lib2$(SO_EXT)'
	else
	    if test -f "/etc/centos-release"
	    then
		echo '	-chcon -t textrel_shlib_t $(PRODUCTION)/$(INST_LIB)/libj_lib2$(SO_EXT)'
	    fi
	fi
    fi
    echo ''

    #--- install all
    echo "install:	instbin $genins_man $genins_read"
    echo "	@echo DONE"

} # END: gen_install()

#------------------------------------------------------------------------------
# gen_build() -- generate build section
#------------------------------------------------------------------------------
gen_build()
{
    echo ''
    echo '#------------------------------------------------------------------------------'
    echo "# Build for $OS"
    echo '#------------------------------------------------------------------------------'

    if test "$need_shared" = "Y"
    then
	if test "$build_man" = "Y"
	then
	    echo 'all:	libj_lib2$(LIB_EXT) $(LIB_SHARED) man tags'
	else
	    echo 'all:	libj_lib2$(LIB_EXT) $(LIB_SHARED) tags'
	fi
    else
	if test "$build_man" = "Y"
	then
	    echo 'all:	libj_lib2$(LIB_EXT) man tags'
	else
	    echo 'all:	libj_lib2$(LIB_EXT) tags'
	fi
    fi

    echo ''

    echo 'libj_lib2$(LIB_EXT):	$(ALL_OBJ)'
    echo '	$(AR) rv libj_lib2$(LIB_EXT) $(ALL_OBJ)'
    echo '	$(RANLIB) libj_lib2$(LIB_EXT)'
    echo ''

    echo '$(LIB_SHARED):	$(ALL_OBJ)'
    echo '	-$(RM) libj_lib2$(SO_EXT)'
    echo '	$(LD) $(LDFLAGS) -o libj_lib2$(SO_EXT) $(ALL_OBJ)'
    echo ''

    echo 'tags:	 $(ALL_C) $(ALL_H)'
    echo '	-$(CTAGS)  $(ALL_C) $(ALL_H) > /dev/null 2>&1'

    type etags > /dev/null 2>&1
    if test "$?" -eq "0"
    then
	echo '	-$(ETAGS)  $(ALL_C) $(ALL_H)'
    fi
    echo ''

    gen_install
    echo ''

    echo 'clean:'
    echo '	-$(RM) *$(OBJ)'
    echo '	-$(RM) *$(LST)'
    echo '	-$(RM) *$(MAN_EXT)'
    echo '	-$(RM) *$(MAN_EXT)$(GZ)'
    echo '	-$(RM) libj_lib2$(LIB_EXT)'
    echo '	-$(RM) libj_lib2$(SO_EXT)'
    echo '	-$(RM) tags'
    echo '	-$(RM) TAGS'
    echo '	-$(RM) core'
    echo '	-$(RM) *.core'
    echo '	-$(RM) a.out'
    echo '	-$(RM) *.pdb'
    echo '	-$(RM) *.ilk'
    echo "	-\$(RM) $ofile"
    echo "	-\$(RM) $bufile"
    echo "	-\$(RM) $oinstall"
    echo "	-\$(RM) $linstall"
    echo '	-$(RM)  Makefile.coh'
    echo '	-$(RM)  coh_man.sh'
    echo ''

}  # END: gen_build()

#------------------------------------------------------------------------------
# gen_mlink() -- set install variables
#------------------------------------------------------------------------------
gen_mlink()
{
    echo '#!/bin/sh'
    echo '###############################################################################'
    echo "# makelink  -- Created `date`"
    echo "#              by:     $sname"
    echo '#------------------------------------------------------------------------------'
    echo '#    symbolic link some files'
    echo '###############################################################################'
    echo ''
    echo 'si_name=$0'
    echo 'ODIR=$1'
    echo 'IFILE=$2'
    echo 'OFILE=$3'
    echo 'export OWNER GROUP MOD OBJ ODIR STRIP'
    echo ''
    echo 'umask 022'
    echo ''
    echo 'if test "$OS" = ""'
    echo 'then'
    echo '    OS=`uname -n`'
    echo 'fi'
    echo ''
    echo 'if test "$ODIR" = ""'
    echo 'then'
    echo '    echo "ERROR   E71: $si_name Arg 1, Out Dir, missing"'
    echo '    exit 2'
    echo 'fi'
    echo 'if test "$IFILE" = ""'
    echo 'then'
    echo '    echo "ERROR   E72: $si_name Arg 2, in file, missing"'
    echo '    exit 2'
    echo 'fi'
    echo 'if test "$OFILE" = ""'
    echo 'then'
    echo '    echo "ERROR   E73: $si_name Arg 3, Out File, missing"'
    echo '    exit 2'
    echo 'fi'
    echo ''
    echo 'if test ! -f "$IFILE"'
    echo 'then'
    echo '   echo "ERROR   E74: $si_name object $IFILE missing"'
    echo '   exit 2'
    echo 'fi'
    echo ''
    echo 'if test ! -d "$ODIR"'
    echo 'then'
    echo '   echo "ERROR   E75: $si_name $ODIR missing"'
    echo '   exit 2'
    echo 'fi'
    echo ''
    echo 'if test ! -f "$ODIR/$IFILE"'
    echo 'then'
    echo '   echo "ERROR   E76: $si_name $ODIR/$IFILE missing"'
    echo '   exit 2'
    echo 'fi'
    echo ''
    echo 'cd $ODIR'
    echo 'ln -sf $IFILE $OFILE'
    echo 'if test "$?" -ne "0"'
    echo 'then'
    echo '   echo "ERROR   E77: $si_name ln $IFILE -> $OFILE aborted"'
    echo '   exit 2'
    echo 'fi'
    echo ''
    echo 'echo "SUCCESS S78: $si_name ln $IFILE -> $OFILE"'
    echo 'exit 0'

} # END: gen_mlink()

#------------------------------------------------------------------------------
# gen_minst() -- set install variables
#------------------------------------------------------------------------------
gen_minst()
{
    echo '#!/bin/sh'
    echo '###############################################################################'
    echo "# install  -- Created `date`"
    echo "#             by:     $sname"
    echo '#------------------------------------------------------------------------------'
    echo '#    install(1) does not work exactly like I would like it to'
    echo '#    so this temp script will be used instead'
    echo '###############################################################################'
    echo ''
    echo 'si_name=$0'
    echo 'OWNER=$1'
    echo 'GROUP=$2'
    echo 'MOD=$3'
    echo 'ODIR=$4'
    echo 'OBJ=$5'
    echo 'STRIP=$6'
    echo 'export OWNER GROUP MOD OBJ ODIR STRIP'
    echo ''
    echo 'umask 022'
    echo ''
    echo 'if test "$OS" = ""'
    echo 'then'
    echo '    OS=`uname -n`'
    echo 'fi'
    echo ''
    echo 'if test "$OWNER" = ""'
    echo 'then'
    echo '    echo "ERROR   E81: $si_name Arg 1, owner, missing"'
    echo '    exit 2'
    echo 'fi'
    echo 'if test "$GROUP" = ""'
    echo 'then'
    echo '    echo "ERROR   E82: $si_name Arg 2, group, missing"'
    echo '    exit 2'
    echo 'fi'
    echo 'if test "$OBJ" = ""'
    echo 'then'
    echo '    echo "ERROR   E83: $si_name Arg 3, object, missing"'
    echo '    exit 2'
    echo 'fi'
    echo 'if test "$ODIR" = ""'
    echo 'then'
    echo '    echo "ERROR   E84: $si_name Arg 4, out directory, missing"'
    echo '    exit 2'
    echo 'fi'
    echo ''
    echo 'if test ! -f "$OBJ"'
    echo 'then'
    echo '   echo "ERROR   E85: $si_name object $OBJ missing"'
    echo '   exit 2'
    echo 'fi'
    echo ''
    echo 'if test "$MOD" = ""'
    echo 'then'
    echo '   echo "ERROR   E86: $si_name protection $MOD missing"'
    echo '   exit 2'
    echo 'fi'
    echo ''
    echo 'if test -f "$ODIR/$OBJ"'
    echo 'then'
    echo '    cmp $OBJ $ODIR/$OBJ > /dev/null 2>&1'
    echo '    if test "$?" -eq "0"'
    echo '    then'
    echo '       echo "INFO    I89: $si_name $ODIR/$OBJ did not change, bypassing"'
    echo '       exit 0'
    echo '    fi'
    echo 'fi'
    echo ''
    echo 'if test ! -d "$ODIR"'
    echo 'then'
    echo '    mkdir -m 755 -p $ODIR'
    echo '    if test "$?" -ne "0"'
    echo '    then'
    echo '       echo "ERROR   E88: $si_name cannot created dir $ODIR"'
    echo '       exit 2'
    echo '    fi'
    echo 'fi'
    echo ''
    echo 'cp $OBJ $ODIR/$OBJ'
    echo 'if test "$?" -eq "0"'
    echo 'then'
    echo '   echo "SUCCESS S91: $si_name cp $OBJ -> $ODIR"'
    echo 'else'
    echo '   echo "ERROR   E87: $si_name cp $OBJ -> $ODIR aborted"'
    echo '   exit 2'
    echo 'fi'
    echo ''
    echo 'if test "$STRIP" = "Y"'
    echo 'then'
    echo '   strip $ODIR/$OBJ'
    echo 'fi'
    echo ''
    echo 'chown $OWNER $ODIR/$OBJ > /dev/null 2>&1'
    echo 'if test "$?" -ne "0"'
    echo 'then'
    echo '   echo "WARN    W92: $si_name chown $OWNER $ODIR/$OBJ failed, continue"'
    echo 'fi'
    echo ''
    echo 'chgrp $GROUP $ODIR/$OBJ > /dev/null 2>&1'
    echo 'if test "$?" -ne "0"'
    echo 'then'
    echo '   echo "WARN    W93: $si_name chgrp $GROUP $ODIR/$OBJ failed, continue"'
    echo 'fi'
    echo ''
    echo 'chmod $MOD   $ODIR/$OBJ > /dev/null 2>&1'
    echo 'if test "$?" -ne "0"'
    echo 'then'
    echo '   echo "WARN    W94: $si_name chmod $MOD $ODIR/$OBJ failed, continue"'
    echo 'fi'
    echo ''

    echo '#--- set links for various manuals'
    echo 'iman=""'
    echo 'inew=""'
    echo 'ibase=`echo "$OBJ" | awk %{FS="."}{print $1}%`'  | sed "s/%/'/g"
    echo 'iextn=`echo "$OBJ" | awk %{FS="."}{print $NF}%`' | sed "s/%/'/g"
    echo 'case "$ibase" in'
    echo '    "j2_ds_fmt")'
    echo '	iman="$OBJ"'
    echo '	inew="j2_dl_fmt"'
    echo '	;;'
    echo '    "j2_date_is_valid")'
    echo '	iman="$OBJ"'
    echo '	inew="j2_dl_valid"'
    echo '	;;'
    echo '    "j2_ds_split")'
    echo '	iman="$OBJ"'
    echo '	inew="j2_dl_split"'
    echo '	;;'
    echo 'esac'
    echo 'if test "$iman" != ""'
    echo 'then'
    echo '    case "$iextn" in'
    echo '	"3")'
    echo '	    inew="$inew.3"'
    echo '	    ;;'
    echo '	"gz")'
    echo '	    inew="$inew.3.gz"'
    echo '	    ;;'
    echo '	"bz2")'
    echo '	    inew="$inew.3.bz2"'
    echo '	    ;;'
    echo '	"xz")'
    echo '	    inew="$inew.3.xz"'
    echo '	    ;;'
    echo '	*)'
    echo '	    inew=""'
    echo '	    ;;'
    echo '    esac'
    echo '    cd "$ODIR"'
    echo '    if test "$inew" != ""'
    echo '    then'
    echo '        ln -sf "$OBJ" "$inew"'
    echo '    fi'
    echo 'fi'

    echo ''
    echo 'echo "SUCCESS S90: $si_name $ODIR/$OBJ installed"'
    echo 'exit 0'

} # END: gen_minst()

#------------------------------------------------------------------------------
# gen_m01() -- Generate first part of the Makefile
#              global settings
#------------------------------------------------------------------------------
gen_m01()
{
    echo '###############################################################################'
    echo "# Makefile -- Created `date`"
    echo "#             by:     $sname"
    echo '###############################################################################'

    echo 'SHELL=/bin/sh'
    echo ''

    echo '#--- REAL_DIR is where the source is expected to be installed incase'
    echo '#             there are config files'
    echo '#    DESTDIR  is where to install so a package can be created'
    echo "REAL_DIR=$PREFIX"
    echo "DESTDIR=$DESTDIR"
    echo "PRODUCTION=\$(DESTDIR)"
    echo 'PRODMAN=$(DESTDIR)/man/man3'
    echo 'READINS=$(DESTDIR)/share/j_lib2'
    echo ''
    echo "OSDESC=$uostype"
    echo ''

    echo 'LIB_EXT=.a'
    echo 'SO_EXT=.so'

    if test "$IS_BSD" = "Y"
    then
	echo 'IS_BSD=-DIS_BSD_YES'
    else
	echo 'IS_BSD=-DIS_BSD_NO'
    fi

    if test "$need_shared" = "Y"
    then
	echo 'LIB_SHARED=libj_lib2$(SO_EXT)'
    fi

    if test "$use_owner" != ""
    then
	echo "OWNER=$use_owner"
	echo "GROUP=$use_group"
    else
	echo 'OWNER='
	echo 'GROUP='
    fi

    if test "$is_unix" = "Y"
    then
	echo 'ISUNIX=-DUNIX'
    fi
    echo ''

    echo 'AR=ar'
    echo 'CAT=cat'
    echo "CC=$CC"
    echo 'CD=cd'
    echo 'CHMOD=chmod'
    echo 'CP=cp'
    echo "CTAGS=$ctagprog"
    echo 'ECHO=echo'
    echo 'ETAGS=etags'
    echo 'GZIP=gzip'

    if test "$fix__guard_local" = "Y"
    then
	#--- this fixes __guard_local error on OpenBSD
	echo 'LD=cc'
    else
	echo 'LD=ld'
    fi

    echo 'LN=ln'
    echo 'MKDIR=mkdir'
    echo 'MV=mv'
    echo 'NROFF=nroff -man'
    echo 'RANLIB=ranlib'
    echo 'RM=rm -f'
    echo 'SED=sed'
    echo 'STRIP=strip'
    echo 'TOUCH=touch'
    echo ''
    echo 'OBJ=.o'
    echo 'EXE='
    echo 'GZ=.gz'
    echo 'LST=.lst'
    echo 'MAN_EXT=.3'
    echo "INST_LIB=$install_lib"

    if test "$use_64" = "Y"
    then
	case "$OS" in
	    "FreeBSD")
		use_fpic="-fPIC"
		;;
	    "NetBSD")
		use_fpic="-fPIC"
		;;
	    "Linux")
		use_fpic="-fPIC"
		;;
	    *)
		unset use_fpic
		;;
	esac
    else
	case "$OS" in
	    "NetBSD")
		use_fpic="-DPIC -fPIC"
		;;
	    "OpenBSD")
		use_fpic="-DPIC -fPIC"
		;;
	    *)
		unset use_fpic
		;;
	esac
    fi

    if test "$gcc" = "Y"
    then
	echo 'GNU_UNIX=-DGNU_UNIX'
	if test "$use_64" = "Y"
	then
	    echo "WALL=-Wall -m64 $use_fpic"
	else
	    echo "WALL=-Wall $use_fpic"
	fi
    else
	echo "GNU_UNIX="
	if test "$IS_BSD" = "Y"
	then
	    echo "WALL=$use_fpic -Wall"
	else
	    echo "WALL=$use_fpic"
	fi
    fi

    #--- compress manual ?
    type gzip > /dev/null 2>&1
    if test "$?" -eq "0"
    then
	echo 'CNROFF=.gz'
    fi

    #--- what to compile and build options
    echo ''
    echo $all_c | sed 's/ /$(OBJ) /g' | sed 's/$/$(OBJ)/g' | sed 's/^/ALL_OBJ=/'
    echo $all_c | sed 's/ /.c /g'     | sed 's/$/.c/g'     | sed 's/^/ALL_C=/'

    if test "$all_h" != ""
    then
	echo $all_h | sed 's/^/ALL_H=/'
    fi

    echo ''
    echo 'CFLAGS=-c -O $(WALL) $(GNU_UNIX) $(NEED_BASENAME) $(IS_BSD) $(NEED_DIRNAME) $(ISUNIX) -DOSTYPE="\"$(OSDESC)\""'
    if test "$fix__guard_local" = "Y"
    then
	#--- this fixes __guard_local error on OpenBSD
	echo 'LDFLAGS=-fPIC -shared'
    else
	echo 'LDFLAGS=-shared'
    fi

} # END: gen_m01()

#------------------------------------------------------------------------------
# gen_mman() -- generate manual protion
#------------------------------------------------------------------------------
gen_mman()
{
    echo '#------------------------------------------------------------------------------'
    echo '# Generate build Manuals'
    echo '#------------------------------------------------------------------------------'

    if test "$gzip_man" = "Y"
    then
	ls *.man               \
	    | sed 's/\.man//'  \
	    | awk 'BEGIN{printf("man:\t")}{printf(" %s$(MAN_EXT)$(GZ)",$1)}END{printf("\n")}'
    else
	ls *.man               \
	    | sed 's/\.man//'  \
	    | awk 'BEGIN{printf("man:\t")}{printf(" %s$(MAN_EXT)",$1)}END{printf("\n")}'
    fi

    echo '	$(ECHO) Manuals built'
    echo ''

    for uman in `ls *.man | sed 's/\.man//'`
    do
	uman_out=`grep "^$uman" < "$man_tr" | awk 'BEGIN{FS="|"}{print $2}'`
	if test "$uman_out" = ""
	then
	    uman_out="$uman"
	fi
	if test "$gzip_man" = "Y"
	then
	    echo "$uman\$(MAN_EXT)\$(GZ):	$uman.man"
	else
	    echo "$uman\$(MAN_EXT):	$uman.man"
	fi
	if test "$gzip_man" = "Y"
	then
	    if test "$need_nroff" = "Y"
	    then
		echo "	\$(NROFF) $uman.man | \$(GZIP) -c > $uman_out\$(MAN_EXT)\$(GZ)"
	    else
		echo "	\$(GZIP) -c $uman.man > $uman_out\$(MAN_EXT)\$(GZ)"
	    fi
	else
	    if test "$need_nroff" = "Y"
	    then
		echo "	\$(NROFF) $uman.man > $uman_out\$(MAN_EXT)"
	    else
		echo "	\$(CAT) $uman.man > $uman_out\$(MAN_EXT)"
	    fi
	fi
	echo ''
    done

} # END: gen_mman()

###############################################################################
# setup
###############################################################################
sname="$0"

ofile="Makefile"
bufile="Makefile"~
oinstall="./install.sh"
linstall="./install_link.sh"
man_tr="man_tr.txt"
fix__guard_local="N"

case "$1" in
    "--help"|"-help"|"--h"|"-h"|"h"|"help")
	showhelp
	exit 2
	;;
    "Y")
	;;
    "")
	;;
    *)
	showhelp "ERROR E03: $1 is an invalud argument"
	exit 2
	;;
esac

if test "$OS" = ""
then
    OS=`uname -s`
    export OS
fi

#--- Exuberant Ctags could be exctags or ectags
if test -x "/usr/local/bin/exctags"
then
    ctagprog="/usr/local/bin/exctags"
else
    if test -x "/usr/pkg/bin/exctags"
    then
	ctagprog="/usr/pkg/bin/exctags"
    else
	if test -x "/usr/local/bin/ectags"
	then
	    ctagprog="/usr/local/bin/ectags"
	else
	    if test -x "/usr/pkg/bin/ectags"
	    then
		ctagprog="/usr/pkg/bin/ectags"
	    else
		ctagprog="ctags"
	    fi
	fi
    fi
fi

#------------------------------------------------------------------------------
# set OS name string and which cc to use
#------------------------------------------------------------------------------
case "$OS" in
    "FreeBSD")
	IS_BSD="Y"
	uostype=`uname -srp`
	if test "$CC" = ""
	then
	    CC=gcc
	    export CC
	    gcc="Y"
	else
	    case "$CC" in
		"gcc"|"cc")
		    gcc="Y"
		    ;;
		*)
		    gcc="N"
		    ;;
	    esac
	fi
	;;
    "NetBSD")
	IS_BSD="Y"
	uostype=`uname -srp`
	if test "$CC" = ""
	then
	    CC=gcc
	    export CC
	    gcc="Y"
	else
	    case "$CC" in
		"gcc"|"cc")
		    gcc="Y"
		    ;;
		*)
		    gcc="N"
		    ;;
	    esac
	fi
	;;
    "OpenBSD")
	IS_BSD="Y"
	fix__guard_local="Y"
	uostype=`uname -srp`
	if test "$CC" = ""
	then
	    CC=cc
	    export CC
	    gcc="N"
	else
	    case "$CC" in
		"gcc")
		    gcc="Y"
		    ;;
		*)
		    gcc="N"
		    ;;
	    esac
	fi
	;;
    "Linux")
	IS_BSD="N"
	uostype=`uname -srp`
	if test "$CC" = ""
	then
	    CC=gcc
	    export CC
	    gcc="Y"
	else
	    case "$CC" in
		"gcc"|"cc")
		    gcc="Y"
		    ;;
		*)
		    gcc="N"
		    ;;
	    esac
	fi
	;;
    "AIX")
	IS_BSD="N"
	uostype=`uname -srp`
	gcc="N"
	if test "$CC" = ""
	then
	    CC=cc
	    export CC
	fi
	;;
    *)
	echo "ERROR E07: $OS not supported"
	return
	;;
esac
export IS_BSD

#------------------------------------------------------------------------------
# objects to build, assumes one executable
#         customize based upon modules
#------------------------------------------------------------------------------

#--- execname also used to format manual name (ie: $execname.1.gz)
execname='not_needed-library'

mansection='1'

all_c=`ls *.c   \
	| sed 's/ //g;s/\.c//'                    \
	| awk 'BEGIN{FS="|"}{printf("%s ", $1)}'  \
	| sed 's/ *$//'`

all_h="j_lib2.h j_lib2m.h"

all_read=""

#------------------------------------------------------------------------------
# set defaults
#------------------------------------------------------------------------------
# You may change if need be or
# set before executing this script

#--- check for prefix, set DESTDIR if necessary
if test "$PREFIX" != ""
then
    REAL_DIR="$PREFIX"
    export REAL_DIR
    if test "$DESTDIR" = ""
    then
	DESTDIR="$PREFIX"
	export DESTDIR
    fi
fi

#--- where files will be installed to
#    allow the creation of a package
if test "$DESTDIR" = ""
then
    case "$OS" in
	"OpenBSD"|"NetBSD"|"FreeBSD"|"Linux")
	    DESTDIR="/usr/local"
	    export DESTDIR
		;;
	"AIX")
	    DESTDIR="$HOME/local"
	    export DESTDIR
	    ;;
	*)
	    echo "ERROR E05: $OS not supported"
	    exit 2
	    ;;
    esac
fi

#--- where files should be installed and other flags
if test "$PREFIX" = ""
then
    case "$OS" in
	"Linux")
	    PREFIX="/usr/local"
	    export PREFIX
	    ;;
	"FreeBSD")
	    PREFIX="/usr/local"
	    export PREFIX
	    ;;
	"OpenBSD")
	    PREFIX="/usr/local"
	    export PREFIX
	    ;;
	"NetBSD")
	    PREFIX="/usr/local"
	    export PREFIX
	    ;;
	"AIX")
	    PREFIX="$HOME/local"
	    export PREFIX
	    ;;
	*)
	    echo "ERROR E06: $OS not supported"
	    exit 2
	    ;;
    esac
fi

#------------------------------------------------------------------------------
# checkout objects if necessary
#------------------------------------------------------------------------------
if test ! -f "$man_tr"
then
    co "$man_tr"
fi

for uf in `echo $all_c | sed 's/\.c/\.man/'`
do
    if test ! -f "$uf"
    then
	if test -f "RCS/$uf,v"
	then
	    co $uf
	fi
    fi
done

for uf in `echo $all_c`
do
    uf=`echo $uf | sed 's/$/\.c/'`
    if test ! -f "$uf"
    then
	if test -f "RCS/$uf,v"
	then
	    co $uf
	fi
    fi
done

for uf in `echo $execname`
do
    uf=`echo $uf | sed 's/$/\.man/'`
    if test ! -f "$uf"
    then
	if test -f "RCS/$uf,v"
	then
	    co $uf
	fi
    fi
done

if test "$all_h" != ""
then
    for uf in `echo $all_h`
    do
	if test ! -f "$uf"
	then
	    if test -f "RCS/$uf,v"
	    then
		co $uf
	    fi
	fi
    done
fi

if test "$all_read" != ""
then
    for uf in `echo $all_read`
    do
	if test ! -f "$uf"
	then
	    if test -f "RCS/$uf,v"
	    then
		co $uf
	    fi
	fi
    done
fi

#------------------------------------------------------------------------------
# set automatic values
#------------------------------------------------------------------------------

if test "$arch" = ""
then
    arch=`uname -m`
fi
echo "INFO I18: OS: $OS  Architecture: $arch"

if test "`ls *.c 2> /dev/null | wc -l`" -lt "1"
then
    echo "ERROR E01: .c files missing ?"
    exit 2
fi

echo "INFO I10: using $CC"

#------------------------------------------------------------------------------
# Local Libraries, based on arch
#       and determine other config items
#------------------------------------------------------------------------------
if test "$SHARED" = "N"
then
    need_shared="N"  # build shared libs ?
else
    need_shared="Y"  # build shared libs ?
fi
is_unix="Y"      # Unix Type System ?
need_nroff="N"   # use nroff for manuals
gzip_man="Y"     # compress manuals
build_man="N"    # Generate and install manuals

case "$OS" in
    "Linux")
	build_man="Y"
	use_owner='root'
	use_group='root'
	;;
    "FreeBSD")
	build_man="Y"
	use_owner='root'
	use_group='wheel'
	;;
    "OpenBSD")
	build_man="Y"
	gzip_man="N"
	use_owner='root'
	use_group='bin'
	;;
    "NetBSD")
	build_man="Y"
	use_owner='root'
	use_group='wheel'
	;;
    "AIX")
	build_man="Y"
	gzip_man="N"
	need_nroff="Y"
	need_shared="N"
	use_owner="jmccue"
	use_group="staff"
	;;
    *)
	echo "ERROR E04: $OS not supported"
	exit 2
	;;
esac

case "$arch" in
    "x86_64")
	use_64="Y"   # <-- this only used for GNU cc
	install_lib=lib64
	;;
    "amd64")
	use_64="Y"   # <-- this only used for GNU cc
	install_lib=lib
	;;
    "i386"|"i486"|"i586"|"i686")
	use_64="N"   # <-- this only used for GNU cc
	install_lib=lib
	;;
    *)
	if test "$OS" = "AIX"
	then
	    use_64="N"   # <-- this only used for GNU cc
	    install_lib=lib
	else
	    echo "ERROR E02: $OS with $arch not yet supported"
	    exit 2
	fi
	;;
esac

#------------------------------------------------------------------------------
# save old Makefile
#------------------------------------------------------------------------------
if test -f "$ofile"
then
    if test -f "$bufile"
    then
	rm -f "$bufile"
    fi
    mv "$ofile" "$bufile"
    echo "INFO I11: old $ofile saved as $bufile"
fi

#------------------------------------------------------------------------------
# start generating the Makefile
#------------------------------------------------------------------------------
emsg=""

gen_m01      > $ofile

if test "$emsg" = ""
then
    gen_build   >> $ofile
fi

if test "$emsg" = ""
then
    gen_modl   >> $ofile
fi

if test "$emsg" = ""
then
    if test "$build_man" = "Y"
    then
	gen_mman >> $ofile
    fi
fi

if test "$emsg" != ""
then
    echo "$emsg"
    exit 2
fi


#------------------------------------------------------------------------------
# DONE
#------------------------------------------------------------------------------
echo "###############################################################################
# Makefile -- Created `date`
#             by:     $sname
#             module: $execname
# END
###############################################################################" >> "$ofile"
if test "$emsg" = ""
then
    gen_minst > "$oinstall"
    chmod 777 "$oinstall"
    gen_mlink > "$linstall"
    chmod 777 "$linstall"
fi


echo "INFO I13: SUCCESS: $ofile"
echo "INFO I14:          $oinstall"
echo "INFO I15:          $linstall"
echo "INFO I22:          Build Shared Libraries: $need_shared"

if test "$PREFIX" != ""
then
    echo "INFO I17:          PREFIX: $PREFIX"
fi

if test "$DESTDIR" != ""
then
    echo "INFO I18:          DESTDIR: $DESTDIR"
fi

echo "INFO I19: genrated for $OS"
if test "$IS_BSD" = "Y"
then
    echo "INFO 820: which is a BSD type OS"
else
    echo "INFO I21: which is a non-BSD type OS"
fi

echo "INFO I12: you may want to examine the files first"

#------------------------------------------------------------------------------
# DONE
#------------------------------------------------------------------------------
exit 0
