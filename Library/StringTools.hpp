/*# MIT License
# Forked from https://github.com/ferhatgec/stringtools
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef STRING_TOOLS_HPP
#define STRING_TOOLS_HPP

#include <iostream>
#ifdef _MSC_VER
#include <string>  // VisualC++
#else
#include <cstring>  // Otherwise
#endif

namespace stringtools {
	static std::string EraseAllSubString(std::string & mainString, const std::string & erase) {
    		size_t pos = std::string::npos;
   		while((pos = mainString.find(erase)) != std::string::npos) {
        		mainString.erase(pos, erase.length());
  		}
  		return mainString;
  	}

	
	static std::string FindStringWithReturn(std::string file, std::string str) {
		std::string line;
    		std::ifstream readfile(file.c_str());
    		if(readfile.is_open()) {
        	while (std::getline(readfile, line)) {
			if(strstr(line.c_str(), str.c_str()))
				return line + "\n";
        	}
        	readfile.close();
    		} else {
        		return "error"; /* Unable to open file */
    		}
    		return "null"; /* Not found. */
    	}

	static void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    		if(from.empty())
        		return;
    		size_t start_pos = 0;
    		while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        		str.replace(start_pos, from.length(), to);
        		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    		}
	}
	
	static bool replace(std::string& str, const std::string& from, const std::string& to) {
    		size_t start_pos = str.find(from);

    		if(start_pos == std::string::npos)
        		return false;
    		
    		str.replace(start_pos, from.length(), to);
    		return true;
	}

  	static int IntConverter(const char *s) {
  		int sum = 0;
  		char ch;
  		char sign = *s;
 		if (*s == '-' || *s == '+') s++;
  		while ((ch = *s++) >= '0' && ch <= '9') {
    			sum = sum * 10 - (ch - '0');
  		}
  		if (sign != '-') {
    			sum = -sum;
  		}
  		return sum;
	}

	static int IntConverterWithWhitespace(char* s) {
		int sum = 0;
  		char ch;
  		std::string conv(s);
  		s = const_cast<char*>(EraseAllSubString(conv, " ").c_str());
 		char sign = *s;
 		if (*s == '-' || *s == '+') s++;
  		while ((ch = *s++) >= '0' && ch <= '9') {
    			sum = sum * 10 - (ch - '0');
  		}
  		if (sign != '-') {
    			sum = -sum;
  		}
  		return sum;
	}

	static int Count(std::string s, char ch) {
  		int count = 0;

	 	for (int i = 0; i < s.size(); i++)
    			if (s[i] == ch) count++;

  		return count;
	}

	static int Counter(const char* str, int type) { // 1 = Vowel, 2 = Consonants, 3 = Numbers, 4 = Special characters
		int v = 0, c = 0, n = 0, s = 0;
		for (int i = 0; str[i]!='\0'; ++i) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
			str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
					++v;
			else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
					++c;
	    else if (str[i] >= '0' && str[i] <= '9')
		  		++n;
		  else
					++s;
		}

		if(type == 1)
			return v;
		else if(type == 2)
			return c;
		else if(type == 3)
			return n;
		else if(type == 4)
			return s;
		else
			return v;

		return 0;
	}

	static std::string GetBetweenString(std::string oStr, std::string sStr1, std::string sStr2) {
    		int start = oStr.find(sStr1);
    		if (start >= 0) {
     			std::string tstr = oStr.substr(start + sStr1.length());
      			int stop = tstr.find(sStr2);
      			if (stop >1)
        			return oStr.substr(start + sStr1.length(), stop);
      			else
        			return "error";
    		}
    		else
       		return "error";
	}

	static void GetBtwString(std::string oStr, std::string sStr1, std::string sStr2, std::string &rStr) {
    		int start = oStr.find(sStr1);
    		if (start >= 0) {
      		std::string tstr = oStr.substr(start + sStr1.length());
      		int stop = tstr.find(sStr2);
      		if (stop >1)
        		rStr = oStr.substr(start + sStr1.length(), stop);
      		else
        		rStr ="error";
    		}
    		else
       		rStr = "error";
	}

	static std::string Add(std::string a, std::string b) {
    		std::string temp = "";

    		int carry = 0;

    		while (a.length() < b.length()) {
    		    a = "0" + a;
    		}

    		while (b.length() < a.length()) {
    		    b = "0" + b;
    		}

    		for (int i = a.length() - 1; i >= 0; i--) {
    		    char val = static_cast<char>(((a[i] - 48) + (b[i] - 48)) + 48 + carry);
        		if (val > 57) {
        		    carry = 1;
        		    val -= 10;
        		} else {
        		    carry = 0;
        		}
        	  	temp = val + temp;
    		}

   	 	if (carry == 1) {
        		temp = "1" + temp;
    		}

    		while (temp[0] == '0' && temp.length() > 1) {
        		temp = temp.substr(1);
    		}

		return temp;
	}
	
	static int Compare(const char* str_1, const char* str_2) {
		const unsigned char *unsigned_str_1 = (const unsigned char *) str_1;
		const unsigned char *unsigned_str_2 = (const unsigned char *) str_2;

		while (*unsigned_str_1 == *unsigned_str_2 && 
			*unsigned_str_1 != '\0') {
    		
			unsigned_str_1++;
    			unsigned_str_2++;
  		}

  		return (*unsigned_str_1 > *unsigned_str_2) - (*unsigned_str_1 < *unsigned_str_2);
	}

    static inline std::string ltrim(std::string s) {
        return s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
    }
}

#endif // STRING_TOOLS_HPP
