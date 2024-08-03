class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;        
        ListNode *next = head->next;
        if (next->val == head->val) {
            while (next && next->val == head->val) next = next->next;
            return deleteDuplicates(next);
        } else {
            head->next = deleteDuplicates(next);
            return head;
        }
    }
};