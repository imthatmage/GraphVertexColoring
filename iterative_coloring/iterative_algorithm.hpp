#pragma once
#include "graph.hpp"
#include <vector>

class iterative_algorithm final
{
	public:
		static graph algorithm(graph Graph);
		static graph improve(graph Graph, size_t max_time);
		iterative_algorithm() = delete;
		iterative_algorithm(const iterative_algorithm& another) = delete;
		iterative_algorithm operator=(const iterative_algorithm& another) = delete;
};