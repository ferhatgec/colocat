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

void Line(unsigned _line_number) {
    if(_line_number < 8) {
        std::cout << _line_number << _line + " ";
    } else {
    if(_line_number == 8 || _line_number == 98 || _line_number == 998 || _line_number == 9998)
		std::cout << _line_number << " ╰  ";
	else if(_line_number == 9 || _line_number == 99 || _line_number == 999 || _line_number == 9999)
		std::cout << _line_number << "  ╮ ";
	else
		std::cout << _line_number << _line;
    }
}

std::string Languages::Predefined(std::string line) {
    stringtools::replaceAll(line, "::",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "::" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "{",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "{" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "}",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "}" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "(",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "(" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, ")",  STR(WBOLD_LIGHT_YELLOW_COLOR) + ")" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "*",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "*" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "<",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "<" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, ">",  STR(WBOLD_LIGHT_YELLOW_COLOR) + ">" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "+",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "+" + STR(WBOLD_LIGHT_WHITE_COLOR));

    return line;
}

void Languages::Regular(std::string line, unsigned line_number) {
	stringtools::replaceAll(line, "int ", STR(WBOLD_RED_COLOR) + "int " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "char ",  STR(WBOLD_BLUE_COLOR) + "char " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "const ",  STR(WBOLD_LIGHT_BLUE_COLOR) + "const " + STR(WBOLD_LIGHT_WHITE_COLOR));			
	stringtools::replaceAll(line, "void ",  STR(WBOLD_BLUE_COLOR) + "void " + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	line = Predefined(line);
	
	Line(line_number);
		
	std::cout << line + "\n";
}

void Languages::CPlusPlus(std::string line, unsigned line_number) {
    if(stringtools::ltrim(line)[0] == '/' && stringtools::ltrim(line)[1] == '/')
        line = STR(WLIGHT_BLACK_COLOR) + line + STR(WBOLD_LIGHT_WHITE_COLOR);

	stringtools::replaceAll(line, "int ", STR(WBOLD_BLUE_COLOR) + "int " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "long ",  STR(WBOLD_BLUE_COLOR) + "long " + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "bool", STR(WBOLD_BLUE_COLOR) + "int " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "char ",  STR(WBOLD_BLUE_COLOR) + "char " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "auto ",  STR(WBOLD_BLUE_COLOR) + "auto " + STR(WBOLD_LIGHT_WHITE_COLOR));


	stringtools::replaceAll(line, "if",  STR(WBOLD_LIGHT_RED_COLOR) + "if" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "else",  STR(WBOLD_LIGHT_RED_COLOR) + "else" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "for",  STR(WBOLD_MAGENTA_COLOR) + "for" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "do",  STR(WBOLD_MAGENTA_COLOR) + "do" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "while",  STR(WBOLD_MAGENTA_COLOR) + "while" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "void ",  STR(WBOLD_RED_COLOR) + "void " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "main",  STR(WBOLD_LIGHT_RED_COLOR) + "main" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "asm",  STR(WBOLD_LIGHT_RED_COLOR) + "asm" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	
	stringtools::replaceAll(line, "const ",  STR(WBOLD_LIGHT_BLUE_COLOR) + "const " + STR(WBOLD_LIGHT_WHITE_COLOR));			
	stringtools::replaceAll(line, "static ",  STR(WBOLD_LIGHT_BLUE_COLOR) + "static " + STR(WBOLD_LIGHT_WHITE_COLOR));			
	stringtools::replaceAll(line, "extern ",  STR(WBOLD_LIGHT_BLUE_COLOR) + "extern " + STR(WBOLD_LIGHT_WHITE_COLOR));			
	stringtools::replaceAll(line, "inline ",  STR(WBOLD_LIGHT_BLUE_COLOR) + "inline" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "virtual ",  STR(WBOLD_LIGHT_BLUE_COLOR) + "virtual " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "friend ",  STR(WBOLD_LIGHT_BLUE_COLOR) + "friend " + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "public",  STR(WBOLD_LIGHT_BLUE_COLOR) + "public" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "private",  STR(WBOLD_LIGHT_BLUE_COLOR) + "private" + STR(WBOLD_LIGHT_WHITE_COLOR));	
	stringtools::replaceAll(line, "protected",  STR(WBOLD_LIGHT_BLUE_COLOR) + "protected" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "#include",  STR(WBOLD_YELLOW_COLOR) + "#include" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "typedef ",  STR(WBOLD_MAGENTA_COLOR) + "typedef " + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "#define ",  STR(WBOLD_MAGENTA_COLOR) + "#define " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "#ifndef ",  STR(WBOLD_MAGENTA_COLOR) + "#ifndef " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "#ifdef ",  STR(WBOLD_MAGENTA_COLOR) + "#ifdef " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "#endif",  STR(WBOLD_MAGENTA_COLOR) + "#endif" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "return ",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "return " + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "nodiscard",  STR(WBOLD_LIGHT_BLACK_COLOR) + "nodiscard" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "class ",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "class " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "struct ",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "struct " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "namespace ",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "namespace " + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "using ",  STR(WBOLD_GREEN_COLOR) + "using " + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "std",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "std" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "iostream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "iostream" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "cstring",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "cstring" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "sstream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "sstream" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "fstream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "fstream" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "memory",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "memory" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "cstdlib",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "cstdlib" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "cstdio",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "cstdio" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "vector",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "vector" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "algorithm",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "algorithm" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "thread",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "thread" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "array",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "array" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "bitset",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "bitset" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "deque",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "deque" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "map",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "map" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "stack",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "stack" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "set",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "set" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "iterator",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "iterator" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "tuple",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "tuple" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "locale",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "locale" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "regex",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "regex" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "istream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "istream" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "ostream",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "ostream" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "cout",  STR(WBOLD_CYAN_COLOR) + "cout" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "printf",  STR(WBOLD_CYAN_COLOR) + "printf" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "getline",  STR(WBOLD_CYAN_COLOR) + "getline" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "cin",  STR(WBOLD_CYAN_COLOR) + "cin" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
    line = Predefined(line);

	Line(line_number);
	
	std::cout << line + "\n";
}

void Languages::FlaScript(std::string line, unsigned line_number) {
    if(stringtools::ltrim(line)[0] == '/' && stringtools::ltrim(line)[1] == '/')
        line = STR(WLIGHT_BLACK_COLOR) + line + STR(WBOLD_LIGHT_WHITE_COLOR);

    stringtools::replaceAll(line, "print",  STR(WBOLD_CYAN_COLOR) + "print" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "fprintf",  STR(WBOLD_CYAN_COLOR) + "fprintf" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "@echo",  STR(WBOLD_CYAN_COLOR) + "@echo" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "fprintln",  STR(WBOLD_CYAN_COLOR) + "fprintln" + STR(WBOLD_LIGHT_WHITE_COLOR));

    stringtools::replaceAll(line, "@append",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "@append" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "@pop_back",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "@pop_back" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "@between",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "@between" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "@escape_seq",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "@escape_seq"+ STR(WBOLD_LIGHT_WHITE_COLOR));
	
    stringtools::replaceAll(line, "@input",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "@input" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	
    stringtools::replaceAll(line, "var ", STR(WBOLD_BLUE_COLOR) + "var " + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "bool", STR(WBOLD_LIGHT_BLUE_COLOR) + "bool" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "int",  STR(WBOLD_LIGHT_BLUE_COLOR) + "int" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "string",  STR(WBOLD_LIGHT_BLUE_COLOR) + "string" + STR(WBOLD_LIGHT_WHITE_COLOR));

    stringtools::replaceAll(line, "put",  STR(WBOLD_MAGENTA_COLOR) + "put" + STR(WBOLD_LIGHT_WHITE_COLOR));
    
	stringtools::replaceAll(line, "if",  STR(WBOLD_LIGHT_RED_COLOR) + "if" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "else",  STR(WBOLD_LIGHT_RED_COLOR) + "else" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "for",  STR(WBOLD_MAGENTA_COLOR) + "for" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "do",  STR(WBOLD_MAGENTA_COLOR) + "do" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "while",  STR(WBOLD_MAGENTA_COLOR) + "while" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "func",  STR(WBOLD_RED_COLOR) + "void" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "main",  STR(WBOLD_LIGHT_RED_COLOR) + "main" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "import",  STR(WBOLD_YELLOW_COLOR) + "import" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "defin",  STR(WBOLD_MAGENTA_COLOR) + "defin" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "#ifdef",  STR(WBOLD_MAGENTA_COLOR) + "#ifdef" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "#endif",  STR(WBOLD_MAGENTA_COLOR) + "#endif" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "return",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "return" + STR(WBOLD_LIGHT_WHITE_COLOR));
	

	
	
	stringtools::replaceAll(line, "SystemInfo",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "SystemInfo" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "Colorized",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "Colorized" + STR(WBOLD_LIGHT_WHITE_COLOR));
		
	stringtools::replaceAll(line, "newline",  STR(WBOLD_LIGHT_BLACK_COLOR) + "newline" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	line = Predefined(line);
	
	Line(line_number);
		
	std::cout << line + "\n";
}

void Languages::Python(std::string line, unsigned line_number) {
    if(stringtools::ltrim(line)[0] == '#')
        line = STR(WLIGHT_BLACK_COLOR) + line + STR(WBOLD_LIGHT_WHITE_COLOR);

	stringtools::replaceAll(line, "if",  STR(WBOLD_LIGHT_RED_COLOR) + "if" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "else",  STR(WBOLD_LIGHT_RED_COLOR) + "else" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "elif",  STR(WBOLD_LIGHT_RED_COLOR) + "elif" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "for",  STR(WBOLD_MAGENTA_COLOR) + "for" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "while",  STR(WBOLD_MAGENTA_COLOR) + "while" + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "str", STR(WBOLD_BLUE_COLOR) + "str" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "bool", STR(WBOLD_BLUE_COLOR) + "bool" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "float", STR(WBOLD_BLUE_COLOR) + "float" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "def",  STR(WBOLD_RED_COLOR) + "def" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "lambda",  STR(WBOLD_RED_COLOR) + "lambda" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "import",  STR(WBOLD_YELLOW_COLOR) + "import" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "from",  STR(WBOLD_LIGHT_YELLOW_COLOR) + "from" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "global",  STR(WBOLD_LIGHT_BLUE_COLOR) + "global" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "return",  STR(WBOLD_LIGHT_MAGENTA_COLOR) + "return" + STR(WBOLD_LIGHT_WHITE_COLOR));
		
	stringtools::replaceAll(line, "print",  STR(WBOLD_CYAN_COLOR) + "print" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	line = Predefined(line);
	
	Line(line_number);
		
	std::cout << line + "\n";
}

void Languages::HTML(std::string line, unsigned line_number) {
	stringtools::replaceAll(line, "html", STR(WBOLD_CYAN_COLOR) + "html" + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "!doctype", STR(WBOLD_BLUE_COLOR) + "!doctype" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "!DOCTYPE", STR(WBOLD_BLUE_COLOR) + "!DOCTYPE" + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "a", STR(WBOLD_CYAN_COLOR) + "a" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "abbr", STR(WBOLD_CYAN_COLOR) + "abbr" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "acronym", STR(WBOLD_CYAN_COLOR) + "acronym" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "address", STR(WBOLD_CYAN_COLOR) + "address" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "applet", STR(WBOLD_CYAN_COLOR) + "applet" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "area", STR(WBOLD_CYAN_COLOR) + "area" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "article", STR(WBOLD_CYAN_COLOR) + "article" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "aside", STR(WBOLD_CYAN_COLOR) + "aside" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "audio", STR(WBOLD_CYAN_COLOR) + "audio" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "base", STR(WBOLD_CYAN_COLOR) + "base" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "basefont", STR(WBOLD_CYAN_COLOR) + "basefont" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "bb", STR(WBOLD_CYAN_COLOR) + "bb" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "bdo", STR(WBOLD_CYAN_COLOR) + "bdo" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "big", STR(WBOLD_CYAN_COLOR) + "big" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "blockquote", STR(WBOLD_CYAN_COLOR) + "blockquote" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "body", STR(WBOLD_CYAN_COLOR) + "body" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "br", STR(WBOLD_CYAN_COLOR) + "br" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "button", STR(WBOLD_CYAN_COLOR) + "button" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "canvas", STR(WBOLD_CYAN_COLOR) + "canvas" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "caption", STR(WBOLD_CYAN_COLOR) + "caption" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "center", STR(WBOLD_CYAN_COLOR) + "center" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "cite", STR(WBOLD_CYAN_COLOR) + "cite" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "code", STR(WBOLD_CYAN_COLOR) + "code" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "col", STR(WBOLD_CYAN_COLOR) + "col" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "colgroup", STR(WBOLD_CYAN_COLOR) + "colgroup" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "command", STR(WBOLD_CYAN_COLOR) + "command" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "datagrid", STR(WBOLD_CYAN_COLOR) + "datagrid" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "datalist", STR(WBOLD_CYAN_COLOR) + "datalist" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "dd", STR(WBOLD_CYAN_COLOR) + "dd" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "del", STR(WBOLD_CYAN_COLOR) + "del" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "details", STR(WBOLD_CYAN_COLOR) + "details" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "dfn", STR(WBOLD_CYAN_COLOR) + "dfn" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "dialog", STR(WBOLD_CYAN_COLOR) + "dialog" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "dir", STR(WBOLD_CYAN_COLOR) + "dir" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "div", STR(WBOLD_CYAN_COLOR) + "div" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "dl", STR(WBOLD_CYAN_COLOR) + "dl" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "dt", STR(WBOLD_CYAN_COLOR) + "dt" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "em", STR(WBOLD_CYAN_COLOR) + "em" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "embed", STR(WBOLD_CYAN_COLOR) + "embed" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "eventsource", STR(WBOLD_CYAN_COLOR) + "eventsource" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "fieldset", STR(WBOLD_CYAN_COLOR) + "fieldset" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "figcaption", STR(WBOLD_CYAN_COLOR) + "figcaption" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "figure", STR(WBOLD_CYAN_COLOR) + "figure" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "font", STR(WBOLD_CYAN_COLOR) + "font" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "footer", STR(WBOLD_CYAN_COLOR) + "footer" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "form", STR(WBOLD_CYAN_COLOR) + "form" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "frame", STR(WBOLD_CYAN_COLOR) + "frame" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "frameset", STR(WBOLD_CYAN_COLOR) + "frameset" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "h1", STR(WBOLD_CYAN_COLOR) + "h1" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "h2", STR(WBOLD_CYAN_COLOR) + "h2" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "h3", STR(WBOLD_CYAN_COLOR) + "h3" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "h4", STR(WBOLD_CYAN_COLOR) + "h4" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "h5", STR(WBOLD_CYAN_COLOR) + "h5" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "h6", STR(WBOLD_CYAN_COLOR) + "h6" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "head", STR(WBOLD_CYAN_COLOR) + "head" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "header", STR(WBOLD_CYAN_COLOR) + "header" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "hgroup", STR(WBOLD_CYAN_COLOR) + "hgroup" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "hr", STR(WBOLD_CYAN_COLOR) + "hr" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "i", STR(WBOLD_CYAN_COLOR) + "i" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "iframe", STR(WBOLD_CYAN_COLOR) + "iframe" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "img", STR(WBOLD_CYAN_COLOR) + "img" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "input", STR(WBOLD_CYAN_COLOR) + "input" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "ins", STR(WBOLD_CYAN_COLOR) + "ins" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "isindex", STR(WBOLD_CYAN_COLOR) + "isindex" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "kbd", STR(WBOLD_CYAN_COLOR) + "kbd" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "keygen", STR(WBOLD_CYAN_COLOR) + "keygen" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "label", STR(WBOLD_CYAN_COLOR) + "label" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "legend", STR(WBOLD_CYAN_COLOR) + "legend" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "li", STR(WBOLD_CYAN_COLOR) + "li" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "link", STR(WBOLD_CYAN_COLOR) + "link" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "map", STR(WBOLD_CYAN_COLOR) + "map" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "mark", STR(WBOLD_CYAN_COLOR) + "mark" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "menu", STR(WBOLD_CYAN_COLOR) + "menu" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "meta", STR(WBOLD_CYAN_COLOR) + "meta" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "meter", STR(WBOLD_CYAN_COLOR) + "meter" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "nav", STR(WBOLD_CYAN_COLOR) + "nav" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "noframes", STR(WBOLD_CYAN_COLOR) + "noframes" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "noscript", STR(WBOLD_CYAN_COLOR) + "noscript" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "object", STR(WBOLD_CYAN_COLOR) + "object" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "ol", STR(WBOLD_CYAN_COLOR) + "ol" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "optgroup", STR(WBOLD_CYAN_COLOR) + "optgroup" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "option", STR(WBOLD_CYAN_COLOR) + "option" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "output", STR(WBOLD_CYAN_COLOR) + "output" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "p", STR(WBOLD_CYAN_COLOR) + "p" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "param", STR(WBOLD_CYAN_COLOR) + "param" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "pre", STR(WBOLD_CYAN_COLOR) + "pre" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "progress", STR(WBOLD_CYAN_COLOR) + "progress" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "q", STR(WBOLD_CYAN_COLOR) + "q" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "rp", STR(WBOLD_CYAN_COLOR) + "rp" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "rt", STR(WBOLD_CYAN_COLOR) + "rt" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "ruby", STR(WBOLD_CYAN_COLOR) + "ruby" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "s", STR(WBOLD_CYAN_COLOR) + "s" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "script", STR(WBOLD_CYAN_COLOR) + "script" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "samp", STR(WBOLD_CYAN_COLOR) + "samp" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "section", STR(WBOLD_CYAN_COLOR) + "section" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "select", STR(WBOLD_CYAN_COLOR) + "select" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "small", STR(WBOLD_CYAN_COLOR) + "small" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "source", STR(WBOLD_CYAN_COLOR) + "source" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "span", STR(WBOLD_CYAN_COLOR) + "span" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "strike", STR(WBOLD_CYAN_COLOR) + "strike" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "strong", STR(WBOLD_CYAN_COLOR) + "strong" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "style", STR(WBOLD_CYAN_COLOR) + "style" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "sub", STR(WBOLD_CYAN_COLOR) + "sub" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "sup", STR(WBOLD_CYAN_COLOR) + "sup" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "table", STR(WBOLD_CYAN_COLOR) + "table" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "tbody", STR(WBOLD_CYAN_COLOR) + "tbody" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "tfoot", STR(WBOLD_CYAN_COLOR) + "tfoot" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "th", STR(WBOLD_CYAN_COLOR) + "th" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "thead", STR(WBOLD_CYAN_COLOR) + "thead" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "time", STR(WBOLD_CYAN_COLOR) + "time" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "title", STR(WBOLD_CYAN_COLOR) + "title" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "tr", STR(WBOLD_CYAN_COLOR) + "tr" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "track", STR(WBOLD_CYAN_COLOR) + "track" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "tt", STR(WBOLD_CYAN_COLOR) + "tt" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "u", STR(WBOLD_CYAN_COLOR) + "u" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "ul", STR(WBOLD_CYAN_COLOR) + "ul" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "var", STR(WBOLD_CYAN_COLOR) + "var" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "video", STR(WBOLD_CYAN_COLOR) + "video" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "wbr", STR(WBOLD_CYAN_COLOR) + "wbr" + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "class", STR(WBOLD_CYAN_COLOR) + "class" + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "/", STR(WBOLD_YELLOW_COLOR) + "/" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "<", STR(WBOLD_YELLOW_COLOR) + "<" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, ">", STR(WBOLD_YELLOW_COLOR) + ">" + STR(WBOLD_LIGHT_WHITE_COLOR));

	Line(line_number);
		
	std::cout << line + "\n";

}
void Languages::Javascript(std::string line, unsigned line_number) {
    if(stringtools::ltrim(line)[0] == '/' && stringtools::ltrim(line)[1] == '/')
        line = STR(WLIGHT_BLACK_COLOR) + line + STR(WBOLD_LIGHT_WHITE_COLOR);

	stringtools::replaceAll(line, "var ", STR(WBOLD_BLUE_COLOR) + "var " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "const ", STR(WBOLD_BLUE_COLOR) + "const " + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "let ", STR(WBOLD_BLUE_COLOR) + "let " + STR(WBOLD_LIGHT_WHITE_COLOR));
	
	stringtools::replaceAll(line, "new", STR(WBOLD_BLUE_COLOR) + "new" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "function", STR(WBOLD_RED_COLOR) + "function" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "for", STR(WBOLD_RED_COLOR) + "for" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "while", STR(WBOLD_RED_COLOR) + "while" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "do", STR(WBOLD_RED_COLOR) + "do" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "break", STR(WBOLD_BLUE_COLOR) + "break" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "return", STR(WBOLD_BLUE_COLOR) + "return" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "continue", STR(WBOLD_BLUE_COLOR) + "continue" + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "if", STR(WBOLD_CYAN_COLOR) + "if" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "else", STR(WBOLD_CYAN_COLOR) + "else" + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "console", STR(WBOLD_CYAN_COLOR) + "console" + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "switch", STR(WBOLD_CYAN_COLOR) + "switch" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "case", STR(WBOLD_CYAN_COLOR) + "case" + STR(WBOLD_LIGHT_WHITE_COLOR));

	stringtools::replaceAll(line, "try", STR(WBOLD_RED_COLOR) + "try" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "catch", STR(WBOLD_RED_COLOR) + "catch" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "throw", STR(WBOLD_RED_COLOR) + "throw" + STR(WBOLD_LIGHT_WHITE_COLOR));
	stringtools::replaceAll(line, "finally", STR(WBOLD_RED_COLOR) + "finally" + STR(WBOLD_LIGHT_WHITE_COLOR));

	line = Predefined(line);
	
	Line(line_number);
		
	std::cout << line + "\n";
}
