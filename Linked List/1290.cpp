class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimalValue = 0;
        ListNode* current = head;        
        while (current != NULL) {
            decimalValue = (decimalValue << 1) | current->val;
            current = current->next;
        }        
        return decimalValue;
    }
};