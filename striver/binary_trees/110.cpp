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

// Brute force O(n^2)
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(rh, lh);
}

bool isBalanced1(TreeNode *root)
{
    if (root == nullptr)
        return true;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    if (abs(lh - rh) <= 1 && isBalanced1(root->left) && isBalanced1(root->right))
        return true;

    return false;
}
// ----------------------------------------------------------------------------------------------
// Optimal approach below

int dfsHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = dfsHeight(root->left);
    int rh = dfsHeight(root->right);
    if ((abs(lh - rh) > 1) || lh == -1 || rh == -1)
        return -1;

    return 1 + max(lh, rh);
}
bool isBalanced(TreeNode *root)
{
    return dfsHeight(root) != -1;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    root->right->left->right->right = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << isBalanced(root) << endl;

    // vector<int> ans = iterativePostorder(root);
    // for(auto it: ans){
    //     cout << it << " ";
    // }
    return 0;
}