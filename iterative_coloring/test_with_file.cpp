#include <iostream>
#include <fstream>
#include <chrono>
#include "iterative_algorithm.hpp"

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::string inputfile = "C:/Users/nurma/Documents/repos/graph_coloring/data/gc_1000_7";
    std::string outputfile = "tmp_result.dat";

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
    std::ofstream outputData(outputfile);

    iterative_algorithm::algorithm(Graph);
    auto stop = std::chrono::high_resolution_clock::now();
    auto curr_result = std::chrono::duration_cast<std::chrono::seconds>(stop - start).count();  
    std::cout << std::endl;

    //std::for_each(colors.begin(), colors.end(), [](auto elem) { static size_t i = 0; std::cout << i++ << ' ' << elem << std::endl; });

    //checking correctness
    std::cout << "Colors: " << Graph.get_chromatic_number() << std::endl;
    iterative_algorithm::improve(Graph, 50);
    auto colors = Graph.get_colors();
    std::for_each(colors.begin(), colors.end(), [](auto elem) { static size_t i = 0; std::cout << i++ << ' ' << elem << std::endl; });
    for (size_t i = 0; i < vertexes; ++i)
    {
        for (auto neigh : Graph.get_vertex(i))
            if (colors[neigh] == colors[i])
                std::cout << "Atas";
    }

    std::cout << "Colors: " << Graph.get_chromatic_number() << std::endl;
    std::cout << "Time: " << curr_result << " seconds" << std::endl;
}