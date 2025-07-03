class Solution {
public:
    void f(vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums,vector<int>&hash){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!hash[i]){
                temp.push_back(nums[i]);
                hash[i]=1;
                f(temp,ans,nums,hash);
                hash[i]=0;
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>hash(nums.size(),0);
        f(temp,ans,nums,hash);
        return ans;
    }
};