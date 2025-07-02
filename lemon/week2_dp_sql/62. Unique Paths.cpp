class Solution {
public:
    int dp[101][101];
    int solve(int m, int n){
        if(n == 0 && m == 0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int top = solve(m-1, n);
        int left = solve(m, n-1);
        return dp[m][n] = top+left;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(m-1, n-1);
    }
};
// On
// up left