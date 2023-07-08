#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <limits>

struct Node {
    size_t number;
    double x;
    double y;
};

size_t findNearestNode(const std::vector<Node>& nodes, double x, double y)
{
    size_t nearestNode = 0;
    double minDistance = std::numeric_limits<double>::max();

    for (const auto& node : nodes)
    {
        double distance = std::sqrt(std::pow(x - node.x, 2) + std::pow(y - node.y, 2));
        if (distance < minDistance)
        {
            minDistance = distance;
            nearestNode = node.number;
        }
    }

    return nearestNode;
}

int main()
{
    std::ifstream file("file.txt");
    if (!file)
    {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    }

    std::vector<Node> nodes;
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        size_t number;
        double x, y;
        if (iss >> number >> x >> y)
        {
            Node node{number, x, y};
            nodes.push_back(node);
        }
        else
        {
            std::cout << "Invalid line format: " << line << std::endl;
        }
    }

    double inputX, inputY;
    std::cout << "Enter coordinates: ";
    if (!(std::cin >> inputX >> inputY))
    {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }

    size_t nearestNode = findNearestNode(nodes, inputX, inputY);

    std::cout << "Nearest node: " << nearestNode << std::endl;

    return 0;
}