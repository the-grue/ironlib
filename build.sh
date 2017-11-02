#!/bin/sh

set -e
set -u

export TOP="$PWD"
export TARGET
export CFLAGS="-Wall -Wextra"

cd utils
./build.sh
cd ..

utils/generate-limits --output include/limits.h

cd src
./build.sh
cd ..
