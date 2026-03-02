AM_CPPFLAGS =
AM_CFLAGS   =
AM_CXXFLAGS = -s NO_DISABLE_EXCEPTION_CATCHING
AM_LDFLAGS  =

LOG_COMPILER = /usr/bin/js --no-experimental-fetch --trace-uncaught

# AM_CPPFLAGS += $(GTEST_MAIN_CFLAGS)
# AM_LDFLAGS  += $(GTEST_MAIN_LIBS)

AM_CPPFLAGS += -I$(top_srcdir)/include
AM_LDFLAGS  += $(top_builddir)/src/libfoo.la

check_PROGRAMS = \
test_io \
test_ifstream

test_io_SOURCES = test_io.cc

test_ifstream_SOURCES = test_ifstream.cc

TESTS = $(check_PROGRAMS)
