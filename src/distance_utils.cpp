#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <float.h>

double get_distance(std::pair<double, double> dot_1, std::pair<double, double> dot_2) {
    double earth_radius = 6367449;
    double lat_1 = dot_1.first * M_PI/180; // lat, lon in radians
    double lat_2 = dot_2.first * M_PI/180;
    double delta_lat = (dot_2.first - dot_1.first) * M_PI/180;
    double delta_lon = (dot_2.second - dot_1.second) * M_PI/180;

    double a = std::sin(delta_lat/2) * std::sin(delta_lat/2) + std::cos(lat_1) * std::cos(lat_2) * std::sin(delta_lon/2) * std::sin(delta_lon/2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1-a));

    return earth_radius * c;
}

size_t NNS(std::vector<std::pair<double, double>>& nodes, std::pair<double, double> pos, int pos_idx = -1) {
    double min_dist = DBL_MAX;
    size_t min_idx = 0;
    for (int i = 0; i < nodes.size(); ++i) {
        double dist = get_distance(nodes[i], pos);
        if (dist < min_dist and i != pos_idx) {
            min_dist = dist;
            min_idx = i;
        }
    }
    return min_idx;
}
