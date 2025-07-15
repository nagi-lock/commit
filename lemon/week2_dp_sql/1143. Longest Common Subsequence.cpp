class Solution {
public:
    int dp[1001][1001];
    int solve(string& s1, int n, string& s2, int m){
        
        if(n==0 || m==0) return 0;
        if(dp[n][m]!= -1) return dp[n][m];
        if(s1[n-1] == s2[m-1]){
            return dp[n][m] = 1+solve(s1, n-1, s2, m-1);
        } else{
            return dp[n][m] = max(solve(s1, n-1, s2, m), solve(s1, n, s2, m-1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(text1, text1.size(), text2, text2.size());
    }
};