#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr) {}

ListNode *LinkedList::getNode(time_t time)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    for (ListNode *cur = head; cur != nullptr; cur = cur->getNext())
    {
        if (cur->getData().getTime() == time)
        {
            return cur;
        }
    }

    return nullptr;
}

bool LinkedList::addNode(Data task_data)
{
    ListNode *newNode = new ListNode(task_data);
    if (head == nullptr)
    {
        head = newNode;
        return true;
    }
    ListNode *cur = head;
    time_t newTime = task_data.getTime();

    if (head->getData().getTime() == newTime)
    {
        delete newNode;
        return false;
    }

    for (; cur->getNext() != nullptr; cur = cur->getNext())
    {
        if (newTime == cur->getData().getTime())
        {
            delete newNode;
            return false;
        }
    }

    if (cur->getData().getTime() == newTime)
    {
        delete newNode;
        return false;
    }

    cur->setNext(newNode);
    return true;
}

bool LinkedList::deleteNode(time_t time)
{
    if (head == nullptr)
    {
        return false;
    }
    if (head->getData().getTime() == time)
    {
        ListNode *deletedTemp = head;
        head = head->getNext();
        delete deletedTemp;
        return true;
    }
    for (ListNode *prew = head, *cur = head->getNext(); cur != nullptr; prew = prew->getNext(), cur = cur->getNext())
    {
        if (cur->getData().getTime() == time)
        {
            prew->setNext(cur->getNext());
            delete cur;
            return true;
        }
    }
    return false;
}

bool LinkedList::updateNode(time_t time, Data task_data)
{
    if (head == nullptr)
    {
        return false;
    }
    for (ListNode *cur = head; cur != nullptr; cur = cur->getNext())
    {
        if (cur->getData().getTime() == time)
        {
            cur->getData().setName(task_data.getName());
            cur->getData().setPrice(task_data.getPrice());
            return true;
        }
    }
    return false;
}

int LinkedList::getSize()
{
    if (head == nullptr)
    {
        return 0;
    }
    int i = 0;
    for (ListNode *cur = head; cur != nullptr; cur = cur->getNext(), i++)
        ;
    return i;
}