#include "TreeNode.hpp"

TreeNode::TreeNode(Data task_data) : task(task_data), left(nullptr), right(nullptr) {}

Data TreeNode::getData()
{
    return this->task;
}

TreeNode *TreeNode::getLeft()
{
    return this->left;
}

TreeNode *TreeNode::getRight()
{
    return this->right;
}

void TreeNode::setLeft(TreeNode * nextLeft) {
    this->left = nextLeft;
}

void TreeNode::setRight(TreeNode * nextRight) {
    this->right = nextRight;
}