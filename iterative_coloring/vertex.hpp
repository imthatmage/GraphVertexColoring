#pragma once
#include <set>
#include <algorithm>

class vertex final
{
public:
    vertex(size_t id) : id_(id) { }

    vertex(const vertex& another)
    {
        adjacent = another.adjacent;
        id_ = another.id_;
        size_ = another.size_;
    }

    vertex& operator=(const vertex& another)
    {
        adjacent = another.adjacent;
        id_ = another.id_;
        size_ = another.size_;
        return *this;
    }

    void push_back(size_t adj)
    {
        adjacent.insert(adj);
    }

    //we want to vector to sort by increasing to assign list by decreasing
    bool operator<(const vertex& another)
    {
        return (*this).size() > another.size();
    }

    size_t size() const { return adjacent.size(); }

    size_t get_id() { return id_; }

    bool find(const std::set<size_t>& setter)
    {
        if (setter.size() < adjacent.size())
        {
            for (auto& elem : setter)
                if (adjacent.find(elem) != adjacent.end())
                    return true;
        }
        else
        {
            for (auto& elem : adjacent)
                if (setter.find(elem) != setter.end())
                    return true;
        }
        return false;
    }
    auto begin()
    {
        return adjacent.begin();
    }
    auto end()
    {
        return adjacent.end();
    }
private:
    std::set<size_t> adjacent;
    size_t id_;
    size_t size_ = 0;
};

