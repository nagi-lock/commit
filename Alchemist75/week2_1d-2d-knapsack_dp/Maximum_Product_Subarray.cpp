//1d dp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0],currMin = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            //save prev step's max and min
            int tmpMax = currMax;
            int tmpMin = currMin;

            currMax = max(nums[i],max(tmpMax*nums[i],tmpMin*nums[i]));//accounts for -ve num*-ve num becoming max
            currMin = min(nums[i],min(tmpMin*nums[i],tmpMax*nums[i]));
            res = max(res,currMax);
        }
        return res;
    }
};//On and O1