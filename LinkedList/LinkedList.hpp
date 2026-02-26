#ifndef LINKED_LIST
#define LINKED_LIST

#include "ListNode.hpp"
#include "string"
#include "fstream"
#include <iostream>
#include <vector>

class LinkedList
{
public:
    LinkedList();
    ListNode *getNode(time_t time);
    bool addNode(Data task_data);
    bool deleteNode(time_t time);
    bool updateNode(time_t time, Data task_data);
    int getSize();
    bool loadFromFile(std::string filePath);
    bool saveToFile(std::string filePath);
    void memoryClear();
    std::vector<ListNode*> getPageELements(int page);

private:
    ListNode *head;
};

#endif