#include "BinTree.hpp"

BinTree::BinTree() : head(nullptr) {}

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

bool BinTree::addNode(Data task_data)
{
    if (getNode(task_data.getTime()))
    {
        return false;
    }
    TreeNode *newNode = new TreeNode(task_data);
    head = addNode(newNode, head);
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

bool BinTree::updateNode(time_t time, Data task_data)
{
    TreeNode *node = getNode(time);
    if (node == nullptr)
    {
        return false;
    }
    node->getData().setName(task_data.getName());
    node->getData().setPrice(task_data.getPrice());
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
        TreeNode *min = findMinRight(node->getRight());
        TreeNode *parent = findOneUpper(node);

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