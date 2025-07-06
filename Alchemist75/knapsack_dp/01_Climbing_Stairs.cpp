class Solution {
public:
    /*
    
    recursion - O(2^n)
    dp top-down(rec + memoization) - O(n)
    dp bottom-up - O(n) as array[i] is number of ways to climb i stairs.find array[n]

    */
    // int t[46];
    // int solve(int n){
    //     if(n == 0 || n == 1 || n == 2)
    //         return n;
        
    //     if(t[n] != -1)
    //         return t[n];
        
    //     int a = solve(n-1);
    //     int b = solve(n-2);
        
    //     return t[n] = a+b;
        
    // }
    // int climbStairs(int n) {
    //     memset(t, -1, sizeof(t));
    //     return solve(n);
    // }


    int climbStairs(int n) {//like fibonacci
        if(n == 1 || n == 2)
            return n;
        vector<int> t(n+1);    
        //t[i] = total ways to climb i stairs
        t[0] = 0;
        t[1] = 1;
        t[2] = 2;    
        for(int i = 3; i<=n; i++) {
            t[i] = t[i-1] + t[i-2];
        }    
        return t[n];
    }
};