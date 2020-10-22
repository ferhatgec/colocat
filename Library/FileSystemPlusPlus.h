/*# MIT License
# Forked from https://github.com/ferhatgec/fsplusplus
# (Removed unused functions)
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef FILE_SYSTEM_PLUS_PLUS_H
#define FILE_SYSTEM_PLUS_PLUS_H

#include <cstring>
#include <iostream>
#include <pwd.h>
#include <dirent.h>
#include <fstream>
#include <sys/stat.h>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#define FS_PLUS_PLUS_VERSION "0.2-beta-1"

namespace fsplusplus {
	static std::string EraseAllSubString(std::string & mainString, const std::string & erase) {
   	 size_t pos = std::string::npos;
   	 while((pos = mainString.find(erase)) != std::string::npos) {
   	     	mainString.erase(pos, erase.length());
   	 }
   		return mainString;
    	}

	static std::string GetCurrentWorkingDir(void) {
  		char buff[FILENAME_MAX];
  		GetCurrentDir( buff, FILENAME_MAX );
  		std::string current_working_dir(buff);
  		return current_working_dir;
	}

	static bool IsExistFile(std::string path) {
    		struct stat buffer;
    		return (stat(path.c_str(), &buffer) == 0);
	}

	static void CreateFile(std::string name, std::string input) {
		std::string path;
    		path.append(fsplusplus::GetCurrentWorkingDir());
    		path.append("/");
    		path.append(name);
    		std::ofstream file(path, std::ios::app);
    		file << input;
    		file.close();
	}
	
	static void CreateFileWithoutAppend(std::string name) {
		std::string path;
    		path.append(fsplusplus::GetCurrentWorkingDir());
    		path.append("/");
    		path.append(name);
    		std::ofstream file(path);
    		file.close();
	}
}

#endif // FILE_SYSTEM_PLUS_PLUS_H
