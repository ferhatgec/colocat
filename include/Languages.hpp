/*# MIT License
# 
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef LANGUAGES_HPP
#define LANGUAGES_HPP

#include <iostream>
#include <cstring>

static std::string _line = " │ ";

class Languages {
public:
	std::string Predefined(std::string line);
	
	void Regular(std::string line, unsigned line_number);
	void CPlusPlus(std::string line, unsigned line_number);
	void FlaScript(std::string line, unsigned line_number);
	void Python(std::string line, unsigned line_number);
	void HTML(std::string line, unsigned line_number);
	void Javascript(std::string line, unsigned line_number);
};

#endif // LANGUAGES_HPP
