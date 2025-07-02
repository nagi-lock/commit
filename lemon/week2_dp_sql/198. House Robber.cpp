class Solution {
public:
    int dp[401];
    int solve(vector<int>& nums, int ind){

        if(ind>=nums.size()) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int take = nums[ind]+ solve(nums, ind+2);
        int nottake = solve(nums, ind+1);
        return dp[ind] = max(take, nottake);

    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};
// On
// take it leave it