    class Solution {
    public:
        int solve(int n, vector<int>&nums,vector<int>&dp){
            if(n==0)return nums[0];
            if(n<0)return 0;

            int pick = nums[n]+solve(n-2,nums,dp);
            int notPick = solve(n-1,nums,dp);
            return dp[n]  = max(pick, notPick);
        }
        int rob(vector<int>& nums) {
            int n=nums.size();
            // vector<int>dp(n+1,-1);
            // return solve(n-1,nums,dp);

            vector<int>dp(n,0);
            if(n==0)return 0;
            if(n==1)return nums[0];
            dp[0]=nums[0];
            for(int i=1;i<n;i++){
                int pick = nums[i];
                if(i>1)pick+=dp[i-2];
                int notPick = dp[i-1];
                dp[i]=max(pick, notPick); 
            }
            return dp[n-1];
            //tc:O(n) sc:O(n)
        }
    };