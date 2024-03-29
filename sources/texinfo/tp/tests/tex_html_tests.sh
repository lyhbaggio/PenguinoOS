#! /bin/sh
# $Id: tex_html_tests.sh,v 1.3 2012/11/13 18:30:39 karl Exp $
# Copyright 2010, 2012 Free Software Foundation, Inc.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.

if test z"$srcdir" = 'z'; then
  srcdir=.
fi

if test "z$TEX_HTML_TESTS" != z'yes'; then
  echo "Skipping HTML TeX tests that are not easily reproducible"
  exit 77
fi

"$srcdir"/parser_tests.sh "$@" \
 tex_html
