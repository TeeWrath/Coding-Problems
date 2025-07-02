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

class BSTIterator{
    stack<TreeNode*> mystack;
    // reverse = true -> before()
    // reverse = false -> next()
    bool reverse = true;

public:
    BSTIterator(TreeNode* root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !mystack.empty();
    }

    int next(){
        TreeNode* tmp = mystack.top();
        mystack.pop();
        if(!reverse)pushAll(tmp->right);
        else pushAll(tmp->left);
        return tmp->val;
    }

private:
    void pushAll(TreeNode* node){
        for(;node != NULL;){
            mystack.push(node);
            if(reverse == true)node= node->right;
            else node = node->left;
        }
    }

};