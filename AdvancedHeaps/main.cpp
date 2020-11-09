#include <iostream>
#include "AdvancedHeap.h"
#include "PairingHeap.h"

int main()
{
    PairingHeap pairingHeap{};
    pairingHeap.insert(std::make_shared<HeapNode>(1));
    pairingHeap.insert(std::make_shared<HeapNode>(2));

    std::shared_ptr<HeapNode> heapNode = std::make_shared<HeapNode>(3);
    pairingHeap.insert(heapNode);

    pairingHeap.insert(std::make_shared<HeapNode>(4));
    pairingHeap.insert(std::make_shared<HeapNode>(0));
    pairingHeap.insert(std::make_shared<HeapNode>(5));

    pairingHeap.decreaseKey(heapNode, 2);

    PairingHeap pairingHeap_{};
    pairingHeap_.insert(std::make_shared<HeapNode>(7));
    pairingHeap_.insert(std::make_shared<HeapNode>(6));

    pairingHeap.merge(pairingHeap_);
}
