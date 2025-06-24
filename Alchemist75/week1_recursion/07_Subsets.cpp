//Backtracking approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> subsets;
        helper(nums,0,subset,subsets);
        return subsets;
    }

    void helper(vector<int>& nums,int i, vector<int>& subset,vector<vector<int>>& subsets){
        if(i==nums.size()){
            subsets.push_back(subset);
            return;
        }
        //with curr element
        subset.push_back(nums[i]);
        helper(nums,i+1,subset,subsets);

        //without curr element
        subset.pop_back();
        helper(nums,i+1,subset,subsets);
    }

    
};//TC O(N*2^N) and SC is O(2^N) if we consider output array else O(N)


//Bitmasking approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> res;
      int n = nums.size();

      for(int i = 0;i<(1<<n);i++){
        //2^N-1  subsets for N size 
        vector<int> subset;
        for(int j = 0;j<n;j++){
            if((i & (1<<j))!=0){//use << to shift bit to be checked each time in j
                //check if jth bit is set for number i
                //add that element to subset.
                subset.push_back(nums[j]);
            }
        }
        res.push_back(subset);
      }
      return res;
    }//O(N*2^N) and O(N)
};