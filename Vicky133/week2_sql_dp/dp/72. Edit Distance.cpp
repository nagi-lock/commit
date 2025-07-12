class Solution {
public:
//left to right
    // int solve(int i,int j,string& w1,string& w2, vector<vector<int>>&dp){
    //     if(i==w1.size())
    //         return w2.size()-j; //insert
    //     else if(j==w2.size())
    //         return w1.size()-i; //deletion
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(w1[i]==w2[j])
    //         return dp[i][j]=solve(i+1,j+1,w1,w2,dp);
    //     else{
    //         int insert = 1+solve(i,j+1,w1,w2,dp);
    //         int deletion = 1+solve(i+1,j,w1,w2,dp);
    //         int replace = 1+solve(i+1,j+1,w1,w2,dp);
    //         return dp[i][j]= min({insert, deletion,replace});
    //     }
    //     return -1;
    // }
//right to left
    int solve(string& s1, string& s2, int m, int n, vector<vector<int>>&dp){
        if(m==0||n==0)
            return m+n;

        if(dp[m][n]!=-1)
            return dp[m][n];

        if(s1[m-1]==s2[n-1]){
            return dp[m][n] =  solve(s1,s2,m-1,n-1,dp);
        }else{
            int insertC = 1 + solve(s1,s2,m,n-1,dp);
            int deleteC = 1 +solve(s1,s2,m-1,n,dp);
            int replaceC = 1 + solve(s1,s2,m-1,n-1,dp);
        return dp[m][n] = min({insertC,deleteC,replaceC});
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        // return solve(0,0,word1,word2,dp);
// //top-down
        // int m=word1.size(),n=word2.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solve(word1,word2,m,n,dp);

//bottom-up
        int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0)
                    dp[i][j]=i+j;
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int insertC = 1 + dp[i][j-1];
                    int deleteC = 1 + dp[i-1][j];
                    int replaceC = 1 + dp[i-1][j-1];
                 dp[i][j] = min({insertC,deleteC,replaceC});
                }
            }
        }
        return dp[m][n];
    }
};