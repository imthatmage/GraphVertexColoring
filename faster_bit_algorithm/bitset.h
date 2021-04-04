#pragma once
#include <bitset>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cassert>

constexpr auto N = 64;

namespace alm
{
    class BITSET
    {
    public:
        BITSET(size_t _length, size_t last_block_elems) : length(_length)
        {
            setbit = std::vector<std::bitset<N>>(length);
            setbit[setbit.size() - 1].flip();
            for (size_t i = 0; i < last_block_elems; ++i)
            {
                setbit[setbit.size() - 1][i] = 0;
            }
        }

        BITSET() : length(0)
        {

        }
        void set_value(bool value, size_t p, size_t pos)
        {
            assert(p < length);
            setbit[p][pos] = value;
        }

        bool get_value(size_t p, size_t pos)
        {
            assert(p < length);
            return setbit[p][pos];
        }

        int get_first_index(size_t p)
        {
            assert(p < length);
            if (setbit[p].all()) return -1;
            return std::bitset<N>(setbit[p]).flip()._Find_first();
        }

        void unite(const BITSET& other, size_t p)
        {
            for (size_t i = p; i < length; ++i)
            {
                setbit[i] |= other[i];
            }
        }

        size_t size()
        {
            return length;
        }

    private:
        std::bitset<N> operator[](size_t p) const
        {
            assert(p < length);
            return setbit[p];
        }

        std::vector<std::bitset<N>> setbit;
        size_t length;
    };
}