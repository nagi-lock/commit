
class Solution {
public:
    int jump(vector<int>& nums) {
        int curEnd = 0, farthest = nums[0], jumps = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);//greedy and bfs
            if (curEnd == i) {
                jumps++;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};




////dp based
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> dp(n, INT_MAX);
//     dp[0] = 0;

//     for (int i = 0; i < n; ++i) {
//         for (int j = 1; j <= nums[i] && i + j < n; ++j) {
//             dp[i + j] = min(dp[i + j], dp[i] + 1);
//         }
//     }

//     return dp[n - 1];
// }

// };