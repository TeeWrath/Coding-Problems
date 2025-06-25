#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = right = nullptr;
    }
};

vector<int> iterativePostorder(TreeNode* root){
    vector<int> preOrder;
    if(root == NULL) return preOrder;

    stack<TreeNode*> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != nullptr) st1.push(root->left);
        if(root->right != nullptr) st1.push(root->right);
    }

    while(!st2.empty()){
        root = st2.top();
        st2.pop();
        preOrder.push_back(root->val);
    }
    return preOrder;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    root->right->left->right->right = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> ans = iterativePostorder(root);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}