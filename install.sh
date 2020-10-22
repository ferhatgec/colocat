#!/bin/sh

g++ -std=c++17 -I./Library/ -I./include/ src/Languages.cpp src/ColoCat.cpp -o /bin/colocat 

colocat
