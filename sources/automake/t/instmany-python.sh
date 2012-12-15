#! /bin/sh
# Copyright (C) 2008-2012 Free Software Foundation, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Installing many files should not exceed the command line length limit.

# This is the python sister test of 'instmany.sh', see there for details.

required='python'
. test-init.sh

limit=2500
subdir=long_subdir_name_with_many_characters
nfiles=81
list=$(seq_ 1 $nfiles)

sed "s|@limit@|$limit|g" >myinstall.in <<'END'
#! /bin/sh
# Fake install script.  This doesn't really install
# (the INSTALL path below would be wrong outside this directory).
limit=@limit@
INSTALL='@INSTALL@'
len=`expr "$INSTALL $*" : ".*" 2>/dev/null || echo $limit`
if test $len -ge $limit; then
  echo "$0: safe command line limit of $limit characters exceeded" >&2
  exit 1
fi
exit 0
END

# Creative quoting in the next line to please maintainer-check.
sed "s|@limit@|$limit|g" >'rm' <<'END'
#! /bin/sh
limit=@limit@
PATH=$save_PATH
export PATH
RM='rm -f'
len=`expr "$RM $*" : ".*" 2>/dev/null || echo $limit`
if test $len -ge $limit; then
  echo "$0: safe command line limit of $limit characters exceeded" >&2
  exit 1
fi
exec $RM "$@"
exit 1
END

chmod +x rm

cat >>configure.ac <<END
AM_PATH_PYTHON
AC_CONFIG_FILES([myinstall], [chmod +x ./myinstall])
AC_CONFIG_FILES([$subdir/Makefile])
AC_OUTPUT
END

cat >Makefile.am <<END
SUBDIRS = $subdir
END

mkdir $subdir
cd $subdir

cat >Makefile.am <<'END'
python_PYTHON =
nobase_python_PYTHON =
END

for n in $list; do
  unindent >>Makefile.am <<END
    python_PYTHON += python$n.py
    nobase_python_PYTHON += npython$n.py
END
  echo >python$n.py
  echo >npython$n.py
done

cd ..
$ACLOCAL
$AUTOCONF
$AUTOMAKE --add-missing

instdir=$(pwd)/inst
mkdir build
cd build
../configure --prefix="$instdir"
$MAKE
# Try whether native install (or install-sh) works.
$MAKE install
# Multiple uninstall should work, too.
$MAKE uninstall
$MAKE uninstall
test $(find "$instdir" -type f -print | wc -l) -eq 0

# Try whether we don't exceed the low limit.
INSTALL='$(SHELL) $(top_builddir)/myinstall' $MAKE -e install
env save_PATH="$PATH" PATH="$(pwd)/..$PATH_SEPARATOR$PATH" $MAKE uninstall

cd $subdir
srcdir=../../$subdir

# Ensure 'make install' fails when 'install' fails.

for file in python3.py python$nfiles.py
do
  chmod a-r $srcdir/$file
  test ! -r $srcdir/$file || skip_ "cannot drop file read permissions"
  $MAKE install && exit 1
  chmod u+r $srcdir/$file
done

for file in npython3.py npython$nfiles.py
do
  chmod a-r $srcdir/$file
  $MAKE install && exit 1
  chmod u+r $srcdir/$file
done

:
