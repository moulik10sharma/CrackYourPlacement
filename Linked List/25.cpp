class Solution {
public:
    ListNode* reverseLinkedList(ListNode *head) {
        ListNode* temp = head;  
        ListNode* prev = NULL;  
        while(temp != NULL){  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }
        return prev;  
    }
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while(temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        while(temp != nullptr) {
            ListNode* KthNode = getKthNode(temp, k);
            if(KthNode == nullptr) {
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = nullptr;
            reverseLinkedList(temp);
            if(temp == head) {
                head = KthNode;
            } else {
                prevLast->next = KthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};