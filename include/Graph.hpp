#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <forward_list>

class Edge {
    friend class Graph;
private:
    size_t numberOfNode;
    double distance;
    int maxSpeed;
    int traffic;
public:
    Edge() = default;
    ~Edge() = default;

    size_t get_node();
    double get_distance();
    int get_speed();
    int get_traffic();
};

class Graph {
public:
    std::vector<std::forward_list<Edge>> graph;
    Graph() = default;
    ~Graph() = default;
    void fillingGraph(const std::string &file);

};

#include "../src/Graph.cpp"

#endif //GRAPH_HPP
