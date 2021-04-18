#pragma once
#include "vertex.hpp"
#include <list>
#include <algorithm>
#include <vector>

class graph final
{
public:
    graph(size_t size) : size_(size), colors(size) {}

    void sort()
    {
        working.sort();
    }
    size_t size() { return size_; }

    std::list<vertex>::iterator begin()
    {
        return working.begin();
    }

    std::list<vertex>::iterator end()
    {
        return working.end();
    }

    void assign(std::vector<vertex>& hgraph)
    {
        for (auto& vert : hgraph)
            working.push_back(vert);
        adjacent = std::move(hgraph);
    }

    auto erase(std::list<vertex>::iterator& itera)
    {
        return working.erase(itera);
    }

    void set_color(size_t id, size_t color)
    {
        color_vertexes[color - 1].push_back(id);
        colors[id] = color;
    }

    bool is_empty()
    {
        return working.size() == 0;
    }

    const std::vector<size_t>& get_colors()
    {
        return colors;
    }

    void initialize_color_vertex()
    {
        color_vertexes.push_back(std::vector<size_t>());
    }

    //returns vertexes colored with i
    std::vector<size_t> get_vertexes(size_t i)
    {
        return color_vertexes[i];
    }
    vertex& get_vertex(size_t i )
    {
        return adjacent[i];
    }

    void set_chromatic_number(size_t num)
    {
        chromatic_number = num;
    }

    size_t get_chromatic_number()
    {
        return chromatic_number;
    }
    
private:
    size_t chromatic_number = -1;
    size_t size_ = 0;
    //working vertex storage
    std::list<vertex> working;
    //colors[i] color of i vertex
    std::vector<size_t> colors;
    //color_vertexes[i] vector with vertexes colored with i
    std::vector<std::vector<size_t>> color_vertexes;
    std::vector<vertex> adjacent;
};