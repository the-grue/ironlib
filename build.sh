#!/bin/bash

set -e

if [ "$CC" == "" ]; then
	CC=gcc
fi

if [ "$CC" == "gcc" ] || [ "$CC" == "clang" ]; then
	CFLAGS="-Wall -Wextra -Werror -Wfatal-errors -std=gnu99 -Iinclude"
	CFLAGS="${CFLAGS} -mno-red-zone -fomit-frame-pointer"
	CFLAGS="${CFLAGS} -nostdlib -nodefaultlibs"
fi

if [ "$CC" == "clang" ]; then
	CFLAGS="${CFLAGS} -Wno-incompatible-library-redeclaration"
fi

if [ "$AR" == "" ]; then
	AR=ar
fi

if [ "$AR" == "ar" ]; then
	ARFLAGS=rcs
fi

function compile {
	echo "CC $1"
	if [ "$CC" == "gcc" ] || [ "$CC" == "clang" ]; then
		$CC $CFLAGS -c $1 -o$2
	fi
}

function generate_limits {
	$CC -Wall -Wextra -Werror -Wfatal-errors -std=gnu99 src/generate-limits.c -o src/generate-limits
	src/generate-limits --output $1
}

generate_limits include/limits.h

function link_static {
	echo "AR $1"
	if [ "$AR" == "ar" ]; then
		$AR $ARFLAGS $1 ${@:2}
	fi
}

set -u

compile src/stdio.c src/stdio.o
compile src/string.c src/string.o
compile src/baremetal.c src/baremetal.o
link_static libbaremetal.a src/baremetal.o src/string.o src/stdio.o
