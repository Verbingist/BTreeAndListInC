#ifndef LIST_NODE_HPP 
#define LIST_NODE_HPP 

#include "../Data.hpp"

class ListNode
{
public:
    ListNode(Data task_data);
    Data& getData();
    ListNode* getNext();
    void setNext(ListNode* nextNode);
private:
    Data task;
    ListNode* next;
};

#endif