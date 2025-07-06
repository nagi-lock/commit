class Solution {
public:
    //dp on string
    //palindrome variant
    //recursion
    //rec+memoization(top-down)
    int t[1001][1001];
    bool solve(string& s,int i,int j){
       if(i>=j){
        return 1;
       }
       if(t[i][j]!=-1){
        return t[i][j];
       }
       if(s[i]==s[j]){
        return t[i][j] = solve(s,i+1,j-1);
       }
       return t[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        memset(t,-1,sizeof(t));
        int maxLen = 0;
        int sp = -1;//start pt
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(solve(s,i,j)){
                    //is pal
                    if(j-i+1>maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};


