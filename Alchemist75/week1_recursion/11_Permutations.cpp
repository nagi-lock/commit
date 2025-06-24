class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        //use map instead of freq array
        //unlike letters which go till 26, numbers can take any val.
        unordered_map<int,int> freq_count;
        for(int num:nums){
            freq_count[num]++;
        }
        helper(0,n,freq_count,curr,ans);
        return ans;
    }
    void helper(int i,int n,unordered_map<int,int> freq_count,vector<int>& curr,vector<vector<int>>& ans){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }

        for(auto[num,count]:freq_count){
            if(count>0){
                //decrease count as we visit child recursive layer
                //track count of element as same ele needs to be reused at diff layer.
                freq_count[num]--;

                //with curr element
                curr.push_back(num);
                helper(i,n,freq_count,curr,ans);
                
                //increase count as we go back to parent rec layer
                freq_count[num]++;
                curr.pop_back();//backtracking

            }
        }
    }
};//O(n!) as at each level we are making  n choices, then n-1 choices.