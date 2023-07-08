#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <forward_list>

class Edge{
private:
    size_t numberOfNode;
    double distance;
    int maxSpeed;
    int traffic;
public:
    Edge() = default;
    ~Edge() = default;
    friend class Graph;
};

class Graph
{
public:
    std::vector<std::forward_list<Edge>> graph;
public:
    Graph() = default;
    ~Graph() = default;
    void fillingGraph(const std::string &file);
};

#include "Graph.cpp"

#endif //GRAPH_HPP
