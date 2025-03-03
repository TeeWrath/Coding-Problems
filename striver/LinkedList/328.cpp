#include<bits/stdc++.h>
using namespace std;

// Brute force - Using Hash Array SC - O(n), TC - O(n+n) = O(n)
ListNode* oddEvenList(ListNode* head) {
        vector<int> hashArr;
        ListNode* tmp = head;
        int i=0;
        while(tmp != nullptr){
            hashArr.insert(hashArr.begin()+i,tmp->val);
            tmp = tmp->next;
            i++;
        }
        tmp = head;
        // odd = 0; even = 1;
        for(int i=0; i<hashArr.size(); i+=2){
            tmp->val = hashArr[i];
            tmp = tmp->next;
        }

        for(int i=1; i<hashArr.size();i+=2){
            tmp->val = hashArr[i];
            tmp = tmp->next;
        }

        return head;
    }

// Optimised solution - SC - O(1), TC - O(n)
ListNode* oddEvenList(ListNode* head) {
        // Handle empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;           // First node (odd)
        ListNode* even = head->next;    // Second node (even)
        ListNode* evenHead = even;      // Preserve even list head

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;     // Link odd to next odd
            odd = odd->next;            // Move odd pointer
            even->next = odd->next;     // Link even to next even
            even = even->next;          // Move even pointer
        }

        odd->next = evenHead;           // Connect odd list to even list
        return head;
    }
