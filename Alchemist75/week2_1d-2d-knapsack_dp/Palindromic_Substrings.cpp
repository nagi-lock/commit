class Solution {
public:
    //dp on strings
    //palindromic variant
    //rec,rec+memoization,bottom-up, bottom-up blueprint
    int t[1001][1001];
    bool solve(string& s,int i,int j){
        if(i>j){
            return true;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(s[i]==s[j]){
            //continue
            return t[i][j] = solve(s,i+1,j-1);
        }
        return t[i][j] = false;
    }
    int countSubstrings(string s) {
        memset(t,-1,sizeof(t));
        int n = s.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(solve(s,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};//o(n^2) coz each substring calc only once and then stored in t[i][j]


// class Solution{
//     //bottom up blueprint
//     //t[i][j] = True, s[i:j] is a palindrome,False if s[i:j] not palindrome
//     //1 length
//     //2 length
//     //>2 length 
// public:
//     int countSubstrings(string s){
//         int n = s.length();
//         vector<vector<bool>> t(n,vector<bool>(n,false));
//         //state - t[i][j]=true:s[i:j] is substring where i and j are inclusive indices.

//         int count = 0;
//         for(int L = 1;L<=n;L++){

//             for(int i  =0;i+L-1<n;i++){

//                 int j  = i+L-1;

//                 if(i==j){//1 length string
//                     t[i][j] = true;
//                 }else if(i+1==j){//2 length string
//                     t[i][j] = (s[i]==s[j]);
//                 }else{
//                     //>2 length string
//                     t[i][j] = (s[i]==s[j] && t[i+1][j-1]);
//                 }

//                 if(t[i][j]==true){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };