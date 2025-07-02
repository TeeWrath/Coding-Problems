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

// slow solution
bool isFound(TreeNode* root, int k, map<int,int> &mpp){
    if(!root)return false;
    if(mpp.find(k - root->val) != mpp.end())return true;
    mpp[root->val] = k - root->val;
    bool lh = isFound(root->left,k,mpp);
    bool rh = isFound(root->right,k,mpp);
    return lh || rh;
}

bool findTarget(TreeNode* root, int k) {
    if(!root)return false;
    map<int,int> mpp;
    return isFound(root,k,mpp);
}

int main(){
    TreeNode* root = createBST();
    cout << findTarget(root,28) << endl;
    return 0;
}