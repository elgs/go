#!/usr/bin/env bash

rm -rf a.out
g++ -std=c++14 -O3 main.cc
./a.out