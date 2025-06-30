class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        int start = 1;
        helper(start,n,k,comb,ans);
        return ans;
    }

    void helper(int s,int n,int k,vector<int>& comb,vector<vector<int>>& ans){
        if(comb.size()==k){
            ans.push_back(comb);
            return;
        }

        //try all values from s to n rather than just doing s and s+1.
        //comb can have values from 1 upto n.
        for(int i = s;i<=n;i++){
            comb.push_back(i);
            helper(i+1,n,k,comb,ans);
            comb.pop_back();
        }
    }
};//O(nck) -  N * (N-1) * (N-2) * ... * (N-K).
// This is because at every level (think of recursion tree), we're adding (N-i) nodes to the (i+1) level (if i is the current level).