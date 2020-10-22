/*# MIT License
# 
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <cstring>

#include <Languages.hpp>

#include <FileSystemPlusPlus.h>
#include <Colorized.hpp>
#include <StringTools.hpp>


inline std::string STR(const char* str) {
	return (std::string)str;
}


void Languages::Regular(std::string line) {
	stringtools::replaceAll(line, "int", STR(WBOLD_RED_COLOR) + "int" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "char",  STR(WBOLD_BLUE_COLOR) + "char" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "const",  STR(WBOLD_LIGHT_BLUE_COLOR) + "const" + STR(WBLACK_COLOR));			
	stringtools::replaceAll(line, "void",  STR(WBOLD_BLUE_COLOR) + "void" + STR(WBLACK_COLOR));

	std::cout << line + "\n";
}

