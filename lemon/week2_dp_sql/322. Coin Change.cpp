class Solution {
public:
    int dp[1000001][15];
    int solve(vector<int>& coins, int amount, int ind){
        if(amount == 0) return 0;
        if(ind == 0) return INT_MAX-1;
        if(dp[amount][ind] != -1) return dp[amount][ind];
        int take = INT_MAX-1;
        if(coins[ind-1] <= amount){
            take = 1+ solve(coins, amount-coins[ind-1], ind);
        }
        int nottake = solve(coins, amount, ind-1);
        return dp[amount][ind] =  min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount, coins.size());
        
        if(ans == INT_MAX-1) return -1;
        else return ans;
    }
};