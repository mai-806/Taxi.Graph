#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>

std::vector<std::pair<double, double>> fillingCoord(const std::string &file) {
     std::ifstream readFile(file);
     std::vector<std::pair<double, double>> coords;

    if (readFile.is_open()) {
        
        std::string line;
        std::getline(readFile, line);
        size_t numberOfNodes = std::stoull(line);
        size_t currentNode;
        std::pair<double, double> elem;
        while (--numberOfNodes)
        {
            std::getline(readFile, line);
            std::stringstream ss(line);
            ss >> currentNode >> elem.first >> elem.second;
            coords.push_back(elem);
        }

        readFile.close();
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }
    return coords;
}
