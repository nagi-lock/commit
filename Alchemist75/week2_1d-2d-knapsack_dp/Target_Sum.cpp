class Solution {
public:
    //knapsack dp
    //recursion
    int solve(int i,vector<int>& nums,int currSum,int target){
        //base case
        if(i==nums.size()){
            if(currSum==target){
                return 1;
            }else{
                return 0;
            }
        }

        int plus = solve(i+1,nums,currSum+nums[i],target);
        int minus = solve(i+1,nums,currSum-nums[i],target);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,nums,0,target);
    }
};





class Solution {
public:
    //knapsack dp
    //one way to memoize-top down memoization
    int solve(int i,vector<int>& nums,int currSum,int target,unordered_map<string,int>& mp){
        //base case
        if(i==nums.size()){
            if(currSum==target){
                return 1;
            }else{
                return 0;
            }
        }

        string key = to_string(i)+"_"+to_string(currSum);
        if(mp.count(key)){
            return mp[key];
        }

        int plus = solve(i+1,nums,currSum+nums[i],target,mp);
        int minus = solve(i+1,nums,currSum-nums[i],target,mp);
        return mp[key] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> mp;
        return solve(0,nums,0,target,mp);
    }
};




class Solution {
public:
    //knapsack dp
    //2d vector top down memoization
    int s;
    int solve(
        int i,
        vector<int>& nums,
        int currSum,
        int target,
        vector<vector<int>>& t
    ){
        //base case
        if(i==nums.size()){
            if(currSum==target){
                return 1;
            }else{
                return 0;
            }
        }

        if(t[i][currSum+s]!=-1){
            return t[i][currSum+s];//ensure curr sum not neg, shifting on num line
        }

        int plus = solve(i+1,nums,currSum+nums[i],target,t);
        int minus = solve(i+1,nums,currSum-nums[i],target,t);
        return t[i][currSum+s] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        s = accumulate(begin(nums),end(nums),0);
        vector<vector<int>> t(n+1,vector<int>(2*s+1,-1));
        return solve(0,nums,0,target,t);
    }
};