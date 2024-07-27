class Solution
{
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre = NULL;
        suc = NULL;
        findPredecessor(root, pre, key);
        findSuccessor(root, suc, key);
    }
private:
    void findPredecessor(Node* root, Node*& pre, int key) {
        while (root != NULL) {
            if (root->key >= key) {
                root = root->left;
            } else {
                pre = root;
                root = root->right;
            }
        }
    }
    void findSuccessor(Node* root, Node*& suc, int key) {
        while (root != NULL) {
            if (root->key <= key) {
                root = root->right;
            } else {
                suc = root;
                root = root->left;
            }
        }
    }
};