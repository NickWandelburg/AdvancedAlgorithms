#pragma once

#include "MonotoneIntegerPriorityQueue.h"

class BucketQueue : public MonotoneIntegerPriorityQueue
{
public:
	BucketQueue(int);
	int deleteMin() override;
	void insert(int) override;
	void decreaseKey(int, int) override;
	void print() override;
};