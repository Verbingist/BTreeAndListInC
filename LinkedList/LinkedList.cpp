#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr), tail(nullptr), lastId(0) {}

ListNode *LinkedList::getNode(int id)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    for (ListNode *cur = head; cur != nullptr; cur = cur->getNext())
    {
        if (cur->getData().getId() == id)
        {
            return cur;
        }
    }

    return nullptr;
}

bool LinkedList::addNode(time_t time, float price, std::string name)
{
    ListNode *newNode = new ListNode(time, price, name, lastId);

    if (head == nullptr)
    {
        head = newNode;
        tail = head;
        lastId++;
        return true;
    }

    tail->setNext(newNode);
    tail = newNode;
    lastId++;
    return true;
}

bool LinkedList::deleteNode(int id)
{
    if (head == nullptr)
    {
        return false;
    }

    if (head->getData().getId() == id)
    {
        ListNode *deletedTemp = head;
        head = head->getNext();
        delete deletedTemp;
        return true;
    }

    for (ListNode *prew = head, *cur = head->getNext(); cur != nullptr; prew = prew->getNext(), cur = cur->getNext())
    {
        if (cur->getData().getId() == id)
        {
            prew->setNext(cur->getNext());
            delete cur;
            return true;
        }
    }
    return false;
}

bool LinkedList::updateNode(int id, time_t time, float price, std::string name)
{
    if (head == nullptr)
    {
        return false;
    }

    for (ListNode *cur = head; cur != nullptr; cur = cur->getNext())
    {
        if (cur->getData().getId() == id)
        {
            cur->getData().setTime(time);
            cur->getData().setName(name);
            cur->getData().setPrice(price);
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

bool LinkedList::loadFromFile(std::string filePath)
{
    std::ifstream inFile(filePath);
    if (!inFile)
    {
        return false;
    }

    std::string file_time = "";
    std::string file_price = "";
    std::string file_name = "";
    std::string subString = "";

    memoryClear();

    try
    {
        while (std::getline(inFile, file_time) && std::getline(inFile, file_price) && std::getline(inFile, file_name) && std::getline(inFile, subString))
        {
            addNode(std::stoll(file_time), std::stof(file_price), file_name);
        }
    }

    catch (...)
    {
        std::cout << "ERROR WHILE READING FILE" << std::endl;
        return false;
    }

    inFile.close();
    return true;
}

bool LinkedList::saveToFile(std::string filePath)
{
    std::ofstream outFile(filePath);
    if (!outFile)
    {
        return false;
    }
    for (ListNode *cur = head; cur != nullptr; cur = cur->getNext())
    {
        outFile << cur->getData().getTime() << "\n"
                << cur->getData().getPrice() << "\n"
                << cur->getData().getName() << "\n"
                << std::endl;
    }
    outFile.close();
    return true;
}

void LinkedList::memoryClear()
{
    if (head == nullptr)
        return;
    ListNode *cur = head;
    while (cur != nullptr)
    {
        ListNode *deletedNode = cur;
        cur = cur->getNext();
        delete deletedNode;
    }
    head = nullptr;
    tail = nullptr;
}

std::vector<ListNode *> LinkedList::getPageELements(int page)
{
    std::vector<ListNode *> resultVector(3, nullptr);

    int start = page * 3 - 2;
    int end = page * 3;

    int element = 1;
    int i = 0;

    for (ListNode *cur = head; cur != nullptr; cur = cur->getNext(), element++)
    {
        if (element >= start && element <= end && i < 3)
        {
            resultVector[i++] = cur;
        }
    }

    return resultVector;
}
