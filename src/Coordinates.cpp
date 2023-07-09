#include "../include/Coordinates.hpp"

void Coordinates::fillingCoord(const std::string &file)
{
    std::ifstream readFile(file);

    if (readFile.is_open())
    {
        
        std::string line;
        std::getline(readFile, line);
        size_t numberOfNodes = std::stoull(line);
        size_t currentNode;
        Elem elemForPush;
        while (--numberOfNodes)
        {
            std::getline(readFile, line);
            std::stringstream ss(line);
            ss >> currentNode >> elemForPush.lat >> elemForPush.lon;
            coord.push_back(elemForPush);
        }

        readFile.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
        return;
    }
}