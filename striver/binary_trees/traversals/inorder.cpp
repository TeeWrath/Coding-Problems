#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

void inOrder(Node* root, vector<int>& arr){
    if(root == nullptr) return;

    inOrder(root->left,arr);
    arr.push_back(root->data);
    inOrder(root->right,arr);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> arr;

    inOrder(root,arr);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}