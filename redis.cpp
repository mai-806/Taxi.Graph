#include <sw/redis++/redis++.h>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "_tor.h"

using namespace sw::redis;
int main(int argc, char* argv[] ) {
	if(argc < 3){
		std::cout << "no files given" << std::endl;
		return 1;
	}
	std::string path1 = argv[1];
	std::string path2 = argv[2];
	vtor(path1);
	etor(path2);
	return 0;
}
