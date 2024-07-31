class Solution
{
    public:       
    void solve(Node* root,Node* &head, Node* &prev, int &flag)
    {
        if(!root)
            return;        
        solve(root->left,head,prev,flag);        
        if(!flag)
        {
            flag = 1;
            head = root;
            prev = root;
        }
        else
        {
            prev->right = root;
            prev ->right->left = prev;
            prev = prev->right;
        }        
        solve(root->right,head,prev,flag);
    }    
    Node* bToDLL(Node* root)
    {        
        Node* head = NULL;
        Node* prev = NULL;
        int flag = 0;
        solve(root,head,prev,flag);
        return head;
    }
};