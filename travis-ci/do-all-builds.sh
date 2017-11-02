#!/bin/bash

set -e

travis-ci/do-bash-build.sh
travis-ci/do-dash-build.sh
travis-ci/do-zsh-build.sh
