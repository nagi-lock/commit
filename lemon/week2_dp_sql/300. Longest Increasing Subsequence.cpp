class Solution {
public:
    int dp[2501][2501];
    int solve(vector<int>& nums, int prev, int ind){

        if(ind == nums.size()) return 0;
        if(prev != -1 && dp[prev][ind] != -1) return dp[prev][ind];
        int take = 0;
        if(prev == -1 || nums[ind]>nums[prev]){
            take = 1+solve(nums, ind, ind+1);
        }
        int nottake = solve(nums, prev, ind+1);
        if(prev != -1){
            dp[prev][ind] = max(take, nottake);
        }
        return max(take, nottake);
    }       

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, -1, 0);
    }
};
// -1 wala issue dega logic
// On**2 tc and sc