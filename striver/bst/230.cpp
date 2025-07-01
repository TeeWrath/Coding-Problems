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

// very slow approach
// void inOrderTrav1(TreeNode* root, vector<int>& arr){
//     if(!root)return;
//     inOrderTrav(root->left,arr);
//     arr.push_back(root->val);
//     inOrderTrav(root->right,arr);
// }

// int kthSmallest1(TreeNode* root, int k) {
//     if(!root)return -1;
//     vector<int> arr;
//     inOrderTrav(root,arr);
//     return arr[k-1];
// }

TreeNode* inOrderTrav(TreeNode* root, int& cnt, int k) {  // Pass cnt by reference
    if (!root) return nullptr;
    
    // Traverse left subtree first (in-order)
    TreeNode* leftResult = inOrderTrav(root->left, cnt, k);
    if (leftResult) return leftResult;  // Found in left subtree
    
    // Process current node
    cnt++;
    if (cnt == k) return root;  // Found the k-th smallest
    
    // Traverse right subtree
    return inOrderTrav(root->right, cnt, k);
}

int kthSmallest(TreeNode* root, int k) {
    if (!root) return -1;  // Handle empty tree
    int cnt = 0;
    TreeNode* node = inOrderTrav(root, cnt, k);
    return node ? node->val : -1;  // Return -1 if k is out of bounds
}

int main(){
    TreeNode* root = createBST();
    // printBST(root);
    cout << "Tree is created, now enter k value: ";
    int k; cin >> k;
    cout << kthSmallest(root,k) << endl;
    return 0;
}