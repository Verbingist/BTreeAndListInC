#ifndef AWL_TREE
#define AWL_TREE

#include "AWLNode.hpp"
#include "../Data.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class AWLTree
{
public:
    AWLTree();
    AWLNode *getNode(int id);
    bool addNode(time_t time, float price, std::string name);
    bool deleteNode(int id);
    bool updateNode(int id, time_t time, float price, std::string name);
    bool loadFromFile(std::string filePath);
    bool saveToFile(std::string filePath);
    void memoryClear();
    void memoryClear(AWLNode *node);
    std::vector<AWLNode *> getPageElements(int number, AWLNode *prevHead);
    int getSize();
    int getDepth();
    int getNumberOfLeafs();
    AWLNode *balanceTree(AWLNode *node);
    AWLNode *singleRotateRight(AWLNode *parentNode);
    AWLNode *doubleRotateRight(AWLNode *parentNode);
    AWLNode *singleRotateLeft(AWLNode *parentNode);
    AWLNode *doubleRotateLeft(AWLNode *parentNode);

private:
    int lastId;
    AWLNode *head;
    AWLNode *getNode(int id, AWLNode *node);
    AWLNode *addNode(AWLNode *newNode, AWLNode *node);
    int getSize(AWLNode *node);
    int getDepth(AWLNode *node);
    AWLNode *findOneUpper(AWLNode *node);
    AWLNode *findMinRight(AWLNode *node);
    void saveNodeToFile(std::ofstream &descriptor, AWLNode *node);
    int getNumberOfLeafs(AWLNode *node);
};

#endif