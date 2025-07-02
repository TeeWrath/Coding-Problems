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

// not a good approach, sc - O(H)
int inorderSuccesor(TreeNode* root, int key){
    if(!root) return -1;
    int lh = inorderSuccesor(root->left,key);
    if(root->val > key)return root->val;
    int rh = inorderSuccesor(root->right,key);
    return lh == -1?rh:lh;
}

// best approach
TreeNode* inordersuccesor(TreeNode* root, TreeNode* p){
    TreeNode* successor = NULL;

    while(root){
        if(p->val >= root->val)root = root->right;
        else{
            successor = root;
            root = root->left;
        }
    }

    return successor;
}


int main(){
    TreeNode* root = createBST();
    TreeNode* p = new TreeNode(8);
    cout << inordersuccesor(root,p)->val << endl;
    return 0;
}