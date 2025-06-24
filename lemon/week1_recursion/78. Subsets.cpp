class Solution {
public:
    vector<vector<int>> ans;

    void solve(int ind, vector<int> nums, vector<int> v){

        if(ind == nums.size()){
            ans.push_back(v);
            return;
        }
        
        solve(ind+1, nums, v);
        v.push_back(nums[ind]);
        solve(ind+1, nums, v);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        solve(0, nums, v);
        return ans;
    }
};