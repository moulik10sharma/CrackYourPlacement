class Solution {
  public:
    int findPair(int n, int x, vector<int> &nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-x)!=mp.end() || mp.find(nums[i]+x)!=mp.end()) return true;
            mp[nums[i]]++;
        }
        return -1;
    }
};