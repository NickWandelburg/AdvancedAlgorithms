
#include "BucketQueue.h"
#include <assert.h>
#include <iostream>
#include <iomanip>

BucketQueue::BucketQueue(int _size) : MonotoneIntegerPriorityQueue(_size) {}

int BucketQueue::deleteMin()
{
	int min{-1};

	assert(itemsCount != 0);

	min = (queue.at(minIndex)).front();
	queue.at(minIndex).erase(queue.at(minIndex).begin());

	itemsCount--;

	if (itemsCount == 0 || queue.at(minIndex).size() != 0)
		return min;

	int currIndex = minIndex + 1;

	while (currIndex != minIndex)
	{
		if (currIndex > (queue.size() - 1))
			currIndex = 0;

		std::list<int> currList = queue.at(currIndex);

		if (currList.size() != 0) {
			minIndex = currIndex;
			break;
		}
		else
			currIndex++;
	}

	return min;
}

void BucketQueue::insert(int key)
{
	int index = key % (size + 1);

	if (queue.at(minIndex).size() != 0)
		assert(key < size);
	else
		minIndex = index;

	queue.at(index).push_back(key);
	itemsCount++;
}

void BucketQueue::decreaseKey(int key, int value)
{
	assert(key < size);
	assert(value >= queue.at(minIndex).front());
	
	int keyIndex = key % (size + 1);
	
	assert(queue.at(keyIndex).size() != 0);

	queue.at(keyIndex).erase(queue.at(keyIndex).begin());

	int valueIndex = value % (size + 1);

	queue.at(valueIndex).push_back(value);
}

void BucketQueue::print()
{
	std::cout << "Queue Size: " << size << " | Items Count: " << itemsCount << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	for(int i = 0; i < queue.size(); i++)
	{
		std::cout << "Bucket " << i << ": ";
		for (int key : queue.at(i))
			std::cout << key << " ";
		if (i == minIndex)
			std::cout << "<-- minPtr";
		std::cout << std::endl;
	}
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;
}
