
int findLevel(Node *root, int k, int level) {
    if (root == NULL) return -1;
    if (root->data == k) return level;    
    int l = findLevel(root->left, k, level + 1);
    return (l != -1) ? l : findLevel(root->right, k, level + 1);
}
Node *findDistU(Node *root, int a, int b, int &d1, int &d2, int &dist, int lvl) {
    if (root == NULL) return NULL;
    if (root->data == a) {        
        d1 = lvl;
        return root;
    }
    if (root->data == b) {        
        d2 = lvl;
        return root;
    }    
    Node *l = findDistU(root->left, a, b, d1, d2, dist, lvl + 1);
    Node *r = findDistU(root->right, a, b, d1, d2, dist, lvl + 1);
    if (l and r) {        
        dist = d1 + d2 - 2 * lvl;
    }    
    return (l != NULL) ? l : r;
}
class Solution{
    public:
    int findDist(Node *root, int a, int b) {
        int d1 = -1, d2 = -1, dist;    
        Node *lca = findDistU(root, a, b, d1, d2, dist, 1);
        if (d1 != -1 and d2 != -1) {        
            return dist;
        }
        if (d1 != -1) {        
            dist = findLevel(lca, b, 0);
            return dist;
        }
        if (d2 != -1) {        
            dist = findLevel(lca, a, 0);
            return dist;
        }    
        return -1;
    }
};