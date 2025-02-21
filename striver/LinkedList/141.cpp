#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute force, using hashing
bool hasCycle(ListNode *head)
{
    map<ListNode *, int> mpp;
    ListNode *temp = head;

    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
            return true;
        mpp[temp] = 1;
        temp = temp->next;
    }

    return false;
}

// Better approach - my approach
bool hasCycle(ListNode *head)
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        if (temp->val == INT_MIN)
            return true;
        temp->val = INT_MIN;
        temp = temp->next;
    }

    return false;
}

// Using tortoise hare algo - slower than previous apporoach but safer as input must not be modified
bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }

        return false;
    }

int main()
{
    return 0;
}