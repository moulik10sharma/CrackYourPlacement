class Solution
{
    public:
    Node *reverseList(Node *head)
    {
        Node *prev = NULL, *current = head, *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        head = reverseList(head);        
        Node *current = head;
        int max_so_far = current->data;        
        Node *prev = current;
        current = current->next;        
        while (current != NULL)
        {
            if (current->data >= max_so_far)
            {
                max_so_far = current->data;
                prev = current;
                current = current->next;
            }
            else
            {
                prev->next = current->next;
                current = prev->next;
            }
        }
        head = reverseList(head);        
        return head;
    }
};