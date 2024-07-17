class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(arr.size(), false);
        backtrack(arr, result, current, visited);
        return result;
    }
  private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& visited) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) {
                continue;
            }
            visited[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, result, current, visited);
            current.pop_back();
            visited[i] = false;
        }
    }
};