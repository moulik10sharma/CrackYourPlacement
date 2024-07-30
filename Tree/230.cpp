class Solution {
private:
    void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
        if (!node || counter >= k) return;
        inorder(node->left, counter, k, kSmallest);
        counter++;
        if (counter == k) {
            kSmallest = node->val;
            return;
        }
        inorder(node->right, counter, k, kSmallest);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int kSmallest = INT_MIN;
        int counter = 0;
        inorder(root, counter, k, kSmallest);
        return kSmallest;
    }
};
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}