class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int pre=0,suf=0,n=nums.size(),mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suf==0)suf=1;
            pre*=nums[i];
            suf*=nums[n-i-1];
            mx=max(mx,max(pre,suf));
        }
        return mx;
    }
};