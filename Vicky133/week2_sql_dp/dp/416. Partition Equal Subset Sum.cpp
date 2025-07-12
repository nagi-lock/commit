class Solution {
public:
    bool solve(int i,int sm, vector<int>&nums, vector<vector<int>>&dp){
        if(sm==0)return true;
        if(sm<0||i>=nums.size())return false;
        if(dp[i][sm]!=-1)return dp[i][sm];

        bool take = false;
        if(sm>=nums[i])
            take = solve(i+1,sm-nums[i],nums,dp);
        bool notTake = solve(i+1,sm,nums,dp);
        return dp[i][sm] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int sm = accumulate(nums.begin(),nums.end(),0);
        if(sm%2!=0)
            return false;
        int target = sm/2;
        // vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        // return solve(0,sm/2,nums,dp);

//bottom up
        int n=nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int sum = 0;sum<=target;sum++){
                bool take = false;
                if(sum>=nums[i]){
                    take = dp[i+1][sum-nums[i]];
                }
                bool notTake = dp[i+1][sum];
                dp[i][sum]= take||notTake;
            }
        }
        return dp[0][target];
    }
};