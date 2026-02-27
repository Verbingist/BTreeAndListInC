#ifndef LIST_NODE_HPP 
#define LIST_NODE_HPP 

#include "../Data.hpp"

class ListNode
{
public:
    ListNode(time_t time, float price, std::string name, int id);
    Data& getData();
    ListNode* getNext();
    void setNext(ListNode* nextNode);
private:
    Data task;
    ListNode* next;
};

#endif