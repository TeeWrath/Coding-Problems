#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

bool isSymUtil(TreeNode *leftNode, TreeNode *rightNode)
{
    if (leftNode == NULL || rightNode == NULL)
    {
        return leftNode == rightNode;
    }

    return (leftNode->val == rightNode->val && isSymUtil(leftNode->left, rightNode->right) && isSymUtil(leftNode->right, rightNode->left));
}
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;

    return isSymUtil(root->left, root->right);
}