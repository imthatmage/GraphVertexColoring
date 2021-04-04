#include <iostream>
#include "bit_graph_coloring_algorithm.h"

int main()
{
    size_t edges, vertexes;
    std::cout << "Give me number of edges and vertexes: ";
    std::cin >> edges >> vertexes;
    alm::Graph graph = alm::Graph(vertexes);
    std::cout << std::endl << "Number of bits in block: " << N << std::endl;
    //assign graph
    for (size_t i = 0; i < edges; ++i)
    {
        size_t a, b;
        std::cin >> a >> b;
        size_t t1_index = (b - 1) / N;
        size_t t2_index = (b - 1) - N * t1_index;
        graph[a - 1].set_value(1, t1_index, t2_index);
        graph[b - 1].set_value(1, t1_index, t2_index);

        t1_index = (a - 1) / N;
        t2_index = (a - 1) - N * t1_index;
        graph[b - 1].set_value(1, t1_index, t2_index);
        graph[a - 1].set_value(1, t1_index, t2_index);
    }
    auto result = fast_graph_coloring(graph);
    std::cout << "Number of colors: " << result.second << std::endl;
    std::for_each(result.first.begin(), result.first.end(), [](auto& elem) { static size_t i = 0; std::cout << ++i << ": " << elem << std::endl; });
}