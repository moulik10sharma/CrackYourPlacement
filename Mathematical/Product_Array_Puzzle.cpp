class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> left(n,1), right(n,1), p(n);
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){
            left[i]=nums[i-1]*left[i-1];
        }
        for(int j=n-2;j>=0;j--){
            right[j]=nums[j+1]*right[j+1];
        }
        for(int k=0;k<n;k++){
            p[k]=left[k]*right[k];
        }
        return p;
    }
};