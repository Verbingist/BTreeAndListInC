#include "BTree.hpp"

BTree::BTree(short order)
{
    this->order = order;
    head = nullptr;
    lastId = 0;
    numberOfLeaves = 0;
    depth = 0;
}

bool BTree::addNode(time_t time, float price, std::string name)
{
    Data *data = new Data(time, price, name, lastId++);

    if (head == nullptr)
    {
        head = new BTreeNode(true);
        numberOfLeaves++;
        depth++;
        head->getData().push_back(data);
        return true;
    }

    if (head->getData().size() == 2 * order - 1)
    {
        BTreeNode *newNode = new BTreeNode(false);
        newNode->getLinks().push_back(head);
        splitChild(newNode, 0);
        depth++;
        head = newNode;
    }

    insertIntoNonFull(data, head);
    return true;
}

void BTree::insertIntoNonFull(Data *data, BTreeNode *node)
{
    std::vector<Data *> &keys = node->getData();

    if (node->getIsLeaf())
    {
        keys.push_back(data);
        std::sort(keys.begin(), keys.end(), [](Data *a, Data *b)
                  { return a->getTime() < b->getTime(); });
        return;
    }

    std::vector<BTreeNode *> &children = node->getLinks();
    short i;

    for (i = keys.size() - 1; i >= 0 && keys[i]->getTime() > data->getTime(); i--)
        ;
    i++;

    if (children[i]->getData().size() == 2 * order - 1)
    {
        splitChild(node, i);

        if (data->getTime() > node->getData()[i]->getTime())
            i++;
    }

    insertIntoNonFull(data, children[i]);
}

void BTree::splitChild(BTreeNode *parent, short index)
{
    BTreeNode *child = parent->getLinks()[index];
    BTreeNode *right = new BTreeNode(child->getIsLeaf());

    if (child->getIsLeaf())
    {
        numberOfLeaves++;
    }

    std::vector<Data *> &childKeys = child->getData();
    std::vector<BTreeNode *> &childLinks = child->getLinks();
    std::vector<Data *> &parentKeys = parent->getData();
    std::vector<BTreeNode *> &parentLinks = parent->getLinks();

    for (int j = 0; j < order - 1; ++j)
        right->getData().push_back(childKeys[j + order]);

    if (!child->getIsLeaf())
    {
        for (int j = 0; j < order; ++j)
            right->getLinks().push_back(childLinks[j + order]);
    }

    Data *middle = childKeys[order - 1];

    childKeys.resize(order - 1);
    if (!child->getIsLeaf())
        childLinks.resize(order);

    parentKeys.insert(parentKeys.begin() + index, middle);
    parentLinks.insert(parentLinks.begin() + index + 1, right);
}

BTreeNode *BTree::getNode(time_t time)
{
    return getNode(time, head);
}

BTreeNode *BTree::getNode(time_t time, BTreeNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    std::vector<Data *> &keys = node->getData();
    for (auto it = keys.begin(); it != keys.end(); it++)
    {
        if (time == (*it)->getTime())
        {
            return node;
        }
        if (time < (*it)->getTime())
        {
            int index = it - keys.begin();
            std::vector<BTreeNode *> &links = node->getLinks();
            if (index < 0 || index >= links.size() || links[index] == nullptr)
            {
                return nullptr;
            }
            return getNode(time, node->getLinks()[index]);
        }
    }
    return getNode(time, node->getLinks()[keys.size()]);
}

bool BTree::updateNode(time_t time, float price, std::string name)
{
    BTreeNode *node = getNode(time, head);
    if (node == nullptr)
        return false;

    std::vector<Data *> &keys = node->getData();

    for (auto it = keys.begin(); it != keys.end(); it++)
    {
        if ((*it)->getTime() == time)
        {
            (*it)->setName(name);
            (*it)->setPrice(price);
            return true;
        }
    }

    return false;
}

void BTree::memoryClear()
{
    memoryClear(head);
}

void BTree::memoryClear(BTreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    std::vector<Data *> &keys = node->getData();
    for (auto it = keys.begin(); it != keys.end(); it++)
    {
        delete *it;
    }

    std::vector<BTreeNode *> &links = node->getLinks();
    for (auto it = links.begin(); it != links.end(); it++)
    {
        memoryClear(*it);
        delete *it;
    }
}

