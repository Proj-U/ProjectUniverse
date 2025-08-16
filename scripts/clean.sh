#!/bin/bash
cd "$(dirname "$(readlink -f "$0")")"
cd ..
rm -rf out/
rm -rf bin/
rm -rf logs/
