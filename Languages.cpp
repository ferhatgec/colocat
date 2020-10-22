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

void Languages::CPlusPlus(std::string line) {
	stringtools::replaceAll(line, "int", STR(WBOLD_BLUE_COLOR) + "int" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "bool", STR(WBOLD_BLUE_COLOR) + "int" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "char",  STR(WBOLD_BLUE_COLOR) + "char" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "auto",  STR(WBOLD_BLUE_COLOR) + "auto" + STR(WBLACK_COLOR));

	stringtools::replaceAll(line, "void",  STR(WBOLD_RED_COLOR) + "void" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "main",  STR(WBOLD_LIGHT_RED_COLOR) + "main" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "const",  STR(WBOLD_LIGHT_BLUE_COLOR) + "const" + STR(WBLACK_COLOR));			
	stringtools::replaceAll(line, "static",  STR(WBOLD_LIGHT_BLUE_COLOR) + "static" + STR(WBLACK_COLOR));			
	stringtools::replaceAll(line, "extern",  STR(WBOLD_LIGHT_BLUE_COLOR) + "extern" + STR(WBLACK_COLOR));			
	stringtools::replaceAll(line, "inline",  STR(WBOLD_LIGHT_BLUE_COLOR) + "inline" + STR(WBLACK_COLOR));
	
	
	stringtools::replaceAll(line, "#include",  STR(WBOLD_YELLOW_COLOR) + "#include" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "#define",  STR(WBOLD_MAGENTA_COLOR) + "#define" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "#ifndef",  STR(WBOLD_MAGENTA_COLOR) + "#ifndef" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "#ifdef",  STR(WBOLD_MAGENTA_COLOR) + "#ifdef" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "#endif",  STR(WBOLD_MAGENTA_COLOR) + "#endif" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "return",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "return" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "nodiscard",  STR(WBOLD_LIGHT_BLACK_COLOR) + "nodiscard" + STR(WBLACK_COLOR));
	
	
	std::cout << WBOLD_CYAN_COLOR << line + "\n";
}
