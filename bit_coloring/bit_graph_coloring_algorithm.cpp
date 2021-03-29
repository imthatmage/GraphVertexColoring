#include "bit_graph_coloring_algorithm.hpp"

std::pair<std::vector<size_t>, size_t> fast_graph_coloring(alm::Graph Graph)
{
    std::vector<size_t> colors(Graph.size());
    size_t curr_color = 1;
    size_t parts = Graph.size() / N + 1;

    for (size_t i = 0; i < Graph.size(); ++i)
    {
        if (colors[i] == 0)
        {
            colors[i] = curr_color;
            size_t p = 0;
            while (true)
            {
                if (p == parts) { break; }
                int bitindex = Graph[i].get_first_index(p);

                if (bitindex == -1)
                {
                    ++p; continue;
                }

                if (colors[p * N + bitindex] != 0)
                {
                    Graph[i].set_value(1, p, bitindex);
                }
                else
                {
                    Graph[i].unite(Graph[p * N + bitindex], p);
                    colors[p * N + bitindex] = curr_color;
                }
            }
            ++curr_color;
        }
    }
    return { colors, --curr_color };
}