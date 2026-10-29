#include <bits/stdc++.h>
using namespace std;
// UNDERSTAND THE RECURSIVE AND TWO POINTER SOLUTION
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int len = 0;

        // figure out the length
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        if(n > len)return nullptr;

        int t = len - n + 1; // the Tth node has to be deleted from the front
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        if(t==1){
            curr->next = nullptr;
            return nxt;
        }
        for(int i=1;i<t;i++){
            prev = curr;
            curr = curr->next;
            nxt = nxt->next;
        }
        
        prev->next = nxt;
        curr->next = nullptr;
        return head;
    }
};


ListNode *build(vector<int> vals)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (int v : vals)
    {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

void print(ListNode *head, int cap = 20)
{
    for (ListNode *p = head; p && cap--; p = p->next)
        cout << p->val << " ";
    cout << endl;
}

int main()
{
    for (auto vals : {vector<int>{1, 2, 3, 4},
                      vector<int>{1, 2, 3, 4, 5},
                      vector<int>{1, 2},
                      vector<int>{1}})
    {
        ListNode *head = build(vals);
        cout << "in:  ";
        print(head);
        cout << "Enter nth node to be deleted from last: ";
        int n; cin >> n;
        cout << endl;
        head = Solution().removeNthFromEnd(head,n);
        cout << "out: ";
        print(head);
        cout << endl;
    }
    return 0;
}