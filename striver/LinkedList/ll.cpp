#include<bits/stdc++.h>
using namespace std;

// Structure for LinkedList
class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* convertArrToLl(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp =  new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Length of Ll
int lenOfLl(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        // cout << temp->data<< endl;
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// Search in Ll
bool checkIfPresent(Node* head, int num){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == num) return true;
        temp = temp->next;
    }

    return false;
}

int main(){
    vector<int> arr = {6,1,2,3,4,5};
    Node* head = convertArrToLl(arr);

    // Traversal of LL
    // Node* temp = head;
    // while(temp != nullptr){
    //     cout << temp->data<< endl;
    //     temp = temp->next;
    // }

    // cout << lenOfLl(head);
    cout << checkIfPresent(head, 0);
    return 0;
}