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

class Solution {
    private:
        TreeNode* first;
        TreeNode* prev;
        TreeNode* mid;
        TreeNode* last;
    private:
        void inorder(TreeNode* root){
            if(!root)return;

            inorder(root->left);
            if(prev && (root->val < prev->val)){
                if(!first){
                    first = prev;
                    mid = root;
                }else last = root;
            }
            prev = root;
            inorder(root->right);
        }
    public:
        void recoverTree(TreeNode* root) {
            first=mid=last=NULL;
            prev = new TreeNode(INT_MIN);
            inorder(root);
            if(first && last) swap(first->val,last->val);
            else if(first && mid)swap(first->val,mid->val);
        }
    };