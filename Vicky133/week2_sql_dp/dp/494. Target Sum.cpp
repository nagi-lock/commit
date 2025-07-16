class Solution {
public:
    int solve(int i,int sum, int target, vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(sum==target)
                return 1;
            else return 0;
        }
        if(dp[i][sum+1000]!=-1)return dp[i][sum+1000];
        
        int plus = solve(i+1,sum+nums[i],target,nums,dp);
        int minus = solve(i+1,sum-nums[i],target,nums,dp);
        return dp[i][sum+1000] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2002,-1));
        return solve(0,0,target,nums,dp);

//button up
        // vector<vector<int>>dp(n+1,vector<int>(2001,-1));
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<)
        // }
    }
};