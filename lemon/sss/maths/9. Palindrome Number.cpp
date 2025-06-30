class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp = x;
        int dig = 0;
        while(x){
            int mod = x%10;
            if(dig>INT_MAX/10 || dig<INT_MIN/10) return 0;
            dig = dig*10+mod;
            x/=10;
        }
        return dig==temp;
    }
};