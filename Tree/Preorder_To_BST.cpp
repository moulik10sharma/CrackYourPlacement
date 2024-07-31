class Solution {
public:    
    Node* rec(int pre[], int n, int &i, int mi, int mx) {
    if (i >= n) return NULL;
    if (pre[i] < mi || pre[i] > mx) return NULL;
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = pre[i++];
    root->left = NULL;
    root->right = NULL;
    root->left = rec(pre, n, i, mi, root->data - 1);
    root->right = rec(pre, n, i, root->data, mx);
    return root;
    }   
    Node* Bst(int pre[], int size) {
        int i = 0;
        int mi = INT_MIN; 
        int mx = INT_MAX;
        return rec(pre, size, i, mi, mx);
    }
};