#include "ListNode.hpp"

class LinkedList
{
public:
    LinkedList();
    ListNode *getNode(time_t time);
    bool addNode(Data task_data);
    bool deleteNode(time_t time);
    bool updateNode(time_t time, Data task_data);
    int getSize();

private:
    ListNode *head;
};