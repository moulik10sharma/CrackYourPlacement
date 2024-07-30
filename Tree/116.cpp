class Solution {
public:
    Node* connect(Node* node) {
        if (!node) return nullptr;
        Node* cur = node;
        Node* nxt = node->left;
        while (cur && nxt) {
            cur->left->next = cur->right;
            if (cur->next) {
                cur->right->next = cur->next->left;
            }
            cur = cur->next;
            if (!cur) {
                cur = nxt;
                nxt = cur->left;
            }
        }
        return node;
    }
};