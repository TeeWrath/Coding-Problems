#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        val = val;
        left = right = nullptr;
    }
};

void postOrder(Node* root, vector<int>& arr){
    if(root == nullptr) return;

    postOrder(root->left,arr);
    postOrder(root->right,arr);
    arr.push_back(root->val);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> arr;

    postOrder(root,arr);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}