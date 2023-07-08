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

Node findNearestCoordinates(const std::vector<Node>& nodes, size_t targetNumber)
{
    Node nearestNode = {0, 0.0, 0.0};
    double minDistance = std::numeric_limits<double>::max();

    for (const auto& node : nodes)
    {
        if (node.number == targetNumber)
        {
            nearestNode = node;
            break;
        }
        double distance = std::sqrt(std::pow(node.x - nearestNode.x, 2) + std::pow(node.y - nearestNode.y, 2));
        if (distance < minDistance)
        {
            minDistance = distance;
            nearestNode = node;
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

    size_t inputNumber;
    std::cout << "Enter node number: ";
    if (!(std::cin >> inputNumber))
    {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }

    Node nearestCoordinates = findNearestCoordinates(nodes, inputNumber);

    std::cout << "Nearest coordinates: " << nearestCoordinates.x << " " << nearestCoordinates.y << std::endl;

    return 0;
}