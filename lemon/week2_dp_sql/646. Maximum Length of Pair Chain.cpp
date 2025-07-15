class Solution {
public:
    // int dp[1001][1001];
    // int solve(vector<vector<int>>& pairs, int prev, int ind){
    //     if(ind == pairs.size()) return 0;
    //     if( prev != -1 && dp[prev][ind] != -1) return dp[prev][ind];
    //     int take = 0;
    //     if(prev == -1 || pairs[ind][0]> pairs[prev][1]){
    //         take = 1+ solve(pairs, ind, ind+1);
    //     }
    //     int nottake = solve(pairs, prev, ind+1);

    //     if(prev != -1){
    //         dp[prev][ind] = max(take, nottake);
    //     }
    //     return max(take, nottake);
    // }

    int findLongestChain(vector<vector<int>>& pairs) {
        // int prev = -1, ind = 0;
        // memset(dp, -1, sizeof(dp));
        sort(pairs.begin(), pairs.end());
        // return solve(pairs, prev, ind);

        vector<int> ans(pairs.size(), 1);
        int maxi = 1;
        for(int i = 0; i< pairs.size(); i++){
            for(int j = 0; j< i; j++){
                if(pairs[i][0]> pairs[j][1]){
                    ans[i] = max(ans[i], 1+ans[j]);
                    maxi = max(maxi, ans[i]);
                }
            }
        }
        return maxi;


    }
};
// tricky hai bottom up, top down d2a hai
// on**2