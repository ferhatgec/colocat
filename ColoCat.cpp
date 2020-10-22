/*# MIT License
# 
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <cstring>
#include "FileSystemPlusPlus.h"
#include "Colorized.hpp"
#include "StringTools.hpp"

inline std::string STR(const char* str) {
	return (std::string)str;
}

int GetWhitespace(std::string line) {
    int q = 0;
    
    while(line[q] == ' ') {
        q++;
    }
    
    return q;
}

void ReadFile(std::string file) {
    std::string line;
    std::ifstream readfile((fsplusplus::GetCurrentWorkingDir() + "/" + file).c_str());
    if(readfile.is_open()) {
        while (std::getline(readfile, line)) {
			stringtools::replaceAll(line, "int", STR(WBOLD_RED_COLOR) + "int" + STR(WBLACK_COLOR));
			stringtools::replaceAll(line, "char",  STR(WBOLD_BLUE_COLOR) + "char" + STR(WBLACK_COLOR));
			stringtools::replaceAll(line, "const",  STR(WBOLD_LIGHT_BLUE_COLOR) + "const" + STR(WBLACK_COLOR));
			
			stringtools::replaceAll(line, "void",  STR(WBOLD_BLUE_COLOR) + "void" + STR(WBLACK_COLOR));
			
			std::cout << line;
			
			printf("\n");
        }
        	
        readfile.close();
    } else printf("Unable to open file\n");
    
}

void HelpFunction(const char* arg) {
	BOLD_RED_COLOR();
	std::cout << "Fegeya ";
	
	BOLD_GREEN_COLOR();
	std::cout << "Colocat\n";
	
	BOLD_BLUE_COLOR();		
	std::cout << "Colorized 'cat' implementation.\n";
	
	BOLD_LIGHT_MAGENTA_COLOR();
	std::cout << arg << " [file]\n";  
}

int main(int argc, char** argv) { 
	if(argc < 2) {
    	HelpFunction(argv[0]);
		
		return 0;
	}
    
    std::string argv_str(argv[1]);
    
    ReadFile(argv_str);

    return 0;
}
