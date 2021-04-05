#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "bit_graph_coloring_algorithm.h"

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::string inputfile = "data/gc_1000_9";
    std::string outputfile = inputfile + "result";

    std::ifstream inputData(inputfile);

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
    //auto start = std::chrono::high_resolution_clock::now();
    auto result = fast_graph_coloring(graph);   
    auto stop = std::chrono::high_resolution_clock::now();
    std::ofstream myfile(outputfile + ".dat");

    myfile << result.second << std::endl;
    myfile << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " miliseconds execution time" << std::endl;
    myfile << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << " microseconds execution time";

    myfile.close();
    std::cout << "Result saved to: " << outputfile + ".dat";
}

