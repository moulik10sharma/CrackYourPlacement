class Solution {
private:
    int total = 0;
    void findPathSum(TreeNode* curr, long long sum, int target, unordered_map<long long, int>& hm) {
        if (curr == nullptr)
            return;
        sum += curr->val;
        if (hm.find(sum - target) != hm.end())
            total += hm[sum - target];
        hm[sum] = hm.count(sum) ? hm[sum] + 1 : 1;
        findPathSum(curr->left, sum, target, hm);
        findPathSum(curr->right, sum, target, hm);
        hm[sum]--;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return 0;
        unordered_map<long long, int> hm;
        hm[0] = 1;
        findPathSum(root, 0, sum, hm);
        return total;
    }
};