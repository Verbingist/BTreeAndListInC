#include "AWLTree.hpp"

AWLTree::AWLTree() : head(nullptr), lastId(0) {}

AWLNode *AWLTree::getNode(int id)
{
    return getNode(id, head);
}

AWLNode *AWLTree::getNode(int id, AWLNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->getData().getId() < id)
    {
        return getNode(id, node->getRight());
    }
    else if (node->getData().getId() > id)
    {
        return getNode(id, node->getLeft());
    }
    return node;
}

bool AWLTree::addNode(time_t time, float price, std::string name)
{
    AWLNode *newNode = new AWLNode(time, price, name, lastId);
    head = addNode(newNode, head);
    lastId++;
    return true;
}

AWLNode *AWLTree::addNode(AWLNode *newNode, AWLNode *node)
{
    if (node == nullptr)
    {
        return newNode;
    }
    if (node->getData().getId() < newNode->getData().getId())
    {
        node->setRight(addNode(newNode, node->getRight()));
    }
    else
    {
        node->setLeft(addNode(newNode, node->getLeft()));
    }
    node = balanceTree(node);
    return node;
}

AWLNode *AWLTree::singleRotateRight(AWLNode *parentNode)
{
    AWLNode *leftChild = parentNode->getLeft();
    parentNode->setLeft(leftChild->getRight());
    leftChild->setRight(parentNode);

    parentNode->setIndex(parentNode->getLocalDepth(parentNode->getRight()) - parentNode->getLocalDepth(parentNode->getLeft()));
    leftChild->setIndex(leftChild->getLocalDepth(leftChild->getRight()) - leftChild->getLocalDepth(leftChild->getLeft()));
    return leftChild;
}

AWLNode *AWLTree::singleRotateLeft(AWLNode *parentNode)
{
    AWLNode *RightChild = parentNode->getRight();
    parentNode->setRight(RightChild->getLeft());
    RightChild->setLeft(parentNode);

    parentNode->setIndex(parentNode->getLocalDepth(parentNode->getRight()) - parentNode->getLocalDepth(parentNode->getLeft()));
    RightChild->setIndex(RightChild->getLocalDepth(RightChild->getRight()) - RightChild->getLocalDepth(RightChild->getLeft()));
    return RightChild;
}

AWLNode *AWLTree::doubleRotateRight(AWLNode *parentNode)
{
    AWLNode *leftChild = parentNode->getLeft();
    AWLNode *newParent = leftChild->getRight();

    leftChild->setRight(newParent->getLeft());

    newParent->setLeft(leftChild);

    parentNode->setLeft(newParent->getRight());

    newParent->setRight(parentNode);

    parentNode->setIndex(parentNode->getLocalDepth(parentNode->getRight()) - parentNode->getLocalDepth(parentNode->getLeft()));
    leftChild->setIndex(leftChild->getLocalDepth(leftChild->getRight()) - leftChild->getLocalDepth(leftChild->getLeft()));
    newParent->setIndex(newParent->getLocalDepth(newParent->getRight()) - newParent->getLocalDepth(newParent->getLeft()));

    return newParent;
}

AWLNode *AWLTree::doubleRotateLeft(AWLNode *parentNode)
{
    AWLNode *rightChild = parentNode->getRight();
    AWLNode *newParent = rightChild->getLeft();

    rightChild->setLeft(newParent->getRight());

    newParent->setRight(rightChild);

    parentNode->setRight(newParent->getLeft());

    newParent->setLeft(parentNode);

    parentNode->setIndex(parentNode->getLocalDepth(parentNode->getRight()) - parentNode->getLocalDepth(parentNode->getLeft()));
    rightChild->setIndex(rightChild->getLocalDepth(rightChild->getRight()) - rightChild->getLocalDepth(rightChild->getLeft()));
    newParent->setIndex(newParent->getLocalDepth(newParent->getRight()) - newParent->getLocalDepth(newParent->getLeft()));

    return newParent;
}

