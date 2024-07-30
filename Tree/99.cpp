class Solution {
private:
    TreeNode *first, *prev, *middle, *last;
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void inorder(TreeNode *root) {
        if (root == NULL) return;
        inorder(root->left);
        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode *root) {
        first = middle = last = NULL;
        prev = nullptr;
        inorder(root);
        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};