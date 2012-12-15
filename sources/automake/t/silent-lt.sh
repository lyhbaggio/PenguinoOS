#!/bin/sh
# Copyright (C) 2009-2012 Free Software Foundation, Inc.
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

# Check silent-rules mode for C, with libtool, both with and without
# automatic dependency tracking.

required='cc libtoolize'
. test-init.sh

mkdir sub

cat >>configure.ac <<'EOF'
AC_CONFIG_FILES([sub/Makefile])
AC_PROG_CC
AM_PROG_AR
AM_PROG_CC_C_O
AC_PROG_LIBTOOL
AC_OUTPUT
EOF

cat > Makefile.am <<'EOF'
# Need generic and non-generic rules.
lib_LTLIBRARIES = libfoo.la libbar.la
libbar_la_CFLAGS = $(AM_CFLAGS)
SUBDIRS = sub
EOF

cat > sub/Makefile.am <<'EOF'
AUTOMAKE_OPTIONS = subdir-objects
# Need generic and non-generic rules.
lib_LTLIBRARIES = libbaz.la libbla.la
libbla_la_CFLAGS = $(AM_CFLAGS)
EOF

cat > libfoo.c <<'EOF'
int main ()
{
  return 0;
}
EOF
cp libfoo.c libbar.c
cp libfoo.c sub/libbaz.c
cp libfoo.c sub/libbla.c

libtoolize
$ACLOCAL
$AUTOMAKE --add-missing
$AUTOCONF

for config_args in \
  '--enable-dependency-tracking' \
  '--disable-dependency-tracking' \
; do

  ./configure --enable-silent-rules $config_args

  $MAKE >stdout || { cat stdout; exit 1; }
  cat stdout

  $EGREP ' (-c|-o)' stdout && exit 1
  grep 'mv ' stdout && exit 1
  grep ' CC .*foo\.' stdout
  grep ' CC .*bar\.' stdout
  grep ' CC .*baz\.' stdout
  grep ' CC .*bla\.' stdout
  grep ' CCLD .*foo' stdout
  grep ' CCLD .*bar' stdout
  grep ' CCLD .*baz' stdout
  grep ' CCLD .*bla' stdout

  $MAKE clean
  $MAKE V=1 >stdout || { cat stdout; exit 1; }
  cat stdout
  grep ' -c' stdout
  grep ' -o libfoo' stdout
  # The libtool command line can contain e.g. a '--tag=CC' option.
  sed 's/--tag=[^ ]*/--tag=x/g' stdout | $EGREP '(CC|LD) ' && exit 1

  $MAKE distclean

done

:
