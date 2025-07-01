class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1) return 1;

        int l =0, r = 1;
        for(int i = 1; i< nums.size(); i++){
            if(nums[l]!=nums[i]){
                // means diff
                l++;
                nums[l] = nums[i];
            }
        }
        return l+1;
    }
}; 
//shift different to next else continue 
//On