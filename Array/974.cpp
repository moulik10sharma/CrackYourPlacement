class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;
        int sum = 0, count = 0;
        
        for (int num : nums) {
            sum += num;
            int remainder = ((sum % k) + k) % k;
            if (prefixSumFreq.find(remainder) != prefixSumFreq.end()) {
                count += prefixSumFreq[remainder];
            }
            prefixSumFreq[remainder]++;
        }
        
        return count;
    }
};