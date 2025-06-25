class Solution {
public:
    int dp[101];
    int solve(string s, int ind){
        if(ind == s.size()) return 1;

        if(s[ind] == '0') return 0;
        if(dp[ind]!=-1) return dp[ind];

        int take = solve(s, ind+1);
        int not_take = 0;

        if(ind + 1 < s.size() && (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6'))) {
    not_take = solve(s, ind + 2);
}
        return dp[ind] = take+not_take;

    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};