bool BTree::loadFromFile(std::string filePath)
{
    std::ifstream inFile(filePath);
    if (!inFile)
    {
        return false;
    }

    this->depth = 0;
    this->numberOfLeaves = 0;

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

bool BTree::saveToFile(std::string filePath)
{
    std::ofstream outFile(filePath);
    if (!outFile)
    {
        return false;
    }
    saveNodeToFile(outFile, head);
    outFile.close();
    return true;
}

void BTree::saveNodeToFile(std::ofstream &outFile, BTreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    std::vector<Data *> &keys = node->getData();
    for (auto it = keys.begin(); it != keys.end(); it++)
    {
        outFile << (*it)->getTime() << "\n"
                << (*it)->getPrice() << "\n"
                << (*it)->getName() << "\n"
                << std::endl;
    }

    std::vector<BTreeNode *> &links = node->getLinks();
    for (auto it = links.begin(); it != links.end(); it++)
    {
        saveNodeToFile(outFile, *it);
    }
}

long BTree::getNumberOfLeafs()
{
    return numberOfLeaves;
}

short BTree::getDepth()
{
    return depth;
}

int BTree::getSize()
{
    return getSize(head);
}

int BTree::getSize(BTreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int size = node->getData().size();

    std::vector<BTreeNode *> &links = node->getLinks();
    for (auto it = links.begin(); it != links.end(); it++)
    {
        size += getSize(*it);
    }
    return size;
}

BTreeNode *BTree::findParent(BTreeNode *cur, BTreeNode *target)
{
    if (cur == nullptr || target == nullptr)
    {
        return nullptr;
    }

    std::vector<BTreeNode *> &links = cur->getLinks();
    for (BTreeNode *child : links)
    {
        if (child == nullptr)
        {
            continue;
        }
        if (child == target)
        {
            return cur;
        }
        BTreeNode *res = findParent(child, target);
        if (res != nullptr)
        {
            return res;
        }
    }
    return nullptr;
}

std::vector<BTreeNode *> BTree::getPageElements(int number, BTreeNode *prevHead)
{
    std::vector<BTreeNode *> result(5, nullptr);

    if (head == nullptr)
    {
        return result;
    }

    BTreeNode *center = nullptr;

    if (prevHead == nullptr)
    {
        center = head;
    }
    else
    {
        if (number == 0 && prevHead != head)
        {
            BTreeNode *parent = findParent(head, prevHead);
            center = (parent != nullptr) ? parent : head;
        }
        else
        {
            std::vector<BTreeNode *> &links = prevHead->getLinks();
            switch (number)
            {
            case 0:
                center = prevHead;
                break;
            case 1:
                center = (links.size() > 0 ? links[0] : prevHead);
                break;
            case 2:
                center = (links.size() > 1 ? links[1] : prevHead);
                break;
            case 3:
                center = (links.size() > 2 ? links[2] : prevHead);
                break;
            case 4:
                center = (links.size() > 3 ? links[3] : prevHead);
                break;
            default:
                center = prevHead;
                break;
            }
        }
    }

    result[0] = center;

    if (center != nullptr)
    {
        auto &links = center->getLinks();
        std::size_t idx = 1;
        for (std::size_t i = 0; i < links.size() && idx < result.size(); ++i, ++idx)
            result[idx] = links[i];
    }

    return result;
}

bool BTree::deleteNode(time_t time)
{
    if (head == nullptr)
    {
        return false;
    }

    deleteFromNode(head, time);

    if (head->getData().empty() && !head->getIsLeaf())
    {
        BTreeNode *oldHead = head;
        head = head->getLinks()[0];
        delete oldHead;
        depth = std::max(0, depth - 1);
    }

    if (head->getData().empty() && head->getIsLeaf())
    {
        delete head;
        head = nullptr;
        depth = 0;
        numberOfLeaves = 0;
    }
    return true;
}

void BTree::deleteFromNode(BTreeNode *node, time_t time)
{
    if (node == nullptr)
    {
        return;
    }

    std::vector<Data *> &keys = node->getData();
    int i = 0;

    for (i = 0; i < keys.size() && keys[i]->getTime() < time; i++)
        ;

    if (i < keys.size() && keys[i]->getTime() == time)
    {
        if (node->getIsLeaf())
        {
            removeFromLeaf(node, i);
        }
        else
        {
            removeFromNonLeaf(node, i);
        }
        return;
    }

    if (node->getIsLeaf())
    {
        return;
    }

    bool lastChild = (i == keys.size()) ? true : false;
    std::vector<BTreeNode *> &children = node->getLinks();

    if (children[i]->getData().size() < order)
    {
        fill(node, i);
        if (i > keys.size())
        {
            i = keys.size();
        }
    }

    deleteFromNode(children[i], time);
}

void BTree::removeFromLeaf(BTreeNode *node, short index)
{
    std::vector<Data *> &keys = node->getData();
    delete keys[index];
    keys.erase(keys.begin() + index);
}

void BTree::removeFromNonLeaf(BTreeNode *node, short index)
{
    std::vector<Data *> &keys = node->getData();
    std::vector<BTreeNode *> &children = node->getLinks();

    Data *data = keys[index];

    if (children[index]->getData().size() >= order)
    {
        Data *pred = getPredecessor(node, index);
        delete keys[index];
        keys[index] = pred;
        deleteFromNode(children[index], pred->getTime());
    }
    else if (children[index + 1]->getData().size() >= order)
    {
        Data *succ = getSuccessor(node, index);
        delete keys[index];
        keys[index] = succ;
        deleteFromNode(children[index + 1], succ->getTime());
    }
    else
    {
        merge(node, index);
        deleteFromNode(children[index], data->getTime());
    }
}

Data *BTree::getPredecessor(BTreeNode *node, short index)
{
    BTreeNode *cur = node->getLinks()[index];
    while (!cur->getIsLeaf())
    {
        std::vector<BTreeNode *> &links = cur->getLinks();
        cur = links.back();
    }
    std::vector<Data *> &keys = cur->getData();
    return keys.back();
}

Data *BTree::getSuccessor(BTreeNode *node, short index)
{
    BTreeNode *cur = node->getLinks()[index + 1];
    while (!cur->getIsLeaf())
    {
        std::vector<BTreeNode *> &links = cur->getLinks();
        cur = links.front();
    }
    std::vector<Data *> &keys = cur->getData();
    return keys.front();
}

void BTree::fill(BTreeNode *node, short index)
{
    std::vector<BTreeNode *> &children = node->getLinks();
    if (index != 0 && children[index - 1]->getData().size() >= order)
    {
        borrowFromPrev(node, index);
    }
    else if (index != children.size() - 1 && children[index + 1]->getData().size() >= order)
    {
        borrowFromNext(node, index);
    }
    else
    {
        if (index != children.size() - 1)
            merge(node, index);
        else
            merge(node, index - 1);
    }
}

void BTree::borrowFromPrev(BTreeNode *node, short index)
{
    std::vector<BTreeNode *> &children = node->getLinks();
    std::vector<Data *> &keys = node->getData();

    BTreeNode *child = children[index];
    BTreeNode *sibling = children[index - 1];

    child->getData().insert(child->getData().begin(), keys[index - 1]);

    if (!sibling->getIsLeaf())
    {
        child->getLinks().insert(child->getLinks().begin(), sibling->getLinks().back());
        sibling->getLinks().pop_back();
    }

    keys[index - 1] = sibling->getData().back();
    sibling->getData().pop_back();
}

void BTree::borrowFromNext(BTreeNode *node, short index)
{
    std::vector<BTreeNode *> &children = node->getLinks();
    std::vector<Data *> &keys = node->getData();

    BTreeNode *child = children[index];
    BTreeNode *sibling = children[index + 1];

    child->getData().push_back(keys[index]);

    if (!sibling->getIsLeaf())
    {
        child->getLinks().push_back(sibling->getLinks().front());
        sibling->getLinks().erase(sibling->getLinks().begin());
    }

    keys[index] = sibling->getData().front();
    sibling->getData().erase(sibling->getData().begin());
}

void BTree::merge(BTreeNode *node, short index)
{
    std::vector<BTreeNode *> &children = node->getLinks();
    std::vector<Data *> &keys = node->getData();

    BTreeNode *left = children[index];
    BTreeNode *right = children[index + 1];

    left->getData().push_back(keys[index]);

    for (Data *d : right->getData())
        left->getData().push_back(d);

    if (!right->getIsLeaf())
    {
        for (BTreeNode *element : right->getLinks())
            left->getLinks().push_back(element);
    }

    keys.erase(keys.begin() + index);
    children.erase(children.begin() + index + 1);
    delete right;

    if (left->getIsLeaf())
    {
        if (right->getIsLeaf())
            numberOfLeaves = std::max<long>(0, numberOfLeaves - 1);
    }
}