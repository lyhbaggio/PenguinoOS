#!/bin/sh
# Test df's behavior for skipping the pseudo "rootfs" file system.

# Copyright (C) 2012 Free Software Foundation, Inc.

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
print_ver_ df

df || skip_ "df fails"

# Verify that rootfs is in mtab (and shown when the -a option is specified).
df -a >out || fail=1
grep '^rootfs' out || skip_ "no rootfs in mtab"

# Ensure that rootfs is suppressed when no options is specified.
df >out || fail=1
grep '^rootfs' out && { fail=1; cat out; }

# Ensure that the rootfs is shown when explicitly specifying "-t rootfs".
df -t rootfs >out || fail=1
grep '^rootfs' out || { fail=1; cat out; }

# Ensure that the rootfs is shown when explicitly specifying "-t rootfs",
# even when the -a option is specified.
df -t rootfs -a >out || fail=1
grep '^rootfs' out || { fail=1; cat out; }

# Ensure that the rootfs is omitted in all_fs mode when it is explicitly
# black-listed.
df -a -x rootfs >out || fail=1
grep '^rootfs' out && { fail=1; cat out; }

Exit $fail
