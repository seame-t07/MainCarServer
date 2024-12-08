#!/bin/bash

# precisa desta dependencia para compilar o projeto
# sudo apt install nlohmann-json3-dev

#cd cpp
#cmake . -DCMAKE_BUILD_TYPE=Release -DCPP_FETCH_DEPS=ON
#cmake --build .

#cd ..

git submodule update --init --recursive

cmake -S . -B build
cd build
make
cd ..
./build/MainCarServer

