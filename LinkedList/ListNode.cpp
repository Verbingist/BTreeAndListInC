#include "ListNode.hpp"

ListNode::ListNode(Data task_data) : task(task_data), next(nullptr) {}

Data ListNode::getData()
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
