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

vector<int> bottomView(TreeNode* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    map<int,int> mpp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        mpp[line] = node->val;
        if(node->left != nullptr)q.push({node->left,line-1});
        if(node->right != nullptr)q.push({node->right,line+1});
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }

    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    // root left part
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    // root right part
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(11);
    root->right->right->left = new TreeNode(10);

    vector<int> ans = bottomView(root);

    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}