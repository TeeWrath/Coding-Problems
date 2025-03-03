// /**
//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//  */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create dummy node to simplify head removal
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *fast = dummyHead; // Start fast at dummy
        ListNode *slow = dummyHead; // Start slow at dummy

        // Move fast n nodes ahead
        for (int i = 0; i < n; i++)
        {
            fast = fast->next; // Assumes n <= length of list
        }

        // Move both until fast reaches the end
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // slow is now at the node before the one to delete
        ListNode *toDel = slow->next;
        slow->next = slow->next->next;

        // Clean up
        delete toDel;
        ListNode *newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};