#!/bin/bash
cd "$(dirname "$(readlink -f "$0")")"
cd ..
if [[ ! -d out ]]; then
    mkdir out
fi
if [[ ! -d bin ]]; then
    mkdir bin
fi
make
