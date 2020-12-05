#pragma once

#include <vector>
#include <list>
#include <memory>

class MonotoneIntegerPriorityQueue {

protected:
	std::vector<std::list<int>> queue;
	const int size;
	int minIndex;
	int itemsCount;

	MonotoneIntegerPriorityQueue(int _size) : size(_size), minIndex(0), itemsCount(0) {
		queue = std::vector<std::list<int>>(size);
	}

public:
	virtual int deleteMin() = 0;
	virtual void insert(int) = 0;
	virtual void decreaseKey(int, int) = 0;
	virtual void print() = 0;
};
