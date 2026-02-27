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
    ListNode *getNode(int id);
    bool addNode(time_t time, float price, std::string name);
    bool deleteNode(int id);
    bool updateNode(int id, time_t time, float price, std::string name);
    int getSize();
    bool loadFromFile(std::string filePath);
    bool saveToFile(std::string filePath);
    void memoryClear();
    std::vector<ListNode*> getPageELements(int page);

private:
    int lastId;
    ListNode *head;
    ListNode *tail;
};

#endif