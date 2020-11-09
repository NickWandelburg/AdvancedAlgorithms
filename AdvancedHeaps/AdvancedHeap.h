// AdvandedHeap.h: Base advanced heap class which declares and defines advanced heap properties and operations
#pragma once
#include "HeapNode.h"
#include <memory>

class AdvancedHeap {
private:
	std::shared_ptr<HeapNode> root;
public:
	AdvancedHeap();
	AdvancedHeap(std::shared_ptr<HeapNode> node);

	void insert(std::shared_ptr<HeapNode>);
	void merge(AdvancedHeap&);
	void decreaseKey(std::shared_ptr<HeapNode>, int);
	virtual int deleteMin() = 0;
};