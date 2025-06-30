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

// TC- O(log2(N))
TreeNode* searchBST(TreeNode* root,int val){
    while(root && root->val!=val)root = val < root->val?root->left:root->right;
    return root;
}