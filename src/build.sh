#!/bin/sh

set -e
set -u

CFLAGS="${CFLAGS} -nostdinc -nodefaultlibs"
CFLAGS="${CFLAGS} -fomit-frame-pointer -fno-stack-protector"
CFLAGS="${CFLAGS} -mno-red-zone"
CFLAGS="${CFLAGS} -I$TOP/include"

export CFLAGS

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
OBJECTFILES="${OBJECTFILES} stdio/puts.o"
OBJECTFILES="${OBJECTFILES} stdio/stdout.o"
OBJECTFILES="${OBJECTFILES} stdio/${TARGET}/fopen.o"
OBJECTFILES="${OBJECTFILES} stdio/${TARGET}/fclose.o"
OBJECTFILES="${OBJECTFILES} stdio/${TARGET}/feof.o"
OBJECTFILES="${OBJECTFILES} stdio/${TARGET}/fread.o"
OBJECTFILES="${OBJECTFILES} stdio/${TARGET}/fwrite.o"
OBJECTFILES="${OBJECTFILES} stdlib/${TARGET}/malloc.o"
OBJECTFILES="${OBJECTFILES} stdlib/${TARGET}/free.o"
OBJECTFILES="${OBJECTFILES} string/memcmp.o"
OBJECTFILES="${OBJECTFILES} string/memcpy.o"
OBJECTFILES="${OBJECTFILES} string/strcmp.o"
OBJECTFILES="${OBJECTFILES} string/strlen.o"

$AR $ARFLAGS libc.a ${OBJECTFILES}
