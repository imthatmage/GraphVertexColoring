#include <filesystem>
#include <iostream>
#include <fstream>
#include <chrono>
#include "iterative_algorithm.hpp"

namespace fs = std::filesystem;

int main()
{
    size_t itera_count = 5;
    size_t part_count = 20;
    std::ofstream outputData("result.dat");

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
        auto helper = Graph;
        inputData.close();
        size_t best_result = 5000000000000;
        size_t best_color = 50000000000000;
        graph best_graph = helper;
        for(size_t k = 0; k < itera_count; ++k)
            for (size_t i = 0; i < part_count; ++i)
            {
                auto start = std::chrono::high_resolution_clock::now();
                Graph = helper;
                Graph.assign(assign_graph, i);
                iterative_algorithm::algorithm(Graph);
                auto stop = std::chrono::high_resolution_clock::now();
                auto curr_result = std::chrono::duration_cast<std::chrono::seconds>(stop - start).count();
                if (curr_result < best_result)
                    best_result = curr_result;
                std::cout << std::endl;

                //checking correctness
                std::cout << "Colors: " << Graph.get_chromatic_number() << std::endl;
                if (Graph.get_chromatic_number() < best_color)
                {
                    best_color = Graph.get_chromatic_number();
                    best_graph = Graph;
                }
                iterative_algorithm::improve(Graph, 50);
                auto colors = Graph.get_colors();
                //std::for_each(colors.begin(), colors.end(), [](auto elem) { static size_t i = 0; std::cout << (i++)%1000 << ' ' << elem << std::endl; });
                for (size_t i = 0; i < vertexes; ++i)
                {
                    for (auto neigh : Graph.get_vertex(i))
                        if (colors[neigh] == colors[i])
                            std::cout << "Atas";
                }
                std::cout << std::endl;
            }
        outputData << inputfile.substr(51) << '\t' << best_color << std::endl;// <<'\t' << best_result << "*10^-6 sec" << std::endl;
    }
    outputData.close();
}