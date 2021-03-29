#include "greedy.hpp"
#include <iostream>

int main()
{
    std::vector<std::list<size_t>> graph(7);
    graph[0] = { 1, 3, 4 };
    graph[1] = { 0, 3, 6 };
    graph[2] = { 3, 5 };
    graph[3] = { 0, 1, 2, 6 };
    graph[4] = { 0, 5 };
    graph[5] = { 2, 4, 6 };
    graph[6] = { 1, 3, 5 };
    auto result = greedy(graph);
    for (auto& tmp : result)
        std::cout << tmp.first << ' ' << tmp.second << std::endl;
}