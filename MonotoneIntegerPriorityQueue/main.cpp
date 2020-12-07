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
	bucketQueue.insert(10);

	bucketQueue.print();

	std::cout << "Decrease Key 10 -> 3\n" << std::endl;

	bucketQueue.decreaseKey(10, 3);

	bucketQueue.print();

	std::cout << "Deleted Min: " << bucketQueue.deleteMin() << std::endl;
	std::cout << "Deleted Min: " << bucketQueue.deleteMin() << std::endl;
	std::cout << "Deleted Min: " << bucketQueue.deleteMin() << std::endl;

	std::cout << std::endl;

	bucketQueue.print();
}