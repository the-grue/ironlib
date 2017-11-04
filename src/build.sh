#!/bin/sh

set -e

CFLAGS="${CFLAGS} -nostdinc -nodefaultlibs"
CFLAGS="${CFLAGS} -fomit-frame-pointer -fno-stack-protector"
CFLAGS="${CFLAGS} -mno-red-zone"
CFLAGS="${CFLAGS} -I$TOP/include"

export CFLAGS

cd baremetal
./build.sh
cd ..

cd errno
./build.sh
cd ..

cd stdio
./build.sh
cd ..

cd stdlib
./build.sh
cd ..

cd string
./build.sh
cd ..

AR=ar
ARFLAGS=rcs

OBJECTFILES=
OBJECTFILES="${OBJECTFILES} baremetal/syscalls.o"
OBJECTFILES="${OBJECTFILES} stdio/puts.o"
OBJECTFILES="${OBJECTFILES} stdio/stdout.o"
OBJECTFILES="${OBJECTFILES} stdio/baremetal/fopen.o"
OBJECTFILES="${OBJECTFILES} stdio/baremetal/fclose.o"
OBJECTFILES="${OBJECTFILES} stdio/baremetal/feof.o"
OBJECTFILES="${OBJECTFILES} stdio/baremetal/fread.o"
OBJECTFILES="${OBJECTFILES} stdio/baremetal/fwrite.o"
OBJECTFILES="${OBJECTFILES} stdlib/baremetal/malloc.o"
OBJECTFILES="${OBJECTFILES} stdlib/baremetal/free.o"
OBJECTFILES="${OBJECTFILES} string/memcmp.o"
OBJECTFILES="${OBJECTFILES} string/memcpy.o"
OBJECTFILES="${OBJECTFILES} string/memset.o"
OBJECTFILES="${OBJECTFILES} string/strcmp.o"
OBJECTFILES="${OBJECTFILES} string/strcpy.o"
OBJECTFILES="${OBJECTFILES} string/strlen.o"

$AR $ARFLAGS ../libc.a ${OBJECTFILES}
