#include "AWLNode.hpp"

AWLNode::AWLNode(time_t time, float price, std::string name, int id) : task(time, price, name, id), left(nullptr), right(nullptr), balanceIndex(0) {}

Data &AWLNode::getData()
{
    return this->task;
}

AWLNode *AWLNode::getLeft()
{
    return this->left;
}

AWLNode *AWLNode::getRight()
{
    return this->right;
}

void AWLNode::setLeft(AWLNode *nextLeft)
{
    this->left = nextLeft;
}

void AWLNode::setRight(AWLNode *nextRight)
{
    this->right = nextRight;
}

short AWLNode::getIndex()
{
    return this->balanceIndex;
}

int AWLNode::getLocalDepth(AWLNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int left = 1, right = 1;
    if (node->getLeft())
    {
        left += getLocalDepth(node->getLeft());
    }
    if (node->getRight())
    {
        right += getLocalDepth(node->getRight());
    }
    if (left > right)
        return left;
    return right;
}

void AWLNode::setIndex(int index) {
    this->balanceIndex = index;
}
