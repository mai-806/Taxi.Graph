#include "Coordinates.cpp"
#include "distance_utils.cpp"
#include "../include/Graph.hpp"
#include <iostream>
#include <cstddef>
#include <utility>
#include <vector>
#include <set>
#include <float.h>

double a_star(const Graph& g,
        const std::vector<std::pair<double, double>>& coords,
        size_t start,
        size_t end,
        std::vector<size_t>& path) {
    // Returns travel time, saves path in vector

    std::vector<bool> closed_list(coords.size(), false);
    std::set<std::pair<double, size_t>> open_list;
    open_list.insert(std::make_pair(0.0, start));
    std::vector<double> F_list(coords.size(), DBL_MAX);
    double total_time = 0;

    while (!open_list.empty()) {
        std::pair<double, size_t> p = *open_list.begin();
        open_list.erase(open_list.begin());
        closed_list[p.second] = true;
        path.push_back(p.second);
        total_time += p.first - get_distance(coords[p.second], coords[end]) / 50;

        for (auto succ : g.graph[p.second]) {
            if (succ.get_node() == end) {
                // Found end node
                path.push_back(p.second);
                return total_time;
            }
            else if (closed_list[succ.get_node()] == false) {
                double G = succ.get_distance() / (succ.get_speed() * (1 - 0.08 * succ.get_traffic()));
                double H = get_distance(coords[succ.get_node()], coords[end]) / 50; // Divide heuristic by average speed
                double F = G + H;

                if (F_list[succ.get_node()] == DBL_MAX or F_list[succ.get_node()] > F) {
                    open_list.insert(std::make_pair(F, succ.get_node()));
                    F_list[succ.get_node()] = F;
                }
            }
        }
    }
    
    std::cout << "Not found\n";
    return -1;
}
