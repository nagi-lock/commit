class Solution {
public:
    int reverse(int x) {
        int dig = 0;
        while(x){
            int mod = x%10;
            if (dig > INT_MAX/10)             
                return 0;
            if (dig < INT_MIN/10)
                return 0;
            dig = dig*10+mod;
            x = x/10;
        }
      
    
        return dig;
    }
};