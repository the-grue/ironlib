#!/bin/sh

set -e

export TOP="$PWD"
export CFLAGS="-Wall -Wextra"

cd utils
./build.sh
cd ..

utils/generate-limits --output include/limits.h

cd src
./build.sh
cd ..
