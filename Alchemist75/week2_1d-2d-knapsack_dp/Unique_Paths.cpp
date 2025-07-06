class Solution {
public:
    //recursion
    //rec + memo(top -down dp)
    int t[101][101];//need 2d memoization table
    int solve(int m,int n){
        //m rows and n cols
        if(m<=1 || n<=1){
            //only 1 way poss
            return 1;
        }
        if(t[m][n]!=-1){
            //it has memoized value
            return t[m][n];
        }
        
        int a = solve(m-1,n);
        int b = solve(m,n-1);
        return t[m][n]=(a+b);
    }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(m,n);
    }
};//O(m*n) for memoization table and O(m+n) for rec call stack


class Solution {
public:
    //bottom up
    //take t[m+1][n+1]
    //define state,t[i][j] is ways to reach i,j from 0,0.
    //return t[m-1][n-1];
    int t[101][101];
    int uniquePaths(int m, int n) {
        t[0][0] = 1;
        //fill 0th row
        for(int col=1;col<n;col++){
            t[0][col] = 1;
        }
        //fill 0th col
        for(int row=1;row<m;row++){
            t[row][0] = 1;
        }
        for(int i = 1;i<m;i++){
            for(int j  =1;j<n;j++){
                t[i][j] = t[i-1][j]+t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};