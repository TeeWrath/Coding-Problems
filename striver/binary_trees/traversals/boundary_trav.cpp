#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

bool isLeaf(TreeNode* root){
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode* root, vector<int> res){
    TreeNode* cur = root->left;

    while(cur){
        if(!isLeaf(cur))res.push_back(cur->val);
        if(cur->left)cur = cur->left;
        else cur = cur->right;
    }
}

void addRightBoundary(TreeNode* root, vector<int> res){
    TreeNode* cur = root->right;
    stack<int> st;
    while(cur){
        if(!isLeaf(cur))st.push(cur->val);
        if(cur->right)cur = cur->right;
        else cur = cur->left;
    }

    while(!st.empty()){
        res.push_back(st.top());st.pop();
    }
}

void addLeaves(TreeNode* root, vector<int> res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left)addLeaves(root->left,res);
    if(root->right)addLeaves(root->right,res);
}

vector<int> boundaryTraversal(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->val);
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);
    return res;
}

int main(){
    return 0;
}