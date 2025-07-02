class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pre= 1;
        int suf= 1;

        for(int i = 0; i< nums.size(); i++){
            pre = pre*nums[i];
            suf = suf*nums[nums.size()-i-1];

            

            ans = max({pre, suf, ans});
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
        }
        return ans;
    }
};