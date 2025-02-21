#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute force using stack
bool isPalindrome(ListNode *head)
{
    stack<int> st = {};
    if (!head || !head->next)
        return true;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (st.top() != temp->val)
            return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

// Optimal approach - reversing half of list
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *newHead = reverseList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *newHead = reverseList(slow->next);

    ListNode *first = head;
    ListNode *second = newHead;

    while (second != nullptr)
    {
        if (first->val != second->val)
        {
            reverseList(second);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseList(newHead);
    return true;
}