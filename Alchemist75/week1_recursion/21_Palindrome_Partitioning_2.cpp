class Solution {
public:
    /*
    aab-1,aba-0,abcb-1
    we have options->recursion.
    top-down dp(rec + memo)
    */
    int t[2001][2001];
    bool isPal(int i,int j,string& s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int j,string& s){
        if(t[i][j]!=-1){
            return t[i][j];
        }

        if(i>=j){
            return 0;//0 cuts
        }
        if(isPal(i,j,s)){
            return t[i][j] = 0;//no need for more cuts
        }

        int result = INT_MAX;
        for(int k = i;k<=j-1;k++){
            int temp = 1+ solve(i,k,s)+solve(k+1,j,s);
            result = min(result,temp);
        }
        return result;
    }
    int minCut(string s) {
       int n = s.size();
       
        memset(t,-1,sizeof(t));

        return solve(0,n-1,s);
    }
};//O(n^2 due to matrix *(n))=O(n^3) and O(n^2) so wont work



// class Solution {
// public:
// /*
//     bottom up dp
//     (use blueprint for bottom up dp on strings - palindrome )
//     1. use blueprint to make 2d array where t[i][j] is true means s[i..j] is palm
//     else s[i,...j] false
//     2.keep i at every char, then cut there.This way bulld dp array by
//     trying cuts at diff indices. dp[i] = s[0..i] os jow many cuts(min) required.
//     s[0...n-1] returns dp[n-1]
// */
//     int minCut(string s) {
//         int n = s.size();
//         //blueprint
//             vector<vector<bool>> t(n,vector<bool>(n,false));

//             //length=1 substring
//             for(int i = 0;i<n;i++){
//                 t[i][i] = true;//s[i..i] always pal
//             }

//             //length>=2 substring
//             for(int L = 2;L<=n;L++){
//                 for(int i = 0;i<n-L+1;i++){
//                     int j = i+L-1;
//                     if(L==2){//string of size 2 only "ac","ab"
//                         t[i][j] = (s[i]==s[j]);
//                     }else{
//                         t[i][j] = (s[i]==s[j] && t[i+1][j-1]);
//                     }
//                 }
//             }

//         //make dp array
//         vector<int> dp(n);
//         //dp[i] is min cuts req to cut string s[0...i] into pal
//         for(int i = 0;i<n;i++){
//             if(t[0][i]==true){//s[0..i] is pal
//                 dp[i] = 0;//no cuts needed
//             }else{
//                 dp[i] = INT_MAX;
//                 for(int k = 0;k<i;k++){
//                     if(t[k+1][i]==true && dp[k]<dp[i]){
//                         //right side of cut and left side of cut
//                         dp[i] = 1+dp[k];
//                     }
//                 }
//             }
//         }
//         return dp[n-1];//s[0...n-1] entire string ke loye min cuts req
//     }
// };//O(n^2)