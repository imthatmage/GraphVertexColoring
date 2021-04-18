#include <filesystem>
#include <iostream>
#include <fstream>
#include <chrono>
#include "iterative_algorithm.hpp"

namespace fs = std::filesystem;

int main()
{
    std::ofstream outputData("result.dat");
    size_t itera_count = 5;
    for (auto& inputfilepath : fs::directory_iterator("C:/Users/nurma/Documents/repos/graph_coloring/data"))
    {
        std::string inputfile = inputfilepath.path().string();
        std::ifstream inputData(inputfile);
        size_t edges, vertexes;

        if (!inputData.is_open())
        {
            std::cout << "Can't read this file!";
            return -1;
        }
        inputData >> vertexes >> edges;
        std::cout << edges << ' ' << vertexes << std::endl;
        graph Graph(vertexes);
        //assign graph
        std::vector<vertex> assign_graph;
        for (size_t i = 0; i < vertexes; ++i)
        {
            assign_graph.push_back(vertex(i));
        }

        for (size_t i = 0; i < edges; ++i)
        {
            size_t a, b;
            inputData >> a >> b;
            assign_graph[a].push_back(b);
            assign_graph[b].push_back(a);
        }
        Graph.assign(assign_graph);
        inputData.close();
        size_t best_result = 500000;

        auto start = std::chrono::high_resolution_clock::now();
        iterative_algorithm::algorithm(Graph);
        auto stop = std::chrono::high_resolution_clock::now();
        auto curr_result = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        if (curr_result < best_result)
            best_result = curr_result;
        outputData << inputfile.substr(51) << '\t' << Graph.get_chromatic_number() <<'\t' << best_result << "*10^-6 sec" << std::endl;
    }
    outputData.close();
}