#include "../include/Graph.hpp"

size_t Edge::get_node() {
    return this->numberOfNode;
}

double Edge::get_distance() {
    return this->distance;
}

int Edge::get_speed() {
    return this->maxSpeed;
}

int Edge::get_traffic() {
    return this->traffic;
}

void Graph::fillingGraph(const std::string &file)
{
    std::ifstream readFile(file);

    if (readFile.is_open())
    {
        Edge elem;
        std::string line;
        size_t whereFrom;
        bool directionOfMovement;
        std::getline(readFile, line);
        size_t numberOfNodes = std::stoull(line);
        std::getline(readFile, line);
        size_t numberOfEdges = std::stoull(line);
        graph.resize(numberOfNodes);
        while (--numberOfEdges)
        {
            std::getline(readFile, line);
            std::stringstream ss(line);
            ss >> whereFrom >> elem.numberOfNode >> elem.distance >> elem.maxSpeed >> elem.traffic >> directionOfMovement;
            graph[whereFrom].push_front(elem);
            if (directionOfMovement)
            {
                size_t tempNumberOfNode = elem.numberOfNode;
                elem.numberOfNode = whereFrom;
                graph[tempNumberOfNode].push_front(elem);
            }
        }

        readFile.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
        return;
    }
}
