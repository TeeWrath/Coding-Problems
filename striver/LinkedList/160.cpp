/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse until pointers meet or both reach nullptr
        while (ptrA != ptrB) {
            // Move to next node, or switch to other list's head if end reached
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        return ptrA;  // Either the intersection node or nullptr
    }
};