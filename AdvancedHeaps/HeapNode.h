#pragma once
#include <memory>

class HeapNode {
private:
	int key;
	std::shared_ptr<HeapNode> child, leftSibling, rightSibling;
public:
	HeapNode();
	HeapNode(int);
	
	int getKey();
	void setKey(int);
	std::shared_ptr<HeapNode> getChild();
	std::shared_ptr<HeapNode> getLeftSibling();
	std::shared_ptr<HeapNode> getRightSibling();
	void setChild(std::shared_ptr<HeapNode>);
	void setLeftSibling(std::shared_ptr<HeapNode>);
	void setRightSibling(std::shared_ptr<HeapNode>);
};