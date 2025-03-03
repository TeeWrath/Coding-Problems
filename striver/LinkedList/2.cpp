/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // Dummy head for result
        ListNode* curr = dummy;             // Current node in result
        int carry = 0;                      // Carry for addition

        // Traverse both lists while there are digits or a carry
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            // Get digits (0 if list ends)
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            // Compute sum and new carry
            int total = x + y + carry;
            carry = total / 10;             // Carry for next digit
            int digit = total % 10;         // Current digit

            // Create new node with digit
            curr->next = new ListNode(digit);
            curr = curr->next;

            // Move to next nodes if available
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Return result, clean up dummy
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};