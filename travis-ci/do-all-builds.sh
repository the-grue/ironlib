#!/bin/bash

set -u
set -e

export TARGET=fake

travis-ci/do-bash-build.sh
travis-ci/do-dash-build.sh
travis-ci/do-zsh-build.sh
