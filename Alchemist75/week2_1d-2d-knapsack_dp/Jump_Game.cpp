class Solution {
public:
    /*
    - dp top down  - recursion +memoization
    - dp bottom up
    */
    int t[10001];
    int solve(vector<int>& nums,int idx,int n){
        //base case.
        //when does it exit
        if(idx==n-1){
            return true;//succeeded
        }
        if(t[idx]!=-1){
            return t[idx];
        }
     
        
        //number of possible ways from i=1 to that index, use for loop
        for(int i = 1;i<=nums[idx];i++){
            if(solve(nums,idx+i,n)==true){
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0,n);
    }
};

// //Bottom Up : O(n^2)
// class Solution {
// public:
    
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<int> t(n, false);
//         //t[i] = True means, you can reach index i
        
//         t[0] = true; //Already at starting index
        
//         for(int i = 1; i<n; i++) {
//             for(int j = i-1; j>=0; j--) {
//                 if(j + nums[j] >= i && t[j]) { //here t[j] == true means you should be able to reach j also, 
//                                                //then only you can plan to jump(j+nums[i])  from this jth index
//                     t[i] = true;
//                     break;
//                 }
//             }
//         }
        
        
//         return t[n-1];

//     }
// };

//optimal - O(n)
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int maxReachable = 0;
//         int n            = nums.size();
        
//         for(int i = 0; i<n; i++) {
//             if(i > maxReachable) {
//                 return false;
//             }
//             maxReachable = max(maxReachable, nums[i]+i);
//         }
        
//         return true;
//     }
// };