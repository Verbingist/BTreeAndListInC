#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include "../Data.hpp"

class TreeNode
{
public:
    TreeNode(time_t time, float price, std::string name, int id);
    Data &getData();
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