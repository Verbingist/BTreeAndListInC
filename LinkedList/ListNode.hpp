#include "../Data.hpp"

class ListNode
{
public:
    ListNode(Data task_data);
    Data getData();
    ListNode* getNext();
    void setNext(ListNode* nextNode);
private:
    Data task;
    ListNode* next;
};