class Solution {
public:
    int climb(int n, vector<int>&dp){
        if(n<0)return 0;
        if(n==0){ return 1;}
        if(dp[n]!=-1)return dp[n];
        int left = climb(n-1, dp);
        int right = climb(n-2, dp);
        return dp[n]= left+right;
    }
    int climbStairs(int n) {
        //1.recursion+memoization(top down)
        //tc:O(n), sc:O(n)+O(n)
        // vector<int>dp(n+1,-1);
        // return climb(n,dp);
        
        //iterative dp
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        //tc:O(n), sc:O(n)
    }
};