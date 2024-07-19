class Solution {
public:
    void findPaths(TreeNode* node, string path, vector<string>& paths){
        if(node==nullptr) return;
        if(!path.empty()) path+="->";
        path+=to_string(node->val);
        if(node->left==nullptr&&node->right==nullptr){
            paths.push_back(path);
        }
        else{
            findPaths(node->left,path,paths);
            findPaths(node->right,path,paths);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root){
            findPaths(root,"",paths);
        }
        return paths;
    }
};