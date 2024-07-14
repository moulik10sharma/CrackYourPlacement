class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] != 0) {
                swap(nums[i], nums[r]);
                ++i;
            }
        }
    }
};