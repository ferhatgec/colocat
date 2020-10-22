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


void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int GetWhitespace(std::string line) {
    int q = 0;
    
    while(line[q] == ' ') {
        q++;
    }
    
    return q;
}


static std::string _Add(std::string & mainString, 
    const std::string & erase) {
    
    size_t pos = std::string::npos;
    
    if((pos = mainString.find(erase)) != std::string::npos) {
        mainString.erase(pos, erase.length());
  	}
    
    return mainString;
}


void ReadFile(std::string file) {
    std::string line;
    std::ifstream readfile((fsplusplus::GetCurrentWorkingDir() + "/" + file).c_str());
    if(readfile.is_open()) {
        while (std::getline(readfile, line)) {
			replaceAll(line, "int", "\033[1;91mint\033[0m");
			replaceAll(line, "void", "\033[1;34mvoid\033[0m");
			
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
