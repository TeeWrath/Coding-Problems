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

TreeNode* build(vector<int>& A,int& i, int bound){
    if(i==A.size() || A[i] > bound)return nullptr;
    TreeNode* root = new TreeNode(A[i++]);
    root->left = build(A,i,root->val);
    root->right = build(A,i,bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return build(preorder,i,INT_MAX);
}

int main(){
    // TreeNode* root = createBST();
    return 0;
}