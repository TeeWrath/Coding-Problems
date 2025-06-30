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

// return min and max valued element of bst
int returnMin(TreeNode* root){
    if(!root)return -1;
    if(root->left == NULL)return root->val;
    returnMin(root->left);
}

int returnMax(TreeNode* root){
    if(!root)return -1;
    if(root->right == NULL)return root->val;
    returnMax(root->right);
}