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

// Brute force, sc - o(n) due to stack
ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    stack<int> st = {};

    while (temp != nullptr)
    {
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr)
    {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

// Optimal - 1 Iteratively
ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = nullptr;
    ListNode *front = nullptr;

    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    free(temp);
    free(front);
    return prev;
}

// Optimal 2 - Recurseively
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