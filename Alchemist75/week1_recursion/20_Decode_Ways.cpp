class Solution {
public:
    /*
    practice with test case 226,06,12,276
    recursion tree since we have mult possibilities
    dp as repeating subproblems.
    top-down dp (memoization)
    */

    int t[101];//based on constraints

    int numDecodings(string s) {
        int n = s.size();
        memset(t,-1,sizeof(t));
        return solve(0,s,n);
    }

    int  solve(int i,string& s,int &n){
        if(t[i]!=-1){
            return t[i];
        }
        if(i==n){
            return t[i] = 1;//one valid split done,store and return
        }
        if(s[i]=='0'){
            //rec tree cannot go further
            return t[i] = 0;//store and return
        }
        
        int result = solve(i+1,s,n);//taken first char, solve from i+1th char

        if(i+1<n){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
                result += solve(i+2,s,n); //take first two chars, but under certain cond
            }
        }
        return t[i] = result;//store and return result
    }
};



// class Solution {
// public:
  
//     /*
//     bottom up dp
//     */
//     int numDecodings(string s) {
//         int n = s.size();
//         vector<int> t(n+1,0);
//         return solve(0,s,n,t);
//     }

//     int  solve(int i,string& s,int &n,vector<int>& t){
//         //t[i] is ways to decode string s from index i to n
//         t[n] = 1;
//         for(int i = n-1;i>=0;i--){
//             if(s[i]=='0'){
//                 t[i] = 0;
//             }else{
//                 t[i] = t[i+1];
//                 if(i+1<n){
//                     if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
//                        t[i]+=t[i+2];
//                     }
//                 }
//             }
//         }

//         return t[0];
//     }
// };