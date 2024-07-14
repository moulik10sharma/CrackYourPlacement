class Solution{
    public:
    long long findMinDiff(vector<long long> arr, long long n, long long m){
        if (m == 0 || n == 0)
        return 0;
        
        sort(arr.begin(), arr.end());
        
        if (n < m)
            return -1;
     
        int min_diff = INT_MAX;
     
        for (int i = 0; i + m - 1 < n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            if (diff < min_diff)
                min_diff = diff;
        }
        return min_diff;
    }   
};