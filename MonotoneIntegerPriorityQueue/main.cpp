#include <iostream>
#include "MonotoneIntegerPriorityQueue.h"
#include "BucketQueue.h"

int main()
{
	const int size = 10;
	BucketQueue bucketQueue{size};

	bucketQueue.insert(1);
	bucketQueue.insert(2);
	bucketQueue.insert(2);

	std::cout << bucketQueue.deleteMin() << std::endl;
	std::cout << bucketQueue.deleteMin() << std::endl;
	std::cout << bucketQueue.deleteMin() << std::endl;

	bucketQueue.print();
}