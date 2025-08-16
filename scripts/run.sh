#!/bin/bash
cd "$(dirname "$(readlink -f "$0")")"
cd ..
if [[ ! -d logs ]]; then
    mkdir logs
fi
bin/proju >> logs/proju_$(date +"%Y-%m-%d_%H-%M-%S").log 2>&1
