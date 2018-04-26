ironlib
=======

[![Build Status](https://travis-ci.org/ReturnInfinity/ironlib.svg?branch=master)](https://travis-ci.org/ReturnInfinity/ironlib)

The standard C library for BareMetal.

**Note**: This project has since been deprecated and replaced by newlib.

### Building with CMake

The primary build is CMake.

To install it on Ubuntu, you can do this:

```
sudo apt install cmake
```

To build with CMake, do this:

```
mkdir build
cd build
cmake ..
cmake --build .
```

If Doxygen is installed, the documentation will be put into `html/` and `man/`.

To install Doxygen, you can do this:

```
sudo apt update
sudo apt install doxygen
sudo apt install graphviz
```

### Building with the Shell

Officially supported shells are:

 - bash
 - zsh
 - dash

To build using the shell scripts, use `build.sh` and `clean.sh`

```
./build.sh
```

The file `libc.a` will be generated in the project root directory.

To remove all generated files, use the `clean.sh` script.

```
./clean.sh
```
