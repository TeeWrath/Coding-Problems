#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Optimal sol
ListNode *deleteMiddle(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;
    ListNode *slow = head;
    ListNode *fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}