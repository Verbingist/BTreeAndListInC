#ifndef AWL_NODE_HPP
#define AWL_NODE_HPP

#include "../Data.hpp"

class AWLNode
{
public:
    AWLNode(time_t time, float price, std::string name, int id);
    Data &getData();
    AWLNode *getLeft();
    AWLNode *getRight();
    void setRight(AWLNode *nextNode);
    void setLeft(AWLNode *nextNode);
    short getIndex();
    void setIndex(int index);
    int getLocalDepth(AWLNode* node);

private:
    Data task;
    AWLNode *left;
    AWLNode *right;
    short balanceIndex;
};

#endif