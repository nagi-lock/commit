class Solution {
public:
    
   

    int jump(vector<int>& nums) {
        int curr = 0, far = 0, step =0;

        for(int i = 0; i< nums.size()-1; i++){
            far = max(far, nums[i]+i);

            if(i == curr){
                step++;
                curr = far;
            }
        }
        return step;
    }
};

//on
//far curr max