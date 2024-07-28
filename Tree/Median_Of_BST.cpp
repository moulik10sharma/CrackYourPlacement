void inorderTraversal(Node* root, vector<int>& elements) {
    if (root == nullptr) return;
    inorderTraversal(root->left, elements);
    elements.push_back(root->data);
    inorderTraversal(root->right, elements);
}
float findMedian(struct Node* root) {
    vector<int> elements;
    inorderTraversal(root, elements);
    int n = elements.size();
    if (n == 0) return 0; 
    if (n % 2 == 1) {        
        return elements[n / 2];
    } else {        
        return (elements[n / 2 - 1] + elements[n / 2]) / 2.0;
    }
}