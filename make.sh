#!/bin/sh

g++ -std=c++17 -I./Library/ -I./include/ Languages.cpp ColoCat.cpp -o colocat && ./colocat
