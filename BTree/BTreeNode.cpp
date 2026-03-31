#include "BTreeNode.hpp"

BTreeNode::BTreeNode(bool leaf) : data(0), links(0), isLeaf(leaf){}

std::vector<Data *> &BTreeNode::getData()
{
    return this->data;
}

std::vector<BTreeNode *> &BTreeNode::getLinks()
{
    return this->links;
}

void BTreeNode::setIsLeaf(bool leaf)
{
    isLeaf = leaf;
}

bool BTreeNode::getIsLeaf()
{
    return isLeaf;
}