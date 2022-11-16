/**
 *

    Takes three arguments
        source file name
        destination file name
        pattern to match in double quotes
        ex: marktext input_file output_file "TODO"
    all instances of the pattern in the input file need to be converted to ""<--pattern-->" (without the double quotes in the output file.

So a file with one line of:
"This is a test of marking TODO"
Will get changed to:
"This is a test of marking <--TODO-->"

**/

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cstddef>

//thinking of either having a specific global var that this will update or add to...
//OR I could just have it either return the edited line or a 0 <-kinda like this
std::string pattern_add_in_line(std::string line, std::string pat){

	//check within line that pattern exists within it
	/**
	 * int *i = strstr(line, pat)
	 * int j = 0;
	 * std::string target = "";
	 *while(line[i] == pat[j]){
	 	strcat(target, line[i]);
	 }*/
	//std::string isolated_pattern = line.substr
	if(line.find(pat)){

		line.append("<--",line.at(line.find(pat.c_str()) -1));
		line.append("-->",line.at(line.find(pat.c_str()) + strlen(pat.c_str())-1));
	}
	return line;	
}

int main(int argc, char** argv){

	std::string file_name = argv[1];
	std::string dest_name = argv[2];
	std::string pattern = argv[3];

	std::string line = "hello world";
	std::string result = pattern_add_in_line(line, "hello");
	std::cout << result;
}
