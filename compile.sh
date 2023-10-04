#!/bin/bash

BINARY_NAME="phonescan"

if [[ $# -gt 0 ]]; then
    rm -rf build ${BINARY_NAME}
fi

mkdir -p build
cd build
cmake .. -G "Unix Makefiles"
make
mv ${BINARY_NAME} ../