class Solution {
public:
    int solve(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()-1)return 0;
        int mn=10001;
        int step=nums[idx];
        if(dp[idx]!=-1)return dp[idx];
        for(int j=1;j<=step;j++){
            if(idx+j<nums.size())
                mn=min(mn,1 + solve(idx+j,nums,dp));
        }
        return dp[idx] = mn;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(10001,-1);
        return solve(0,nums,dp);
    }
};