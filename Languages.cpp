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
	stringtools::replaceAll(line, "long",  STR(WBOLD_BLUE_COLOR) + "long" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "bool", STR(WBOLD_BLUE_COLOR) + "int" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "char",  STR(WBOLD_BLUE_COLOR) + "char" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "auto",  STR(WBOLD_BLUE_COLOR) + "auto" + STR(WBLACK_COLOR));


	stringtools::replaceAll(line, "if",  STR(WBOLD_LIGHT_RED_COLOR) + "if" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "else",  STR(WBOLD_LIGHT_RED_COLOR) + "else" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "for",  STR(WBOLD_MAGENTA_COLOR) + "for" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "do",  STR(WBOLD_MAGENTA_COLOR) + "do" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "fowhile",  STR(WBOLD_MAGENTA_COLOR) + "while" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "void",  STR(WBOLD_RED_COLOR) + "void" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "main",  STR(WBOLD_LIGHT_RED_COLOR) + "main" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "asm",  STR(WBOLD_LIGHT_RED_COLOR) + "asm" + STR(WBLACK_COLOR));
	
	
	stringtools::replaceAll(line, "const",  STR(WBOLD_LIGHT_BLUE_COLOR) + "const" + STR(WBLACK_COLOR));			
	stringtools::replaceAll(line, "static",  STR(WBOLD_LIGHT_BLUE_COLOR) + "static" + STR(WBLACK_COLOR));			
	stringtools::replaceAll(line, "extern",  STR(WBOLD_LIGHT_BLUE_COLOR) + "extern" + STR(WBLACK_COLOR));			
	stringtools::replaceAll(line, "inline",  STR(WBOLD_LIGHT_BLUE_COLOR) + "inline" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "virtual",  STR(WBOLD_LIGHT_BLUE_COLOR) + "virtual" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "friend",  STR(WBOLD_LIGHT_BLUE_COLOR) + "friend" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "public",  STR(WBOLD_LIGHT_BLUE_COLOR) + "public" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "private",  STR(WBOLD_LIGHT_BLUE_COLOR) + "private" + STR(WBLACK_COLOR));	
	stringtools::replaceAll(line, "protected",  STR(WBOLD_LIGHT_BLUE_COLOR) + "protected" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "#include",  STR(WBOLD_YELLOW_COLOR) + "#include" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "typedef",  STR(WBOLD_MAGENTA_COLOR) + "typedef" + STR(WBLACK_COLOR));

	stringtools::replaceAll(line, "#define",  STR(WBOLD_MAGENTA_COLOR) + "#define" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "#ifndef",  STR(WBOLD_MAGENTA_COLOR) + "#ifndef" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "#ifdef",  STR(WBOLD_MAGENTA_COLOR) + "#ifdef" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "#endif",  STR(WBOLD_MAGENTA_COLOR) + "#endif" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "return",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "return" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "nodiscard",  STR(WBOLD_LIGHT_BLACK_COLOR) + "nodiscard" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "class",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "class" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "struct",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "struct" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "namespace",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "namespace" + STR(WBLACK_COLOR));

	stringtools::replaceAll(line, "using",  STR(WBOLD_GREEN_COLOR) + "using" + STR(WBLACK_COLOR));	
	
	stringtools::replaceAll(line, "std",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "std" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "iostream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "iostream" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "cstring",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "cstring" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "sstream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "sstream" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "fstream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "fstream" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "memory",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "memory" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "cstdlib",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "cstdlib" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "cstdio",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "cstdio" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "vector",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "vector" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "algorithm",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "algorithm" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "thread",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "thread" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "array",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "array" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "bitset",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "bitset" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "deque",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "deque" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "map",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "map" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "stack",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "stack" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "set",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "set" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "iterator",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "iterator" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "tuple",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "tuple" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "locale",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "locale" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "regex",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "regex" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "istream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "istream" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "ostream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "ostream" + STR(WBLACK_COLOR));
	
	stringtools::replaceAll(line, "cout",  STR(WBOLD_CYAN_COLOR) + "cout" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "printf",  STR(WBOLD_CYAN_COLOR) + "printf" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "getline",  STR(WBOLD_CYAN_COLOR) + "getline" + STR(WBLACK_COLOR));
	stringtools::replaceAll(line, "cin",  STR(WBOLD_CYAN_COLOR) + "cin" + STR(WBLACK_COLOR));
	
	std::cout << line + "\n";
}
