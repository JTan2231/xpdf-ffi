#!/bin/bash
mkdir -p build
cd build

# Regular CMake build - no toolchain file needed
cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_SHARED_LIBS=ON \
    -G Ninja

ninja
