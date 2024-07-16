class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1, mx=INT_MIN;
        while(i<j){
            int water=(j-i)*min(height[i],height[j]);
            mx=max(mx,water);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return mx;
    }
};