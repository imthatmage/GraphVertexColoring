#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <filesystem>
#include "bit_graph_coloring_algorithm.h"
namespace fs = std::filesystem;

int main()
{
    std::ofstream outputData("result.dat");
    size_t itera_count = 10;
    std::cout << std::endl << "Number of bits in block: " << N << std::endl;
    for(auto& inputfilepath: fs::directory_iterator("/home/almir/Documents/source/repos/graph_coloring/data"))
    {
        const std::string inputfile = inputfilepath.path().string();
        std::ifstream inputData(inputfile);

        size_t edges, vertexes;

        if (!inputData.is_open())
        {
            std::cout << "Can't read this file!";
            return -1;
        }
        std::cout << inputfile << std::endl;
        inputData >> vertexes >> edges;
        std::cout << edges << ' ' << vertexes << std::endl;
        alm::Graph graph = alm::Graph(vertexes);
        

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
        size_t best_result = 500;
        std::pair<std::vector<size_t>, size_t> result;
        for(size_t p = 0; p < itera_count; ++p)
        {
            auto start = std::chrono::high_resolution_clock::now();
            result = fast_graph_coloring(graph);
            auto stop = std::chrono::high_resolution_clock::now();
            auto curr_result = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
            if(curr_result < best_result)
                best_result = curr_result;
        }
        outputData << inputfile.substr(55) << ' ' << result.second << "               " << best_result << "*10^-6 seconds" << std::endl; 
    }
    outputData.close();
}