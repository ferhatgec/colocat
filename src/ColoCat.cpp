/*# MIT License
# 
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <cstring>

#include <ColoCat.hpp>
#include <Languages.hpp>

#include <FileSystemPlusPlus.h>
#include <Colorized.hpp>
#include <StringTools.hpp>

int GetWhitespace(std::string line) {
    int q = 0;
    
    while(line[q] == ' ')
        q++;
    
    return q;
}

void ReadFile(std::string file) {
    std::string line;
    unsigned line_number = 0;
    
    std::ifstream readfile((fsplusplus::GetCurrentWorkingDir() + "/" + file).c_str());

	Languages lang;
	
    if(readfile.is_open()) {
    	if(strstr(file.c_str(), ".cpp") || strstr(file.c_str(), ".hpp")) {
    		while (std::getline(readfile, line)) {
    			line_number++;
				lang.CPlusPlus(line, line_number);
			}
    	} else if(strstr(file.c_str(), ".fls") || strstr(file.c_str(), ".flsh")) {
    		while (std::getline(readfile, line)) {
				line_number++;
				lang.FlaScript(line, line_number);
    		}
    	} else if(strstr(file.c_str(), ".py") || strstr(file.c_str(), ".pyw")) {
    		while (std::getline(readfile, line)) {
				line_number++;
				lang.Python(line, line_number);
			}
		} else if(strstr(file.c_str(), ".htm") || strstr(file.c_str(), ".html")) {
			while(std::getline(readfile, line)) {
				line_number++;
				lang.HTML(line, line_number);
			}
		} else if(strstr(file.c_str(), ".js")) {
			while(std::getline(readfile, line)) {
				line_number++;
				lang.Javascript(line, line_number);
			}
    	} else {
        	while (std::getline(readfile, line)) {
        		line_number++;
				lang.Regular(line, line_number);
        	}
        }
        
        readfile.close();
    } else std::cout << "Unable to open file\n";
    
}

void HelpFunction(const char* arg) {
	BOLD_RED_COLOR();
	std::cout << "Fegeya ";
	
	BOLD_GREEN_COLOR();
	std::cout << "Colocat ";
	
	BOLD_BLUE_COLOR();
	std::cout << VERSION;
	
	BOLD_YELLOW_COLOR();		
	std::cout << "\nColorized 'cat' implementation.\n";
	
	BOLD_LIGHT_MAGENTA_COLOR();
	std::cout << arg << " [file]\n";  
}

void centerText(std::string text, std::string language) {
    std::cout << "🔒 \033[0;95m" << text << "\033[0m \033[0;94m│\033[0m " << language << "\n ";
}

void printHalfBox_Top(int len) {
	BOLD_YELLOW_COLOR();

	// Corners	
	std::cout << "  ╭";
	
	for(int a = 0; a != len; a++) {
		std::cout << "───";
	}
	
	// Corners
	std::cout << "╮\n " << _line;
	
	RESETB();		
}

void printHalfBox_Bottom(int len) {
	BOLD_LIGHT_CYAN_COLOR();
	
	// Corners
	std::cout << " ╰";
	
	for(int a = 0; a != len; a++) {
		std::cout << "───";
	}
	
	// Corners
	std::cout << "╯\n";

	RESETB();	
}


int main(int argc, char** argv) { 
	if(argc < 2) {
    	HelpFunction(argv[0]);	
		return 0;
	}
    
	std::string argv_str(argv[1]);
	
	// Set default width size.
	printHalfBox_Top(10);
		
	// Language
	if(strstr(argv_str.c_str(), ".cpp") || strstr(argv_str.c_str(), ".hpp")) {
		centerText(argv_str, "\033[1;91mC++\033[0m");
	} else if(strstr(argv_str.c_str(), ".fls")) {
		centerText(argv_str, "\033[01;33mFlaScript\033[0m");
	} else if(strstr(argv_str.c_str(), ".py")) {
		centerText(argv_str, "\033[01;32mPython\033[0m");
	} else if(strstr(argv_str.c_str(), ".js")) {
		centerText(argv_str, "\033[01;95mJavaScript\033[0m");
	} else if(strstr(argv_str.c_str(), ".htm")) {
		centerText(argv_str, "\033[01;96mHTML\033[0m");
	} else
		centerText(argv_str, "Regular");
	
	// Set default width size.
	printHalfBox_Bottom(10);	
	
    ReadFile(argv_str);

    return 0;
}
