#include "iterative_algorithm.hpp"
#include <set>

namespace
{
    int get_first_available(const std::set<size_t>& setter, size_t max)
    {
        for (int i = 1; i < (max + 1); ++i)
        {
            if (setter.find(i) == setter.end())
                return i;
        }
        return -1;
    }
}


void iterative_algorithm::algorithm(graph& Graph)
{
    Graph.sort();
    size_t color = 1;
    std::set<size_t> curr_colored;
    auto itera = Graph.begin();
    Graph.initialize_color_vertex();
    while (true)
    {
        if (!itera->find(curr_colored))
        {
            curr_colored.insert(itera->get_id());
            Graph.set_color(itera->get_id(), color);
            itera = Graph.erase(itera);
        }
        else
        {
            ++itera;
        }
        if (itera == Graph.end())
        {
            if (Graph.is_empty())
            {
                break;
            }
            else
            {
                curr_colored.clear();
                itera = Graph.begin();
                Graph.initialize_color_vertex();
                ++color;
            }
        }
    }
    Graph.set_chromatic_number(color);
}


//no need actually
void iterative_algorithm::improve(graph& Graph, size_t max_time)
{
    for (size_t i = 0; i < max_time; ++i)
    {
        auto vert = Graph.get_vertexes(Graph.get_chromatic_number() - 1);

        std::set<size_t> curr_colors;
        size_t max_curr_color = 1;
        for (auto neigh : vert)
        {
            for (auto add_neigh : Graph.get_vertex(neigh))
            {
                auto clr = Graph.get_colors()[add_neigh];
                if (clr > max_curr_color)
                    max_curr_color = clr;
                curr_colors.insert(clr);
            }
        }
        auto color = get_first_available(curr_colors, max_curr_color);
        if (color == -1)
            return;
        else
        {
            for (auto neigh : vert)
            {
                Graph.set_color(neigh, color);
            }
        }
        Graph.set_chromatic_number(Graph.get_chromatic_number() - 1);
    }
}