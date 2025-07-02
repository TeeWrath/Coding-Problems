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

bool findTargets(TreeNode* root, int k) {
    if(!root)return false;
    map<int,int> mpp;
    return isFound(root,k,mpp);
}

class BSTIterator{
    stack<TreeNode*> mystack;
    // reverse = true -> before()
    // reverse = false -> next()
    bool reverse = true;

public:
    BSTIterator(TreeNode* root,bool isReverse){
        reverse = isReverse;

    }

    bool hasNext(){
        return !mystack.empty();
    }

    int next(){
        TreeNode* tmp = mystack.top();
        mystack.pop();
        if(!reverse)pushAll(tmp->right);
        else pushAll(tmp->left);
        return tmp->val;
    }

private:
    void pushAll(TreeNode* node){
        for(;node != NULL;){
            mystack.push(node);
            if(reverse == true)node= node->right;
            else node = node->left;
        }
    }

};

class Solution {
    public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j == k)return true;
            else if(i+j <k)i= l.next();
            else j = r.next();
        }
        return false;
    }
    };

int main(){
    TreeNode* root = createBST();
    cout << Solution().findTarget(root,28) << endl;
    return 0;
}