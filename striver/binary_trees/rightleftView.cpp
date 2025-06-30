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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<int> rightSideView(TreeNode* root) {
    vector<vector<int>> level = levelOrder(root);
    vector<int> ans;
    for(auto it: level){
        ans.push_back(it[it.size()-1]);
    }

    return ans;
}

vector<int> leftSideView(TreeNode* root) {
    vector<vector<int>> level = levelOrder(root);
    vector<int> ans;
    for(auto it: level){
        ans.push_back(it[0]);
    }

    return ans;
}