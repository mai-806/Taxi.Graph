#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <forward_list>

class ElemOfVector
{
private:
    size_t numberOfNode;
    long double distance;
public:
    ElemOfVector() = default;
    ~ElemOfVector() = default;
    friend class Graph;
};

class Graph
{
private:
    std::vector<std::forward_list<ElemOfVector>> graph;
public:
    Graph() = default;
    ~Graph() = default;
    void fillingGraph(const std::string &file);
};

#include "Graph.cpp"

#endif //GRAPH_HPP
