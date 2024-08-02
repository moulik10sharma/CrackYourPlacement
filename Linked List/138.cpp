class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;        
        while(temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }        
        temp = head;
        while(temp) {
            if(temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node* dummy = new Node(0);
        Node* dit = dummy;
        Node* it = head;        
        while(it) {
            temp = it->next->next;
            dit->next = it->next;
            it->next = temp;
            dit = dit->next;
            it = temp;
        }        
        return dummy->next;
    }
};