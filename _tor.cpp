#include <sw/redis++/redis++.h>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "_tor.h"

std::string to_string_with_precision(double a_value, const int n = 7)
{
	std::ostringstream out;
	out.precision(n);
	out << std::fixed << a_value;
	return std::move(out).str();
}

using namespace sw::redis;
void vtor(std::string path){
	std::ifstream file(path);
	if(file.is_open()){
		std::cout << "opened file: " << path << std::endl;
	}else{
		std::cout << "no such file was found" << std::endl;
		return;
	}
	long double lat, lon;
	size_t trash;
	size_t N;
	file >> N;
	//auto r = sw::redis::Redis("redis://127.0.0.1");
	Redis r("tcp://127.0.0.1:6379/0");
	std::unordered_map<std::string, std::string> results;
	
	std::cout << "processing..." << std::endl;
	for (int i = 0; i < N; ++i) {
		file >> trash >> lat >> lon;
		results.insert({"lat", to_string_with_precision(lat)});
		results.insert({"lon", to_string_with_precision(lon)});
		r.hmset(std::to_string(i), results.begin(), results.end());
		results.clear();
		if(i%10000 == 0 || i == N-1){ std::cout << i << std::endl;} //just checking
	}
	file.close();
}

void etor(std::string path){
	std::ifstream file(path);
	if(file.is_open()){
		std::cout << "opened file: " << path << std::endl;
	}else{
		std::cout << "no such file was found" << std::endl;
		return;
	}
	size_t start, end;
	double way_length;
	size_t max_speed, traffic;
	bool bilateral;
	std::string street_name;
	
	size_t N;
	file >> N >> N;
	//auto r = sw::redis::Redis("redis://127.0.0.1");
	Redis r("tcp://127.0.0.1:6379/1");
	std::unordered_map<std::string, std::string> results;
	
	std::cout << "processing..." << std::endl;
	for(int i = 0; i < N; i++){
		file >> start >> end >> way_length >> max_speed >> traffic >> bilateral;
		std::getline(file, street_name, '\n');
		results.insert({"street", street_name});
		results.insert({"bilateral", std::to_string(bilateral)});
		results.insert({"traffic", std::to_string(traffic)});
		results.insert({"speed", std::to_string(max_speed)});
		results.insert({"length", std::to_string(way_length)});
		results.insert({"destination", std::to_string(end)});
		results.insert({"origin", std::to_string(start)});
		r.hset(std::to_string(i), results.begin(), results.end());
		results.clear();
		if(i%10000 == 0 || i == N-1){ std::cout << i << std::endl;} //just checking
		
	}
	file.close();
}