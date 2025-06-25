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

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(rh, lh);
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

    int h = maxDepth(root);
    cout << h << endl;

    // vector<int> ans = iterativePostorder(root);
    // for(auto it: ans){
    //     cout << it << " ";
    // }
    return 0;
}