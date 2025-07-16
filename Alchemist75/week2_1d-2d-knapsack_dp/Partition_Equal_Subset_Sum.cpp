class Solution {
public:
    /*
    x+x = s
    2x=s
    x=s/2
    so if x is not s/2, means not possible.
    but we have cases like 1,2,5.here s=8 and 8 is divisible by 2
    but, cannot divide into 2 equal subset sums.
    so just because x%2===0, does not mean we can get 2 equal subset sums.
    we need to find subset such that sum==x(s/2)[CLASSICAL SUBSET SUM]
    for every index, 2 options take or not_take
    
    we do recursion first.
    then do rec+memo(top down dp)
    */
    int t[201][20001];//index,sum max value coz 200*100
    bool solve(vector<int>& nums,int i,int x){
        if(i>=nums.size()){
            return false;
        }
        if(x==0){
            return true;
        }
        if(t[i][x]!=-1){
            return t[i][x];
        }
        bool take = false;
        if(nums[i]<=x){
            take = solve(nums,i+1,x-nums[i]);
        }
        bool not_take = solve(nums,i+1,x);
        return t[i][x] = take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        int s = accumulate(begin(nums),end(nums),0);
        memset(t,-1,sizeof(t));
        if(s%2!=0){
            return false;
        }
        int x = s/2;

        return solve(nums,0,x);
    }
};//o(n2^n) with recursion, o(n*x) with rec+memo(top down dp)