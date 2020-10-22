/*# MIT License
# 
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

	// Get Between String    
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


	static void List() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("Error: Directory not found.\n");
        	return;
    	    }
            while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
            	printf("%4s: %s\n", "[Dir]", entryname->d_name);
            	}
            	} else if(strstr(entryname->d_name, "Elitefile")) {
            		printf("%4s: %s\n", "[Elitebuild]", entryname->d_name);
            	} else if(strstr(entryname->d_name, ".scrift_log")) {
	    		printf("%4s: %s\n", "FeLog*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scrift_ascii")) {
			printf("%4s: %s\n", "Ascii Art*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scrift_settings")) {
	    		printf("%4s: %s\n", "Settings*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scrift_history")) {
	    		printf("%4s: %s\n", "History*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scr")) {
            		printf("%4s: %s\n", "[Scrift]", entryname->d_name);
            	} else if(strstr(entryname->d_name, ".cpp") || strstr(entryname->d_name, ".hpp") || 
            		strstr(entryname->d_name, ".cxx") || strstr(entryname->d_name, ".hxx") || 
            		strstr(entryname->d_name, ".cc") || strstr(entryname->d_name, ".hh")) {
            		printf("%4s: %s\n", "[C++]", entryname->d_name);
	    	} else if(strstr(entryname->d_name, ".c") || strstr(entryname->d_name, ".h")) {
            		printf("%4s: %s\n", "[C]", entryname->d_name);		
	    	} else if(strstr(entryname->d_name, "CMakeLists.txt")) {
            		printf("%4s: %s\n", "[CMake]", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".sh")) {
            		printf("%4s: %s\n", "[Bash]", entryname->d_name);
	    	} else if(strstr(entryname->d_name, ".py")) {
            		printf("%4s: %s\n", "[Python]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".fls") || strstr(entryname->d_name, ".flsh")) {
		   	printf("%4s: %s\n", "[FlaScript]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".md")) {
            		printf("%4s: %s\n", "[Markdown]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".frbr")) {
	    		printf("%4s: %s\n", "[FreeBrain]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".png")) {
	    		printf("%4s: %s\n", "[Png]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".jpg") || strstr(entryname->d_name, ".jpeg")) {
	    		printf("%4s: %s\n", "[Jpg]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".gif")) {
	    		printf("%4s: %s\n", "[Gif]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".html") || strstr(entryname->d_name, ".htm")) {
	    		printf("%4s: %s\n", "[Html]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".rs") || strstr(entryname->d_name, ".rslib")) {
	    		printf("%4s: %s\n", "[Rust]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".lua")) {
	    		printf("%4s: %s\n", "[Lua]", entryname->d_name);	
		} else if(strstr(entryname->d_name, ".inclink")) {
	    		printf("%4s: %s\n", "[includeLink]", entryname->d_name);			
		} else {
               		printf("%4s: %s\n", "[File]", entryname->d_name);
           	}
    	  }
   	 closedir(directory);
	}
	
	static void ListFile() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("Error: Directory not found.\n");
        	return;
    	    }
            while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          	// Null
            	}
           	} else if(strstr(entryname->d_name, "Elitefile")) {
            		printf("%4s: %s\n", "[Elitebuild]", entryname->d_name);
            	} else if(strstr(entryname->d_name, ".scrift_log")) {
	    		printf("%4s: %s\n", "FeLog*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scrift_ascii")) {
			printf("%4s: %s\n", "Ascii Art*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scrift_settings")) {
	    		printf("%4s: %s\n", "Settings*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scrift_history")) {
	    		printf("%4s: %s\n", "History*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scr")) {
            		printf("%4s: %s\n", "[Scrift]", entryname->d_name);
            	} else if(strstr(entryname->d_name, ".cpp") || strstr(entryname->d_name, ".hpp") || 
            		strstr(entryname->d_name, ".cxx") || strstr(entryname->d_name, ".hxx") || 
            		strstr(entryname->d_name, ".cc") || strstr(entryname->d_name, ".hh")) {
            		printf("%4s: %s\n", "[C++]", entryname->d_name);
	    	} else if(strstr(entryname->d_name, ".c") || strstr(entryname->d_name, ".h")) {
            		printf("%4s: %s\n", "[C]", entryname->d_name);		
	    	} else if(strstr(entryname->d_name, "CMakeLists.txt")) {
            		printf("%4s: %s\n", "[CMake]", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".sh")) {
            		printf("%4s: %s\n", "[Bash]", entryname->d_name);
	    	} else if(strstr(entryname->d_name, ".py")) {
            		printf("%4s: %s\n", "[Python]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".fls") || strstr(entryname->d_name, ".flsh")) {
		   	printf("%4s: %s\n", "[FlaScript]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".md")) {
            		printf("%4s: %s\n", "[Markdown]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".frbr")) {
	    		printf("%4s: %s\n", "[FreeBrain]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".png")) {
	    		printf("%4s: %s\n", "[Png]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".jpg") || strstr(entryname->d_name, ".jpeg")) {
	    		printf("%4s: %s\n", "[Jpg]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".gif")) {
	    		printf("%4s: %s\n", "[Gif]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".html") || strstr(entryname->d_name, ".htm")) {
	    		printf("%4s: %s\n", "[Html]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".rs") || strstr(entryname->d_name, ".rslib")) {
	    		printf("%4s: %s\n", "[Rust]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".lua")) {
	    		printf("%4s: %s\n", "[Lua]", entryname->d_name);	
		} else if(strstr(entryname->d_name, ".inclink")) {
	    		printf("%4s: %s\n", "[includeLink]", entryname->d_name);			
		} else {
               	printf("%4s: %s\n", "[File]", entryname->d_name);
            	}
    	 }
   	 closedir(directory);
	}
	
	static void ListDirectory() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("Error: Directory not found.\n");
        	return;
    	    }
            while ((entryname = readdir(directory)))
    	    {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          		printf("%4s: %s\n", "[Dir]", entryname->d_name);
            	}
            } else {
               // Null
            }
    	   }
   	 closedir(directory);
	}
	
	static void ListFileDefault() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("Error: Directory not found.\n");
        	return;
    	    }
            while ((entryname = readdir(directory)))
    	    {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          	// Null
            	}
            } else {
               printf("%4s %s\n", entryname->d_name);
            }
    	}
   	 closedir(directory);
	}
	
	static void ListDirectoryDefault() {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
        	printf("Error: Directory not found.\n");
        	return;
    	    }
            while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          		printf("%4s %s\n", entryname->d_name);
            	}
            } else {
               // Null
            }
    	   }
   	 closedir(directory);	
	}
	
	static void ListPath(std::string path) {
	    DIR *directory;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(path.c_str());
    	    if(directory == NULL) {
        	printf("Error: Directory not found.\n");
        	return;
    	    }
            while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
            		printf("%4s: %s\n", "[Dir]", entryname->d_name);
            	}
           	} else if(strstr(entryname->d_name, "Elitefile")) {
            		printf("%4s: %s\n", "[Elitebuild]", entryname->d_name);
            	} else if(strstr(entryname->d_name, ".scrift_log")) {
	    		printf("%4s: %s\n", "FeLog*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scrift_ascii")) {
	    		printf("%4s: %s\n", "Ascii Art*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scrift_settings")) {
	    		printf("%4s: %s\n", "Settings*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scrift_history")) {
	    		printf("%4s: %s\n", "History*", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".scr")) {
            		printf("%4s: %s\n", "[Scrift]", entryname->d_name);
            	} else if(strstr(entryname->d_name, ".cpp") || strstr(entryname->d_name, ".hpp") || strstr(entryname->d_name, ".cxx") || strstr(entryname->d_name, ".hxx") || strstr(entryname->d_name, ".cc") || strstr(entryname->d_name, ".hh")) {
            		printf("%4s: %s\n", "[C++]", entryname->d_name);
	    	} else if(strstr(entryname->d_name, ".c") || strstr(entryname->d_name, ".h")) {
            		printf("%4s: %s\n", "[C]", entryname->d_name);		
	    	} else if(strstr(entryname->d_name, "CMakeLists.txt")) {
            		printf("%4s: %s\n", "[CMake]", entryname->d_name);	
	    	} else if(strstr(entryname->d_name, ".sh")) {
            		printf("%4s: %s\n", "[Bash]", entryname->d_name);
	    	} else if(strstr(entryname->d_name, ".py")) {
            		printf("%4s: %s\n", "[Python]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".fls") || strstr(entryname->d_name, ".flsh")) {
		   	printf("%4s: %s\n", "[FlaScript]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".md")) {
            		printf("%4s: %s\n", "[Markdown]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".frbr")) {
	    		printf("%4s: %s\n", "[FreeBrain]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".png")) {
	    		printf("%4s: %s\n", "[Png]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".jpg") || strstr(entryname->d_name, ".jpeg")) {
	    		printf("%4s: %s\n", "[Jpg]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".gif")) {
	    		printf("%4s: %s\n", "[Gif]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".html") || strstr(entryname->d_name, ".htm")) {
	    		printf("%4s: %s\n", "[Html]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".rs") || strstr(entryname->d_name, ".rslib")) {
	    		printf("%4s: %s\n", "[Rust]", entryname->d_name);
		} else if(strstr(entryname->d_name, ".lua")) {
	    		printf("%4s: %s\n", "[Lua]", entryname->d_name);	
		} else if(strstr(entryname->d_name, ".inclink")) {
	    		printf("%4s: %s\n", "[includeLink]", entryname->d_name);			
		} else {
               		printf("%4s: %s\n", "[File]", entryname->d_name);
            	}
	}
   	 closedir(directory);				
	}

		
	static std::string ListPathWithReturn(std::string path) {
	    DIR *directory;
	    std::string add;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(path.c_str());
    	    if(directory == NULL) {
        	return "null"; // Directory not found.
    	    }
            while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          		add.append(entryname->d_name);
            	}
            } else {
               	add.append(entryname->d_name);
            }
		return add;
    	   }
   	 	closedir(directory);
		return "null";	
	}

	static std::string ListDirectoryWithReturn(std::string path) {
	    DIR *directory;
	    std::string add;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(path.c_str());
    	    if(directory == NULL) {
        	return "null"; // Directory not found.
    	    }
            while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          		add.append(entryname->d_name);
            	}
            } else {
                // Null
            }
		return add;
    	   }
   	    closedir(directory);
	    return "null";
	}
	
	static std::string ListFileWithReturn(std::string path) {
	    DIR *directory;
	    std::string add;
	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(path.c_str());
    	    if(directory == NULL) {
        	return "null"; // Directory not found.
    	    }
            while ((entryname = readdir(directory))) {
        	stat(entryname->d_name, &filestat);
        	if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            	if(strstr(entryname->d_name, ".")) {
            		// Null
            	} else if(strstr(entryname->d_name, "..")){
	    		// Null
	    	} else {  
          		// Null
            	}
            } else {
                add.append(entryname->d_name);
            }
		return add;
    	   }
   	  closedir(directory);
	  return "null";
	}

	static std::string CDFunction(std::string path) {
		return fsplusplus::GetCurrentWorkingDir() + path;
	}
	
	static void ReadFile(std::string file) {
		std::string line;
    		std::ifstream readfile((fsplusplus::GetCurrentWorkingDir() + "/" + file).c_str());
    		if(readfile.is_open()) {
        	while (std::getline(readfile, line)) {
			printf(line.c_str());
			printf("\n");
        	}
        	readfile.close();
    	} else {
        	printf("Unable to open file\n");
    	}
    	}
    	
    	static std::string ReadFileWithReturn(std::string file) {
		std::string line;
    		std::ifstream readfile((fsplusplus::GetCurrentWorkingDir() + "/" + file).c_str());
    		if(readfile.is_open()) {
        	while (std::getline(readfile, line)) {
			return line + "\n";
        	}
        	readfile.close();
    		} else {
        		printf("Unable to open file\n");
    		}
		return "null";
    	}
    	
    	static void FindPath(std::string name) {
    	    DIR *directory;
    	    struct dirent *entryname;
	    struct stat filestat;
    	    directory = opendir(fsplusplus::GetCurrentWorkingDir().c_str());
    	    if(directory == NULL) {
            printf("Error: Directory not found.\n");
            return;
    	    }
    	    while ((entryname = readdir(directory))) {
            stat(entryname->d_name, &filestat);
            if(entryname->d_type == DT_DIR) {
                if(strstr(entryname->d_name, ".")) {
                // Null
                } else if(strstr(entryname->d_name, "..")){
	        // Null
	        } else if(strstr(entryname->d_name, name.c_str())) {  
            	  printf("%4s %s\n", "[Dir]", entryname->d_name);
                }
            } 
            else if(strstr(entryname->d_name, name.c_str())){
                 printf("%4s %s\n", "[File]", entryname->d_name);
            }
            }
   	 closedir(directory);
    	}
    	
    	static void ReadFilePath(std::string path) {
    		std::string line;
    		std::ifstream readfile(path.c_str());
    		if(readfile.is_open()) {
        	while (std::getline(readfile, line)) {
			printf(line.c_str());
			printf("\n");
        	}
        	readfile.close();
    	} else {
        	printf("Unable to open file\n");
    	}
	}
	
	static void ReadCPU() {
    		std::string line;
		#ifdef __FreeBSD__
			std::ifstream readfile("/var/run/dmesg.boot");
		#else     		
			std::ifstream readfile("/proc/cpuinfo");
		#endif    		
		if(readfile.is_open()) {
        	while (std::getline(readfile, line)) {
			#ifdef __FreeBSD__
			if(line.find("CPU: ") == 0) {
				line = EraseAllSubString(line, "CPU: ");
				printf(line.c_str());
				printf("\n");
				return;
        		}
			#else        		
			if(line.find("model name	: ") == 0) {
				line = fsplusplus::EraseAllSubString(line, "model name	: ");
				printf(line.c_str());
				printf("\n");
				return;
        		}
			#endif
        	}
        	readfile.close();
    	} else {
        	printf("Unable to open file\n");
    	}
	}
	
	static void ReadOSName(std::string path) {
		#ifdef __FreeBSD__
		printf("FreeBSD\n");
		#else
    		std::string line;
    		std::ifstream readfile(path.c_str());
    		if(readfile.is_open()) {
        	while (std::getline(readfile, line)) {
        		if(line.find("PRETTY_NAME=\"") == 0) {
				fsplusplus::GetBtwString(line, "\"", "\"", line); 
				printf(line.c_str());
				printf("\n");
        		}
        	}
        	readfile.close();
    		} else {
        		printf("Unable to open file\n");
    		}
		#endif
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
