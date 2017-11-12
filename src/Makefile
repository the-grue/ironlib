TOP ?= ..
include $(TOP)/make/config.mk
include $(TOP)/make/patterns.mk

CC ?= gcc
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -Wfatal-errors
CFLAGS := $(CFLAGS) -I $(TOP)/include

libfiles += errno/errno.o
libfiles += stdio/puts.o
libfiles += stdio/stdout.o
libfiles += string/memcpy.o
libfiles += string/memcmp.o
libfiles += string/memset.o
libfiles += string/strcpy.o
libfiles += string/strlen.o

ifdef IRONLIB_WITH_BAREMETAL
libfiles += baremetal/syscalls.o
libfiles += stdio/baremetal/disk.o
libfiles += stdio/baremetal/fclose.o
libfiles += stdio/baremetal/feof.o
libfiles += stdio/baremetal/fopen.o
libfiles += stdio/baremetal/fread.o
libfiles += stdio/baremetal/fwrite.o
libfiles += stdlib/baremetal/free.o
libfiles += stdlib/baremetal/malloc.o
endif

.PHONY: all
all: libc.a

libc.a: $(libfiles)

.PHONY: clean
clean:
	$(RM) $(libfiles)
	$(RM) libc.a

.PHONY: test
test:

.PHONY: install
install: libc.a
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	mkdir -p $(DESTDIR)$(PREFIX)/include
	cp libc.a $(DESTDIR)$(PREFIX)/lib/
	cp -R $(TOP)/include/* $(DESTDIR)$(PREFIX)/include

$(V).SILENT:
