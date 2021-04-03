#include "greedy.hpp"
#include <iostream>

int main()
{
    size_t edges, vertexes;
    std::cout << "Give me number of edges and vertexes: ";
    std::cin >> edges >> vertexes;
    std::vector<std::list<size_t>> graph(vertexes);
    //assign graph
    for (size_t i = 0; i < edges; ++i)
    {
        size_t a, b;
        std::cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    auto result = greedy(graph);
    std::cout << std::endl;
    size_t colors = 1;
    for (auto& tmp : result)
    {
        colors = tmp.second > colors ? tmp.second : colors;
        std::cout << tmp.first + 1 << ' ' << tmp.second << std::endl;
    }
    std::cout << "Number of colors: " << colors << std::endl;
}