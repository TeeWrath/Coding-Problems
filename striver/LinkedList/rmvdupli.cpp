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


// Using map
Node *removeDuplicates(Node *head)
    {
        if (!head || !head->next) return head;
        
        std::unordered_set<int> seen;
        Node *curr = head;
        seen.insert(curr->data);  // Store first node's value
        
        while (curr->next != nullptr)
        {
            if (seen.find(curr->next->data) != seen.end())  // Duplicate found
            {
                Node *del = curr->next;
                curr->next = del->next;
                if (del->next) {
                    del->next->prev = curr;
                }
                delete del;
            }
            else
            {
                seen.insert(curr->next->data);  // Insert new unique value
                curr = curr->next;  // Move forward
            }
        }
        
        return head;
    }

// Directly iterating- optimised
Node *removeDuplicates(Node *head)
    {
        if (!head || !head->next) return head;
        Node* tmp = head;
        Node* nextNode = tmp->next;
        
        while(tmp!= nullptr && tmp->next!= nullptr){
            nextNode = tmp->next;
            while(nextNode!=nullptr && nextNode->data == tmp->data){
                Node* dupli = nextNode;
                nextNode = nextNode->next;
                free(dupli);
            }
            if(nextNode!=nullptr) nextNode->prev = tmp;
            tmp->next = nextNode;
            tmp = tmp->next;
        }
        return head;
    }