AWLNode *AWLTree::balanceTree(AWLNode *node)
{
    if (node == nullptr)
    {
        return node;
    }
    node->setIndex(node->getLocalDepth(node->getRight()) - node->getLocalDepth(node->getLeft()));
    if (node->getIndex() == -2)
    {
        if (node->getLeft()->getIndex() < 0)
        {
            return singleRotateRight(node);
        }
        else
        {
            return doubleRotateRight(node);
        }
    }
    if (node->getIndex() == 2)
    {
        if (node->getRight()->getIndex() > 0)
        {
            return singleRotateLeft(node);
        }
        else
        {
            return doubleRotateLeft(node);
        }
    }
    return node;
}

bool AWLTree::updateNode(int id, time_t time, float price, std::string name)
{
    AWLNode *node = getNode(id);
    if (node == nullptr)
    {
        return false;
    }
    node->getData().setTime(time);
    node->getData().setName(name);
    node->getData().setPrice(price);
    return true;
}

int AWLTree::getSize()
{
    return getSize(head);
}

int AWLTree::getSize(AWLNode *node)
{
    int count = 0;
    if (node == nullptr)
        return 0;
    count++;
    if (node->getLeft() != nullptr)
    {
        count += getSize(node->getLeft());
    }
    if (node->getRight() != nullptr)
    {
        count += getSize(node->getRight());
    }
    return count;
}

int AWLTree::getDepth()
{
    return getDepth(head);
}

int AWLTree::getDepth(AWLNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int left = 1, right = 1;
    if (node->getLeft())
    {
        left += getDepth(node->getLeft());
    }
    if (node->getRight())
    {
        right += getDepth(node->getRight());
    }
    if (left > right)
        return left;
    return right;
}

bool AWLTree::deleteNode(int id)
{
    AWLNode *node = getNode(id);
    if (node == nullptr)
    {
        return false;
    }

    AWLNode *globalParent = findOneUpper(node);

    if (node->getLeft() == nullptr && node->getRight() == nullptr)
    {
        AWLNode *parent = findOneUpper(node);
        if (parent->getLeft() == node)
        {
            parent->setLeft(nullptr);
        }
        else
        {
            parent->setRight(nullptr);
        }
        delete node;
    }
    else if (node->getLeft() != nullptr ^ node->getRight() != nullptr)
    {
        if (node->getLeft())
        {
            AWLNode *parent = findOneUpper(node);
            if (parent->getLeft() == node)
            {
                parent->setLeft(node->getLeft());
                delete node;
            }
            else
            {
                parent->setRight(node->getLeft());
                delete node;
            }
        }
        else
        {
            AWLNode *parent = findOneUpper(node);

            if (parent->getLeft() == node)
            {
                parent->setLeft(node->getRight());
                delete node;
            }
            else
            {
                parent->setRight(node->getRight());
                delete node;
            }
        }
    }
    else
    {
        AWLNode *parent = findOneUpper(node);
        AWLNode *min = findMinRight(node->getRight());

        if (min->getLeft())
        {
            AWLNode *minParent = findOneUpper(min);
            if (minParent->getLeft() == min)
            {
                minParent->setLeft(min->getLeft());
            }
            else
            {
                minParent->setRight(min->getLeft());
            }
        }
        else
        {
            AWLNode *minParent = findOneUpper(min);
            if (minParent->getLeft() == min)
            {
                minParent->setLeft(min->getRight());
            }
            else
            {
                minParent->setRight(min->getRight());
            }
        }

        min->setLeft(node->getLeft());
        min->setRight(node->getRight());

        if (parent == nullptr)
        {
            delete head;
            head = min;
            head = balanceTree(head);
            return true;
        }

        else if (parent->getLeft() == node)
        {
            parent->setLeft(min);
        }
        else
        {
            parent->setRight(min);
        }

        delete node;
    }

    for (AWLNode *upper = findOneUpper(globalParent); globalParent != nullptr; globalParent = upper, upper = findOneUpper(globalParent))
    {
        AWLNode *balanced = balanceTree(globalParent);
        if (upper == nullptr)
        {
            head = balanced;
        }
        else
        {
            if (upper->getLeft() == globalParent)
            {
                upper->setLeft(balanced);
            }
            else
            {
                upper->setRight(balanced);
            }
        }
    }

    return true;
}

