#include "greedy.hpp"

size_t get_first_available(const std::set<size_t>& colors)
{
    size_t index = 1;
    while (1)
    {
        if (colors.find(index) != colors.end())
            ++index;
        else
            return index;
    }
}

std::pair<std::map<size_t, size_t>, size_t> greedy(const std::vector<std::list<size_t>> Graph)
{
    std::map<size_t, size_t> colors;
    size_t colors_count = 0;
    for (size_t i = 0; i < Graph.size(); ++i)
    {
        std::set<size_t> colors_curr;
        for (const auto& ngb : Graph[i])
            if (colors.find(ngb) != colors.end())
                colors_curr.insert(colors[ngb]);
        colors[i] = get_first_available(colors_curr);
        if(colors[i] > colors_count)
            colors_count = colors[i];
    }
    return { colors, colors_count };
}

