#include "HeapNode.h"
#include <memory>


HeapNode::HeapNode() : key{ 0 }, child { nullptr }, leftSibling{ nullptr }, rightSibling{ nullptr }{}
HeapNode::HeapNode(int key) : HeapNode() { this->key = key; }

int HeapNode::getKey() { return key; }
void HeapNode::setKey(int key) { this->key = key; }
std::shared_ptr<HeapNode> HeapNode::getChild() { return child; }
std::shared_ptr<HeapNode> HeapNode::getLeftSibling() { return leftSibling; }
std::shared_ptr<HeapNode> HeapNode::getRightSibling() { return rightSibling; }
void HeapNode::setChild(std::shared_ptr<HeapNode> node) { child = node; }
void HeapNode::setLeftSibling(std::shared_ptr<HeapNode> node) { leftSibling = node; }
void HeapNode::setRightSibling(std::shared_ptr<HeapNode> node) { rightSibling = node; }
