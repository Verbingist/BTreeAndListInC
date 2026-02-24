#include "TreeNode.hpp"
#include "../Data.hpp"

class BinTree
{
public:
    BinTree();
    TreeNode *getNode(time_t time);
    bool addNode(Data task_data);
    bool deleteNode(time_t time);
    bool updateNode(time_t time, Data task_data);
    int getSize();
    int getDepth();

private:
    TreeNode *head;
    TreeNode *getNode(time_t time, TreeNode *node);
    TreeNode *addNode(TreeNode *newNode, TreeNode *node);
    int getSize(TreeNode *node);
    int getDepth(TreeNode *node);
    TreeNode *findOneUpper(TreeNode *node);
    TreeNode *findMinRight(TreeNode *node);
};