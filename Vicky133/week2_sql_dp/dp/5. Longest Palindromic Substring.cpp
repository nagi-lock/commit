class Solution {
public:
    // bool isPalindrome(string& s,int left, int right){
    //     while(left<=right){
    //         if(s[left++]!=s[right--])return false;
    //     }
    //     return true;
    // }
    bool solve(int i, int j, string& s, vector<vector<int>>&dp){
        if(i>=j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j] = solve(i+1,j-1,s,dp);
        }else
            return 0;
    }
    string longestPalindrome(string s) {
        int max_len=0;
        string max_str="";
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(j-i+1>max_len && solve(i,j,s,dp)){
                    max_len=j-i+1;
                    max_str=s.substr(i,j-i+1);
                }
            }
        }
        return max_str;
 
        // if(s.size()<=1)return s;
        // int max_len = 0;
        // string max_str = "";
        // for(int i=0;i<s.size();i++){
        //     for(int j=i;j<s.size();j++){
        //         if(j-i+1>max_len && isPalindrome(s,i,j)){
        //             max_len=j-i+1;
        //             max_str=s.substr(i,j-i+1);
        //         }
        //     }
        // }
        // return max_str;
    }
};