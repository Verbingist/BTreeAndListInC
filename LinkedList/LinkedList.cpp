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
        if (newTime == cur->getNext()->getData().getTime())
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
            Data tempData = Data(std::stoll(file_time), std::stof(file_price), file_name);
            addNode(tempData);
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
