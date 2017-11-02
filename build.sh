#!/bin/sh

export TOP="$PWD"

export TARGET=baremetal
export TARGET=fake

export CFLAGS="-Wall -Wextra"

cd utils
./build.sh
cd ..

utils/generate-limits --output include/limits.h

cd src
./build.sh
cd ..
