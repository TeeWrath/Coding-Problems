#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        if (!head_ref || !(*head_ref)) return;

        Node* current = *head_ref;

        // Traverse and delete nodes with value x
        while (current) {
            if (current->data == x) {
                Node* toDelete = current;
                
                // Adjust previous node
                if (current->prev)
                    current->prev->next = current->next;
                else
                    *head_ref = current->next; // Update head if first node is deleted
                
                // Adjust next node
                if (current->next)
                    current->next->prev = current->prev;

                current = current->next;
                delete toDelete; // Free memory
            } else {
                current = current->next;
            }
        }
    }
};
