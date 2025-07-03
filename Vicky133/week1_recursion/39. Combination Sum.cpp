class Solution {
public:
    void comb(int i,vector<int>&temp,vector<vector<int>>&ans, int target,vector<int>&candidates){
        if (i == candidates.size()) return; 
        if (target < 0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        comb(i,temp,ans,target-candidates[i],candidates);

        temp.pop_back();
        comb(i+1,temp,ans,target,candidates);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        comb(0,temp,ans,target,candidates);
        return ans;
    }
};