#!/bin/sh
# This variant of 'assert' would get a UMR reliably in 2.0.9.
# Due to a race condition in the test, the 'assert' script would get
# the UMR on Solaris only some of the time, and not at all on Linux/GNU.

# Copyright (C) 2000-2012 Free Software Foundation, Inc.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

. "${srcdir=.}/tests/init.sh"; path_prepend_ ./src
print_ver_ tail

# Not "expensive" per se, but sleeping for so long is annoying.
very_expensive_

ok='ok ok ok'

touch a
tail --follow=name a foo > err 2>&1 &
tail_pid=$!
# Arrange for the tail process to die after 12 seconds.
(sleep 12; kill $tail_pid) &
echo $ok > f
echo sleeping for 7 seconds...
sleep 7
mv f foo

# echo waiting....
wait

case "$(cat err)" in
  *$ok) ;;
  *) fail=1;;
esac

test $fail = 1 && cat err

Exit $fail
