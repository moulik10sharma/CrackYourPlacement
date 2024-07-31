Node* help(int n, int pre[], char preLN[], int &index) {
    if (index >= n) return NULL;
    Node* temp = new Node(pre[index]);
    if (preLN[index] == 'N') {
        index++;
        temp->left = help(n, pre, preLN, index);
        temp->right = help(n, pre, preLN, index);
    } else {
        index++;
    }
    return temp;
}
Node* constructTree(int n, int pre[], char preLN[]) {
    int index = 0;
    return help(n, pre, preLN, index);
}