#pragma once
#include "bitset.h"

namespace alm
{
    class Graph final
    {
    public:
        Graph(size_t _size) : size_(_size), graph(std::vector<alm::BITSET>(_size))
        {
            size_t num_blocks = size_ / N + 1;
            size_t last_blocks_elems = size_ % N;
            std::for_each(graph.begin(), graph.end(), [num_blocks, last_blocks_elems](alm::BITSET& elem) { elem = alm::BITSET(num_blocks, last_blocks_elems); });
        }
        alm::BITSET& operator[](size_t p)
        {
            return graph[p];
        }
        size_t size()
        {
            return size_;
        }
    private:
        std::vector<alm::BITSET> graph;
        size_t size_;
    };
}

