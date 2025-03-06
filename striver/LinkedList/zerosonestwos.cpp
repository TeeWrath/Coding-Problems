#include<bits/stdc++.h>
using namespace std;

 // Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// TC - O(2n)
Node* segregate(Node* head) {
        Node* tmp = head;
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        // Iterating and storing the values;
        while(tmp != nullptr){
            if(tmp->data == 0) zeros++;
            else if(tmp->data == 1)ones++;
            else twos++;
            tmp = tmp->next;
        }
        
        tmp = head;
        
        // now replace the data
        while(tmp != nullptr){
            if(zeros != 0){
                tmp->data = 0;
                zeros--;
            }
            else if(ones != 0){
                tmp->data = 1;
                ones--;
            }
            else{
                tmp->data = 2;
                twos--;
            }
            tmp = tmp->next;
        }
        
        return head;
    }


// Optimized Solution - TC: O(n)
Node* segregate(Node* head) {
        if(head == nullptr || head->next == nullptr)return head;
        Node* tmp = head;
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        
        while(tmp != nullptr){
            if(tmp->data == 0){
                zero->next = tmp;
                zero = tmp;
            }else if(tmp->data == 1){
                one->next = tmp;
                one = tmp;
            }else{
                two->next = tmp;
                two = tmp;
            }
            tmp = tmp->next;
        }
        
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;
        
        Node* newHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return newHead;
    }