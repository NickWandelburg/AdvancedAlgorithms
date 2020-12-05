
#include "BucketQueue.h"
#include <assert.h>

BucketQueue::BucketQueue(int _size) : MonotoneIntegerPriorityQueue(_size) {}

int BucketQueue::deleteMin()
{
	int min{-1};

	assert(itemsCount != 0);

	min = (queue.at(minIndex)).front();
	queue.at(minIndex).erase(queue.at(minIndex).begin());

	itemsCount--;

	if (itemsCount == 0)
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
		assert(key < queue.at(minIndex).front() + size);
	else
		minIndex = index;

	queue.at(index).push_back(key);
	itemsCount++;
}

void BucketQueue::decreaseKey(int key, int value)
{
}

void BucketQueue::print()
{
	int currIndex = minIndex++;


	while (currIndex != minIndex);

}
