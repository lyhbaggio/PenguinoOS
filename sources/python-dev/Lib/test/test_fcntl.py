"""Test program for the fcntl C module.
"""
import os
import struct
import sys
import unittest
from test.support import verbose, TESTFN, unlink, run_unittest, import_module

# Skip test if no fnctl module.
fcntl = import_module('fcntl')


# TODO - Write tests for flock() and lockf().

def get_lockdata():
    try:
        os.O_LARGEFILE
    except AttributeError:
        start_len = "ll"
    else:
        start_len = "qq"

    if (sys.platform.startswith(('netbsd', 'freebsd', 'openbsd', 'bsdos'))
        or sys.platform == 'darwin'):
        if struct.calcsize('l') == 8:
            off_t = 'l'
            pid_t = 'i'
        else:
            off_t = 'lxxxx'
            pid_t = 'l'
        lockdata = struct.pack(off_t + off_t + pid_t + 'hh', 0, 0, 0,
                               fcntl.F_WRLCK, 0)
    elif sys.platform in ['aix3', 'aix4', 'hp-uxB', 'unixware7']:
        lockdata = struct.pack('hhlllii', fcntl.F_WRLCK, 0, 0, 0, 0, 0, 0)
    else:
        lockdata = struct.pack('hh'+start_len+'hh', fcntl.F_WRLCK, 0, 0, 0, 0, 0)
    if lockdata:
        if verbose:
            print('struct.pack: ', repr(lockdata))
    return lockdata

lockdata = get_lockdata()

class TestFcntl(unittest.TestCase):

    def setUp(self):
        self.f = None

    def tearDown(self):
        if self.f and not self.f.closed:
            self.f.close()
        unlink(TESTFN)

    def test_fcntl_fileno(self):
        # the example from the library docs
        self.f = open(TESTFN, 'wb')
        rv = fcntl.fcntl(self.f.fileno(), fcntl.F_SETFL, os.O_NONBLOCK)
        if verbose:
            print('Status from fcntl with O_NONBLOCK: ', rv)
        rv = fcntl.fcntl(self.f.fileno(), fcntl.F_SETLKW, lockdata)
        if verbose:
            print('String from fcntl with F_SETLKW: ', repr(rv))
        self.f.close()

    def test_fcntl_file_descriptor(self):
        # again, but pass the file rather than numeric descriptor
        self.f = open(TESTFN, 'wb')
        rv = fcntl.fcntl(self.f, fcntl.F_SETFL, os.O_NONBLOCK)
        rv = fcntl.fcntl(self.f, fcntl.F_SETLKW, lockdata)
        self.f.close()

    def test_fcntl_64_bit(self):
        # Issue #1309352: fcntl shouldn't fail when the third arg fits in a
        # C 'long' but not in a C 'int'.
        try:
            cmd = fcntl.F_NOTIFY
            # This flag is larger than 2**31 in 64-bit builds
            flags = fcntl.DN_MULTISHOT
        except AttributeError:
            self.skipTest("F_NOTIFY or DN_MULTISHOT unavailable")
        fd = os.open(os.path.dirname(os.path.abspath(TESTFN)), os.O_RDONLY)
        try:
            fcntl.fcntl(fd, cmd, flags)
        finally:
            os.close(fd)


def test_main():
    run_unittest(TestFcntl)

if __name__ == '__main__':
    test_main()
