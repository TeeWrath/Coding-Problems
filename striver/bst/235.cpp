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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    TreeNode* cur = root;
    while(true){
        if(cur->val <= val){
            if(cur->right != nullptr)cur = cur->right;
            else{
                cur->right = new TreeNode(val);
                break;
            }
        }else{
            if(cur->left != nullptr)cur = cur->left;
            else{
                cur->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

TreeNode* createBST(){
    int rt;
    cout << "Enter root value: ";
    cin >> rt;
    TreeNode* root = new TreeNode(rt);
    while(true){
        cout << "Enter whole numeric value: ";
        int value; cin >> value;
        if(value == -1)break;
        root = insertIntoBST(root,value);
    }

    return root;
}

void printBST(TreeNode* root){
    if(!root)return;
    cout << root->val << " ";
    printBST(root->left);
    printBST(root->right);
}

// Using recursion - this a bit slower
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)return nullptr;
    int cur = root->val;
    if(cur < p->val && cur < q->val) return lowestCommonAncestor(root->right,p,q);
    if(cur > p->val && cur > q->val) return lowestCommonAncestor(root->left,p,q);
    return root;
}

// Using loop - bit faster
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)return root;

    while(root){
        int cur = root->val;
        if(cur > p->val and cur > q->val) root = root->left;
        else if(cur < p->val and cur < q->val) root = root->right;
        else return root;
    }

    return nullptr;
}

int main(){
    TreeNode* root = createBST();
    return 0;
}