#include "../include/Coordinates.hpp"
#include "../include/Graph.hpp"

int main()
{
    Graph graph;
    Coordinates coords;
    std::string fileForGraph = "../filesForGraph/edges_w_speeds.txt";
    std::string fileForCoords = "../filesForGraph/vertexes.txt";
    graph.fillingGraph(fileForGraph);
    coords.fillingCoord(fileForCoords);
    
}