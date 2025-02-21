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

// Optimal approach