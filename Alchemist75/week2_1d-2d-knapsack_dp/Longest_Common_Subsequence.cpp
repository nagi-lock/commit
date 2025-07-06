//top down
class Solution {
public:
    int t[1001][1001];//2 states so 2d array
    int solve(string& text1,string& text2,int i,int j){
        //base case
        if(i>=text1.length() || j>=text2.length()){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(text1[i]==text2[j]){
            return t[i][j] = 1+ solve(text1,text2,i+1,j+1);//consider 1 and go ahead
        }

        return t[i][j] = max({solve(text1,text2,i+1,j),solve(text1,text2,i,j+1)});

    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        return solve(text1,text2,0,0);
    }
};//O2^m*2^n so O(2^m+n)


class Solution {
public:
//bottom up
//t[i][j] = lcs between s1 or length i and s2 of length j
//return t[m][n]
//so, t[m+1][n+1] is my 2d array size
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> t(m+1,vector<int>(n+1));
        //first row and col are 0
        for(int i = 0;i<n+1;i++){
            t[0][i] = 0;
        }
        for(int i = 0;i<m+1;i++){
            t[i][0] = 0;
        }

        for(int i = 1;i<m+1;i++){
            for(int j = 1;j<n+1;j++){
                if(text1[i-1]==text2[j-1])
                t[i][j] = 1+ t[i-1][j-1];//get ans from prev not i+1,j+1 as we do not know that
                else
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[m][n];
    }
};