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

vector<int> iterativeInorder(TreeNode* root){
    vector<int> preOrder;
    if(root == NULL) return preOrder;

    stack<TreeNode*> st;
    while(true){
        if(root != nullptr){
            st.push(root);
            root = root->left;
        }else{
            if(st.empty())break;
            root = st.top();
            st.pop();
            preOrder.push_back(root->val);
            root = root->right;
        }
    }

    return preOrder;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> ans = iterativeInorder(root);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}