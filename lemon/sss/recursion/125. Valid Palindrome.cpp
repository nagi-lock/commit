class Solution {
public:
    // int dp[]
    bool solve(string& s, int l, int r){
        if(l>r) return true;
        if(!isalnum(s[l])){
            return solve(s, l+1, r);
        } else if (!isalnum(s[r])){
            return solve(s, l, r-1);
        } else{
            if(tolower(s[l])!= tolower(s[r])){
                return false;
            } else{
                return solve(s, l+1, r-1);
            }
        
        }
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        return solve(s, l, r);
    }
};