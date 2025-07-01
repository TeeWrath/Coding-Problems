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

TreeNode* findLastRight(TreeNode* root){
    if(!root->right)return nullptr;
    return findLastRight(root->right);

}

TreeNode* helper(TreeNode* root){
    if(root->left == nullptr)return root->right;
    else if(root->right == nullptr)return root->left;
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key){
    if(!root) return nullptr;
    if(root->val == key)return helper(root);
    TreeNode* dummy = root;

    while(root){
        if(root->val > key){
            if(root->left != nullptr && root->left->val == key){
                root->left = helper(root->left);
                break;
            }else root= root->left;
        }else{
            if(root->right != nullptr && root->right->val == key){
                root->right = helper(root->right);
                break;
            }else root = root->right;
        }
    }
    return dummy;
}