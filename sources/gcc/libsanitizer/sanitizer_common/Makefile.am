AM_CPPFLAGS = -I $(top_srcdir)/include 
 
# May be used by toolexeclibdir.
gcc_version := $(shell cat $(top_srcdir)/../gcc/BASE-VER)

DEFS = -D_GNU_SOURCE -D_DEBUG -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS 
AM_CXXFLAGS = -Wall -W -Wno-unused-parameter -Wwrite-strings -pedantic -Wno-long-long  -fPIC -fno-builtin -fno-exceptions -fomit-frame-pointer -funwind-tables -fvisibility=hidden -Wno-variadic-macros -Wno-c99-extensions 
AM_CXXFLAGS += $(LIBSTDCXX_RAW_CXX_CXXFLAGS)
ACLOCAL_AMFLAGS = -I m4

noinst_LTLIBRARIES = libsanitizer_common.la

sanitizer_common_files = \
        sanitizer_allocator.cc \
        sanitizer_common.cc \
        sanitizer_flags.cc \
        sanitizer_libc.cc \
        sanitizer_linux.cc \
        sanitizer_mac.cc \
        sanitizer_posix.cc \
        sanitizer_printf.cc \
        sanitizer_stackdepot.cc \
        sanitizer_stacktrace.cc \
        sanitizer_symbolizer.cc \
        sanitizer_symbolizer_linux.cc \
        sanitizer_symbolizer_mac.cc \
        sanitizer_symbolizer_win.cc \
        sanitizer_win.cc

libsanitizer_common_la_SOURCES = $(sanitizer_common_files) 

# Work around what appears to be a GNU make bug handling MAKEFLAGS
# values defined in terms of make variables, as is the case for CC and
# friends when we are called from the top level Makefile.
AM_MAKEFLAGS = \
	"AR_FLAGS=$(AR_FLAGS)" \
	"CC_FOR_BUILD=$(CC_FOR_BUILD)" \
	"CFLAGS=$(CFLAGS)" \
	"CXXFLAGS=$(CXXFLAGS)" \
	"CFLAGS_FOR_BUILD=$(CFLAGS_FOR_BUILD)" \
	"CFLAGS_FOR_TARGET=$(CFLAGS_FOR_TARGET)" \
	"INSTALL=$(INSTALL)" \
	"INSTALL_DATA=$(INSTALL_DATA)" \
	"INSTALL_PROGRAM=$(INSTALL_PROGRAM)" \
	"INSTALL_SCRIPT=$(INSTALL_SCRIPT)" \
	"JC1FLAGS=$(JC1FLAGS)" \
	"LDFLAGS=$(LDFLAGS)" \
	"LIBCFLAGS=$(LIBCFLAGS)" \
	"LIBCFLAGS_FOR_TARGET=$(LIBCFLAGS_FOR_TARGET)" \
	"MAKE=$(MAKE)" \
	"MAKEINFO=$(MAKEINFO) $(MAKEINFOFLAGS)" \
	"PICFLAG=$(PICFLAG)" \
	"PICFLAG_FOR_TARGET=$(PICFLAG_FOR_TARGET)" \
	"SHELL=$(SHELL)" \
	"RUNTESTFLAGS=$(RUNTESTFLAGS)" \
	"exec_prefix=$(exec_prefix)" \
	"infodir=$(infodir)" \
	"libdir=$(libdir)" \
	"prefix=$(prefix)" \
	"includedir=$(includedir)" \
	"AR=$(AR)" \
	"AS=$(AS)" \
	"LD=$(LD)" \
	"LIBCFLAGS=$(LIBCFLAGS)" \
	"NM=$(NM)" \
	"PICFLAG=$(PICFLAG)" \
	"RANLIB=$(RANLIB)" \
	"DESTDIR=$(DESTDIR)"

MAKEOVERRIDES=

## ################################################################