AWLNode *AWLTree::findOneUpper(AWLNode *node)
{
    if (node == head || node == nullptr)
    {
        return nullptr;
    }

    for (AWLNode *cur = head; cur != nullptr;)
    {
        if (cur->getLeft() == node || cur->getRight() == node)
        {
            return cur;
        }
        if (node->getData().getId() < cur->getData().getId())
        {
            cur = cur->getLeft();
        }
        else
        {
            cur = cur->getRight();
        }
    }
    return nullptr;
}

AWLNode *AWLTree::findMinRight(AWLNode *node)
{
    AWLNode *cur = node;
    for (; cur && cur->getLeft() != nullptr; cur = cur->getLeft())
        ;
    return cur;
}

bool AWLTree::loadFromFile(std::string filePath)
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

bool AWLTree::saveToFile(std::string filePath)
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

void AWLTree::saveNodeToFile(std::ofstream &outFile, AWLNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    outFile << node->getData().getTime() << "\n"
            << node->getData().getPrice() << "\n"
            << node->getData().getName() << "\n"
            << std::endl;

    saveNodeToFile(outFile, node->getLeft());
    saveNodeToFile(outFile, node->getRight());
}

void AWLTree::memoryClear()
{
    memoryClear(head);
    head = nullptr;
}

void AWLTree::memoryClear(AWLNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    memoryClear(node->getLeft());
    memoryClear(node->getRight());
    delete node;
}

std::vector<AWLNode *> AWLTree::getPageElements(int number, AWLNode *prevHead)
{
    std::vector<AWLNode *> resultVector(3, nullptr);
    if (prevHead == nullptr)
        prevHead = head;

    if (prevHead == nullptr)
        return resultVector;

    if (number == 0)
    {
        AWLNode *parent = findOneUpper(prevHead);
        if (parent == nullptr)
        {
            resultVector[0] = head;
            resultVector[1] = head->getLeft();
            resultVector[2] = head->getRight();
            return resultVector;
        }
        else
        {
            resultVector[0] = parent;
            resultVector[1] = parent->getLeft();
            resultVector[2] = parent->getRight();
            return resultVector;
        }
    }
    if (number == 1)
    {
        if (prevHead->getRight() == nullptr)
        {
            resultVector[0] = prevHead;
            resultVector[1] = prevHead->getLeft();
            resultVector[2] = prevHead->getRight();
            return resultVector;
        }
        else
        {
            resultVector[0] = prevHead->getRight();
            resultVector[1] = prevHead->getRight()->getLeft();
            resultVector[2] = prevHead->getRight()->getRight();
            return resultVector;
        }
    }
    else
    {
        if (prevHead->getLeft() == nullptr)
        {
            resultVector[0] = prevHead;
            resultVector[1] = prevHead->getLeft();
            resultVector[2] = prevHead->getRight();
            return resultVector;
        }
        else
        {
            resultVector[0] = prevHead->getLeft();
            resultVector[1] = prevHead->getLeft()->getLeft();
            resultVector[2] = prevHead->getLeft()->getRight();
            return resultVector;
        }
    }
    return resultVector;
}

int AWLTree::getNumberOfLeafs()
{
    if (head == nullptr)
        return 0;
    return getNumberOfLeafs(head);
}

int AWLTree::getNumberOfLeafs(AWLNode *node)
{
    int leafCount = 0;

    if (node == nullptr)
        return 0;

    if (node->getRight() == nullptr && node->getLeft() == nullptr)
    {
        leafCount++;
    }

    if (node->getRight())
    {
        leafCount += getNumberOfLeafs(node->getRight());
    }

    if (node->getLeft())
    {
        leafCount += getNumberOfLeafs(node->getLeft());
    }

    return leafCount;
}