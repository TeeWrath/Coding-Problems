#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
         if (!head || !head->next) return;
        
         ListNode *slow = head;
        ListNode *fast = head;
        // reaching midpoint
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the list from slow->next to fast;
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr; //split dont join

        while (curr)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // now prev is at the first node of the second half
        ListNode* first = head;
        ListNode* second = prev;
        while(second){
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
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
        Solution().reorderList(head);
        cout << "out: ";
        print(head);
        cout << endl;
    }
    return 0;
}