class Solution {
  public:
    Node* convertArrToLinkedList(vector<int>&arr){
        Node* dummyNode=new Node(-1);
        Node* temp=dummyNode;
        for(int i=0;i<arr.size();i++)
        {
            temp->bottom=new Node(arr[i]);
            temp=temp->bottom;
        }
        return dummyNode->bottom;
    }
    Node *flatten(Node *root) {
        vector<int> arr;
        while(root!=nullptr){
            Node* t2=root;
            while(t2!=nullptr){
                arr.push_back(t2->data);
                t2=t2->bottom;
            }
            root=root->next;
        }
        sort(arr.begin(),arr.end());
        return convertArrToLinkedList(arr);
    }
};