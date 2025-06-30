class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        dfsHelper(0,target,current,candidates,ans);
        //current holds current combo
        return ans;
    }

    void dfsHelper(int i,int target,vector<int>& current,vector<int>& candidates, vector<vector<int>>&  ans){
        if(target==0){
            ans.push_back(current);
            return;
        }
        //edge cases
        if(i>=(candidates.size()) || target<0){
            return;
        }

        //without curr candidate
        dfsHelper(i+1,target,current,candidates,ans);

        //with current candidate
        current.push_back(candidates[i]);
        dfsHelper(i,target-candidates[i],current,candidates,ans);

        //backtracking
        current.pop_back();
    }//O(2^target/min(candidates)),as if min cand is 1 we get 2^target.
    //Same SC.
};