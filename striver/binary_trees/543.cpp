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

int getHeight(TreeNode* root,int& d){
    if(root == nullptr)return 0;
    int lh = getHeight(root->left,d);
    int rh = getHeight(root->right,d);
    d = max(d,lh+rh);

    return 1 + max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root) {
    int d = 0;

    getHeight(root,d);

    return  d;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    root->right->left->right->right = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}