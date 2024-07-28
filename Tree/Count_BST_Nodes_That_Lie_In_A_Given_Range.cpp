class Solution {
public:
    int getCount(Node *root, int l, int h) {
        if (root == NULL) {
            return 0;
        }
        int val = root->data;
        if (val >= l && val <= h) {
            return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
        } else if (val < l) {
            return getCount(root->right, l, h);
        } else {
            return getCount(root->left, l, h);
        }
    }
};