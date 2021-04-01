#include <iostream>
#include <fstream>
#include <string>
#include "bit_graph_coloring_algorithm.hpp"

int main()
{
    std::string inputfile = "gc41";
    std::string outputfile = inputfile + "result";

    std::ifstream inputData(inputfile + ".dat");

    size_t edges, vertexes;

    if (!inputData.is_open())
    {
        std::cout << "Can't read this file!";
        return -1;
    }
    inputData >> vertexes >> edges;
    std::cout << edges << ' ' << vertexes << std::endl;
    alm::Graph graph = alm::Graph(vertexes);
    std::cout << std::endl << "Number of bits in block: " << N << std::endl;

    //assign graph
    for (size_t i = 0; i < edges; ++i)
    {
        size_t a, b;
        inputData >> a >> b;

        size_t t1_index = b / N;
        size_t t2_index = b - N * t1_index;
        graph[a].set_value(1, t1_index, t2_index);
        graph[b].set_value(1, t1_index, t2_index);

        t1_index = a / N;
        t2_index = a - N * t1_index;
        graph[b].set_value(1, t1_index, t2_index);
        graph[a].set_value(1, t1_index, t2_index);
    }
    inputData.close();
    auto result = fast_graph_coloring(graph);   
    std::ofstream myfile(outputfile + ".dat");

    for (size_t i = 0; i < result.first.size(); ++i)
    {
        myfile << i << ' ' << result.first[i] - 1 << '\n';
    }
    myfile.close();
    std::cout << "Result saved to: " << outputfile + ".dat";
}

