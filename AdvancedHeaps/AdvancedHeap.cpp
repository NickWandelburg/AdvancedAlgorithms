#include "AdvancedHeap.h"
#include "HeapNode.h"


AdvancedHeap::AdvancedHeap() : root{ nullptr } {}
AdvancedHeap::AdvancedHeap(std::shared_ptr<HeapNode> node) : root{ node } {}

void AdvancedHeap::insert(std::shared_ptr<HeapNode> node)
{
	if (this->root == nullptr)
		this->root = node;
	else if (this->root->getKey() < node->getKey()) {
		if (this->root->getChild() != nullptr)
		{
			node->setRightSibling(this->root->getChild());
			this->root->getChild()->setLeftSibling(node);
		}
		this->root->setChild(node);
	}
	else
	{
		node->setChild(this->root);
		this->root = node;
	}
}

void AdvancedHeap::merge(AdvancedHeap& heap)
{
	if (this->root->getKey() < heap.root->getKey())
	{
		heap.root->setRightSibling(this->root->getChild());
		this->root->getChild()->setLeftSibling(heap.root);
		this->root->setChild(heap.root);
	}
	else
	{
		this->root->setRightSibling(heap.root->getChild());
		heap.root->getChild()->setLeftSibling(this->root);
		heap.root->setChild(this->root);
		this->root = heap.root;
	}
	heap.root = nullptr;
}

void AdvancedHeap::decreaseKey(std::shared_ptr<HeapNode> node, int key)
{
	if (node->getKey() <= key)
		return;
	
	node->setKey(key);

	if (node->getLeftSibling() != nullptr)
		node->getLeftSibling()->setRightSibling(node->getRightSibling());

	if (node->getRightSibling() != nullptr)
		node->getRightSibling()->setLeftSibling(node->getLeftSibling());

	node->setLeftSibling(nullptr);
	node->setRightSibling(nullptr);

	insert(node);
}