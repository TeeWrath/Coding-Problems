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

vector<int> iterativePreorder(TreeNode* root){
    vector<int> preOrder;
    if(root == NULL) return preOrder;

    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preOrder.push_back(root->val);
        if(root->right != nullptr)st.push(root->right);
        if(root->left != nullptr)st.push(root->left);
    }

    return preOrder;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> ans = iterativePreorder(root);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}