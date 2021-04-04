#include "greedy.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string inputfile = "gc41";
    std::string outputfile = inputfile + "result";

    std::ifstream inputData(inputfile + ".dat");
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

    for (auto& tmp : result)
    {
        colors = tmp.second > colors ? tmp.second : colors;
        myfile << tmp.first << ' ' << tmp.second - 1 << std::endl;
    }
    myfile.close();
    std::cout << "Number of colors: " << colors << std::endl;
    std::cout << "Result saved to: " << outputfile + ".dat";
}