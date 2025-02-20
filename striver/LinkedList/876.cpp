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

int lenOfLl(ListNode *head)
{
    int cnt = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// Brute force
ListNode *middleNode(ListNode *head)
{
    int n = lenOfLl(head);
    int mid = (n / 2) + 1;
    int cnt = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == mid)
            break;
        temp = temp->next;
    }
    return temp;
}

// Tortoise and Hare Algo
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}