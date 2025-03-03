// Optimized
class Solution {
public:

    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                tmp->next = list1;
                list1 = list1->next;
            }else{
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }

        if(list1 != nullptr){
            tmp->next = list1;
        }else{
            tmp->next = list2;
        }

        return dummy->next;
    }

    ListNode* findMiddle(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoSortedLists(left,right);         
    }
};