#ifndef TREE_NODE_HPP 
#define TREE_NODE_HPP

#include "../Data.hpp"

class TreeNode
{
public:
    TreeNode(Data task_data);
    Data getData();
    TreeNode *getLeft();
    TreeNode *getRight();
    void setRight(TreeNode *nextNode);
    void setLeft(TreeNode *nextNode);

private:
    Data task;
    TreeNode *left;
    TreeNode *right;
};

#endif