#ifndef BTREE_NODE
#define BTREE_NODE
#include "../Data.hpp"
#include <vector>

class BTreeNode
{
public:
    BTreeNode(bool leaf);
    std::vector<Data *> &getData();
    std::vector<BTreeNode *> &getLinks();
    void setIsLeaf(bool);
    bool getIsLeaf();

private:
    std::vector<Data *> data;
    std::vector<BTreeNode *> links;
    bool isLeaf;
};

#endif