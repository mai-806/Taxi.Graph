#include "Graph.hpp"

class ShortestPath
{
private:
    std::vector<long double> times;
    std::vector<bool> visited;
    std::vector<size_t> prevVertices;
    size_t numberOfVertices;
    size_t sourceVertex;
public:
    ShortestPath(const Graph &graph, size_t source);
    void dijkstra(const Graph &graph);
    std::vector<size_t> getPath(size_t destination) const;
    long double getTime(size_t vertex) const;
};

ShortestPath::ShortestPath(const Graph &graph, size_t source)
{
    numberOfVertices = graph.graph.size();
    sourceVertex = source;
    times.resize(numberOfVertices, std::numeric_limits<long double>::infinity());
    visited.resize(numberOfVertices, false);
    prevVertices.resize(numberOfVertices, numberOfVertices);
    times[sourceVertex] = 0;
    dijkstra(graph);
}

void ShortestPath::dijkstra(const Graph &graph)
{
    std::priority_queue<std::pair<long double, size_t>, std::vector<std::pair<long double, size_t>>, std::greater<>> pq;
    pq.push({0, sourceVertex});

    while (!pq.empty())
    {
        auto [time, elem] = pq.top();
        pq.pop();

        if (visited[elem]) continue;

        visited[elem] = true;

        for (auto &i : graph.graph[elem])
        {
            if (time + i.distance / (i.maxSpeed * i.traffic) < times[i.numberOfNode])
            {
                times[i.numberOfNode] = time + i.distance / (i.maxSpeed * i.traffic);
                pq.push({times[i.numberOfNode], i.numberOfNode});
                prevVertices[i.numberOfNode] = elem;
            }
        }
    }
}

long double ShortestPath::getTime(size_t vertex) const
{
    return times[vertex];
}

std::vector<size_t> ShortestPath::getPath(size_t destination) const
{
    std::vector<size_t> path;
    size_t currentVertex = destination;
    while (currentVertex != sourceVertex)
    {
        path.push_back(currentVertex);
        currentVertex = prevVertices[currentVertex];
    }
    path.push_back(sourceVertex);
    std::reverse(path.begin(), path.end());
    return path;
}