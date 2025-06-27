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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;
    if (p->val != q->val)
        return false;
    if (isSameTree(p->left, q->left) == false)
        return false;
    if (isSameTree(p->right, q->right) == false)
        return false;
    return true;
}