#!/bin/bash

set -u
set -e

export IRONLIB_FAKE=-fake
export TRAVIS_BUILD=1

travis-ci/do-bash-build.sh
travis-ci/do-dash-build.sh
travis-ci/do-zsh-build.sh
