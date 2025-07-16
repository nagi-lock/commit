class Solution {
public:
    //bottom up
    //like coin change
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1);
        dp[0] = 1;
        for(int curTarget = 1;curTarget<=target;curTarget++){
            for(auto &num:nums){
                if(num<=curTarget){
                    dp[curTarget]+=dp[curTarget-num];
                }
            }
        }
        return dp[target];
    }
};