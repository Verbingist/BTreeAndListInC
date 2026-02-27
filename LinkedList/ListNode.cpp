#include "ListNode.hpp"

ListNode::ListNode(time_t time, float price, std::string name, int id) : task(time, price, name, id), next(nullptr) {}

Data& ListNode::getData()
{
    return this->task;
}

ListNode *ListNode::getNext()
{
    return this->next;
}

void ListNode::setNext(ListNode * nextNode) {
    this->next = nextNode;
}
