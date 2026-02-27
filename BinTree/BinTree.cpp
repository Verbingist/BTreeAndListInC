#include "BinTree.hpp"

BinTree::BinTree() : head(nullptr), lastId(0) {}

TreeNode *BinTree::getNode(time_t time)
{
    return getNode(time, head);
}

TreeNode *BinTree::getNode(time_t time, TreeNode *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->getData().getTime() < time)
    {
        return getNode(time, node->getRight());
    }
    else if (node->getData().getTime() > time)
    {
        return getNode(time, node->getLeft());
    }
    return node;
}

bool BinTree::addNode(time_t time, float price, std::string name)
{
    TreeNode *newNode = new TreeNode(time, price, name, lastId);
    head = addNode(newNode, head);
    lastId++;
    return true;
}

TreeNode *BinTree::addNode(TreeNode *newNode, TreeNode *node)
{
    if (node == nullptr)
    {
        return newNode;
    }
    if (node->getData().getTime() < newNode->getData().getTime())
    {
        node->setRight(addNode(newNode, node->getRight()));
    }
    else
    {
        node->setLeft(addNode(newNode, node->getLeft()));
    }
    return node;
}

bool BinTree::updateNode(time_t time, float price, std::string name)
{
    TreeNode *node = getNode(time);
    if (node == nullptr)
    {
        return false;
    }
    node->getData().setName(name);
    node->getData().setPrice(price);
    return true;
}

int BinTree::getSize()
{
    return getSize(head);
}

int BinTree::getSize(TreeNode *node)
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

int BinTree::getDepth()
{
    return getDepth(head);
}

int BinTree::getDepth(TreeNode *node)
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

bool BinTree::deleteNode(time_t time)
{
    TreeNode *node = getNode(time);
    if (node == nullptr)
    {
        return false;
    }

    if (node->getLeft() == nullptr && node->getRight() == nullptr)
    {
        TreeNode *parent = findOneUpper(node);
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
            TreeNode *parent = findOneUpper(node);
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
            TreeNode *parent = findOneUpper(node);

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
        TreeNode *parent = findOneUpper(node);
        TreeNode *min = findMinRight(node->getRight());

        if (min->getLeft())
        {
            TreeNode *minParent = findOneUpper(min);
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
            TreeNode *minParent = findOneUpper(min);
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
            return true;
        }

        if (parent->getLeft() == node)
        {
            parent->setLeft(min);
        }
        else
        {
            parent->setRight(min);
        }

        delete node;
    }

    return true;
}

TreeNode *BinTree::findOneUpper(TreeNode *node)
{
    if (node == head || node == nullptr)
    {
        return nullptr;
    }

    for (TreeNode *cur = head; cur != nullptr;)
    {
        if (cur->getLeft() == node || cur->getRight() == node)
        {
            return cur;
        }
        if (node->getData().getTime() < cur->getData().getTime())
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

TreeNode *BinTree::findMinRight(TreeNode *node)
{
    TreeNode *cur = node;
    for (; cur && cur->getLeft() != nullptr; cur = cur->getLeft())
        ;
    return cur;
}

bool BinTree::loadFromFile(std::string filePath)
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

bool BinTree::saveToFile(std::string filePath)
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

void BinTree::saveNodeToFile(std::ofstream &outFile, TreeNode *node)
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

void BinTree::memoryClear()
{
    memoryClear(head);
    head = nullptr;
}

void BinTree::memoryClear(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    memoryClear(node->getLeft());
    memoryClear(node->getRight());
    delete node;
}

std::vector<TreeNode *> BinTree::getPageElements(int number, TreeNode *prevHead)
{
    std::vector<TreeNode *> resultVector(3, nullptr);
    if (prevHead == nullptr)
        prevHead = head;

    if (prevHead == nullptr)
        return resultVector;

    if (number == 0)
    {
        TreeNode *parent = findOneUpper(prevHead);
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

int BinTree::getNumberOfLeafs()
{
    if (head == nullptr)
        return 0;
    return getNumberOfLeafs(head);
}

int BinTree::getNumberOfLeafs(TreeNode *node)
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