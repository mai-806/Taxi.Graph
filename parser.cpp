#include "pugixml/src/pugixml.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <forward_list>

class Node {
    // Долгота и ширина
    std::string lat;
    std::string lon;
    std::forward_list<std::string> paths; // Односвязный список путей из вершины.
                                          // Потом строку с id заменить на пару (id, leghth)
public:
    Node(std::string _lat, std::string _lon) {
        lat = _lat;
        lon = _lon;
    }
    ~Node() = default;
};

int main() {
    std::string path = "pugixml-1.13/docs/samples/tree.xml";

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("map.xml");

    std::vector<std::string> edges;
    std::unordered_map<std::string, Node*> graph;

    pugi::xml_node map = doc.child("osm");

    for (pugi::xml_node node : map.children("node")) {
        graph[node.attribute("id").value()] = new Node(node.attribute("lat").value(), node.attribute("lat").value());
    }
    std::cout << graph.size() << std::endl;

    for (pugi::xml_node relation : map.children("relation")) {
        edges.push_back(relation.attribute("id").value());
        // Здесь заполняем форвард листы
    }
    std::cout << edges.size() << std::endl;

    return 0;
}
