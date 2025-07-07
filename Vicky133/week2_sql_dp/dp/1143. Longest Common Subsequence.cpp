class Solution {
public:
    int solve(int id1,string str1,int id2,string str2,vector<vector<int>>&dp){
        if(id1<0 || id2<0)return 0;
        if(dp[id1][id2]!=-1)return dp[id1][id2];
        if(str1[id1]==str2[id2])
            return dp[id1][id2]= 1+ solve(id1-1,str1,id2-1,str2,dp);
        return dp[id1][id2]= max(solve(id1-1,str1,id2,str2,dp),solve(id1,str1,id2-1,str2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // int id1=text1.size()-1, id2=text2.size()-1;
        // vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        // return solve(id1,text1,id2,text2,dp);
        
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
//tc: recursive: O(2^(m+n)), dp: O(m*n)
//sc: recursive: O(m+n), dp: O(m*n)