#pragma once
#include <vector>
#include <map>
#include <set>
#include <list>

size_t get_first_available(const std::set<size_t>& colors);
std::map<size_t, size_t> greedy(const std::vector<std::list<size_t>> Graph);