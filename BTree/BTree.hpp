#include "../Data.hpp"
#include "BTreeNode.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

class BTree
{
public:
    BTree(short order);

    BTreeNode *getNode(time_t time);
    bool addNode(time_t time, float price, std::string name);
    bool deleteNode(time_t time);
    bool updateNode(time_t time, float price, std::string name);
    void memoryClear();

    bool loadFromFile(std::string filePath);
    bool saveToFile(std::string filePath);
    std::vector<BTreeNode *> getPageElements(int number, BTreeNode *prevHead);

    long getNumberOfLeafs();
    int getSize();
    short getDepth();

private:
    void insertIntoNonFull(Data *data, BTreeNode *node);
    void splitChild(BTreeNode *node, short index);
    void memoryClear(BTreeNode *node);
    void saveNodeToFile(std::ofstream &outFile, BTreeNode *node);
    int getSize(BTreeNode *node);
    BTreeNode *findParent(BTreeNode *cur, BTreeNode *target);
    BTreeNode *getNode(time_t time, BTreeNode *node);
    int lastId;
    short order;
    BTreeNode *head;
    long numberOfLeaves;
    short depth;

    void deleteFromNode(BTreeNode *node, time_t time);
    void removeFromLeaf(BTreeNode *node, short index);
    void removeFromNonLeaf(BTreeNode *node, short index);
    Data *getPredecessor(BTreeNode *node, short index);
    Data *getSuccessor(BTreeNode *node, short index);
    void fill(BTreeNode *node, short index);
    void borrowFromPrev(BTreeNode *node, short index);
    void borrowFromNext(BTreeNode *node, short index);
    void merge(BTreeNode *node, short index);
};