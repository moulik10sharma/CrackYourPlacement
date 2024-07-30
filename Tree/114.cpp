class Solution {
private:
    TreeNode* prev = nullptr;
    void flattenTree(TreeNode* node) {
        if (node == nullptr) return;
        flattenTree(node->right);
        flattenTree(node->left);
        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
public:
    void flatten(TreeNode* root) {
        prev = nullptr;
        flattenTree(root);
    }
};