#include "Graph.hpp"


void Graph::fillingGraph(const std::string &file)
{
    std::ifstream readFile(file);

    if (readFile.is_open())
    {
        ElemOfVector elem;
        std::string line;
        size_t whereFrom;
        std::getline(readFile, line);
        size_t numberOfNodes = std::stoull(line);
        std::getline(readFile, line);
        size_t numberOfEdges = std::stoull(line);
        graph.resize(numberOfNodes);
        while (--numberOfEdges)
        {
            std::getline(readFile, line);
            std::stringstream ss(line);
            ss >> whereFrom >> elem.numberOfNode >> elem.distance;
            graph[whereFrom].push_front(elem);
        }

        readFile.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
        return;
    }
}
