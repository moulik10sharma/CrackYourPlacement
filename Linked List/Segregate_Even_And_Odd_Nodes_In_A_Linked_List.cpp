class Solution {
  public:
    Node* divide(Node* head) {
        Node* slist = new Node(0);
        Node* blist = new Node(0);
        Node* small = slist;
        Node* big = blist;
        while (head != nullptr) {
            if (head->data%2==0) {
                small->next = head;
                small = small->next;
            } else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        small->next = blist->next;
        big->next = nullptr;
        return slist->next;     
    }
};