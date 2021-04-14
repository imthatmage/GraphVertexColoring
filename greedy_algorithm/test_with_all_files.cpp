#include "greedy.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    std::ofstream outputData("result.dat");
    size_t itera_count = 10;

    for(auto& inputfilepath: fs::directory_iterator("C:/Users/nurma/Documents/repos/graph_coloring/data"))
    {
        const std::string inputfile = inputfilepath.path().string();
        std::ifstream inputData(inputfile);
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
        size_t best_result = 50000000000;
        std::pair<std::map<size_t, size_t>, size_t> result;
        for(size_t p = 0; p < itera_count; ++p)
        {
            auto start = std::chrono::high_resolution_clock::now();
            result = greedy(graph);
            auto stop = std::chrono::high_resolution_clock::now();
            auto curr_result = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
            if(curr_result < best_result)
                best_result = curr_result;
        }
        outputData << inputfile.substr(51) << ' ' << result.second << "               " << best_result << "*10^-6 seconds" << std::endl;
    }
    outputData.close();
}