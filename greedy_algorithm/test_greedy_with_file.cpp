#include "greedy.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::string inputfile = "/home/almir/Documents/source/repos/graph_coloring/data/gc_1000_9";
    std::string outputfile = "result";

    std::ifstream inputData(inputfile);
    if(!inputData.is_open())
    {
        std::cout << "Can't open this file!";
        return -1;
    }
    size_t edges, vertexes;
    inputData >> vertexes >> edges;
    std::vector<std::list<size_t>> graph(vertexes);
    //assign graph
    for (size_t i = 0; i < edges; ++i)
    {
        size_t a, b;
        inputData >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    inputData.close();

    auto result = greedy(graph);
    std::cout << std::endl;
    size_t colors = 1;

    std::ofstream myfile(outputfile + ".dat");
    auto stop = std::chrono::high_resolution_clock::now();
    for (auto& tmp : result)
    {
        colors = tmp.second > colors ? tmp.second : colors;
    }
    myfile << "colors: " << colors << " time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    myfile.close();
}