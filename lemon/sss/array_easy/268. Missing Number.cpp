class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int curr_sum = accumulate(nums.begin(), nums.end(), 0); //4
        int n = nums.size(); //3
        int total_sum = (n*(n+1))/2; //6
        return total_sum - curr_sum;
        // cout<<total_sum;
        // return total_sum;
    }
};
// On
// sum formula