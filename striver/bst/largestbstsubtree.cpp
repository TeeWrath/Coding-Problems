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

class NodeValue{
    public:
    int minNode,maxNode,maxSize;
    NodeValue(int minNode,int maxNode,int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution{
    private:
    NodeValue largestBstSubtreeHelper(TreeNode* root){
        if(!root)return NodeValue(INT_MIN,INT_MAX,0);

        auto left = largestBstSubtreeHelper(root->left);
        auto right = largestBstSubtreeHelper(root->right);

        if(left.maxNode < root->val && right.minNode > root->val)return NodeValue(min(left.minNode,root->val),max(root->val,right.maxNode),left.maxSize+right.maxSize +1);

        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }

    public:
    int largstBSTSubtree(TreeNode* root){
        return largestBstSubtreeHelper(root).maxSize;
    }
};