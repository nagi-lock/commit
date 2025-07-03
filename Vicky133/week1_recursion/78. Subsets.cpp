class Solution {
public:
    void subset(int i,vector<int>temp ,vector<vector<int>>&res,vector<int>&nums){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subset(i+1,temp,res,nums);
        temp.pop_back();
        subset(i+1,temp,res,nums);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
             subset(0,temp,res,nums);
        return res;
    }
};