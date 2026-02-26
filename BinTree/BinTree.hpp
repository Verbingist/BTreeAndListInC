#ifndef BIN_TREE
#define BIN_TREE

#include "TreeNode.hpp"
#include "../Data.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class BinTree
{
public:
    BinTree();
    TreeNode *getNode(time_t time);
    bool addNode(Data task_data);
    bool deleteNode(time_t time);
    bool updateNode(time_t time, Data task_data);
    int getSize();
    int getDepth();
    bool loadFromFile(std::string filePath);
    bool saveToFile(std::string filePath);
    void memoryClear();
    void memoryClear(TreeNode *node);
    std::vector<TreeNode *> getPageElements(int number, TreeNode *prevHead);
    int getNumberOfLeafs();

private:
    TreeNode *head;
    TreeNode *getNode(time_t time, TreeNode *node);
    TreeNode *addNode(TreeNode *newNode, TreeNode *node);
    int getSize(TreeNode *node);
    int getDepth(TreeNode *node);
    TreeNode *findOneUpper(TreeNode *node);
    TreeNode *findMinRight(TreeNode *node);
    void saveNodeToFile(std::ofstream &descriptor, TreeNode *node);
    int getNumberOfLeafs(TreeNode *node);
};

#endif