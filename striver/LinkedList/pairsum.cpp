#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// Optimized solution
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> arr;
        if(!head || !head->next) return arr;
        
        Node* right = head;
        while(right->next != nullptr){
            right = right->next;
        }
        
        Node* left = head;
        
        while(left!=right && left->prev != right){
            int sum = left->data + right->data;
            if(sum == target) {
                arr.push_back({left->data,right->data});
                left = left->next;
            right = right->prev;
            }
            else if(sum > target) right = right->prev;
            else left = left->next;
        }
        
        return arr;
    }
};