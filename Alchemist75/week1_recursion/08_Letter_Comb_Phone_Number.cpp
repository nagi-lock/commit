/**
    - small constraints,
    - complete search using backtracking applicable
    - mapping between strings and integer phone number
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()){
            return {};
        }
        vector<string> d={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string curr="";
        helper(digits,d,curr,ans,0);
        return ans;
    }
    void helper(string digits,vector<string>& d, string curr,vector<string> &ans,int i){
        if(i==digits.size()){
            ans.push_back(curr);
            return;
        }

        int x = digits[i]-'0';//int rep of char
        for(char ch:d[x]){
            curr+=ch;
            helper(digits,d,curr,ans,i+1);
            curr.pop_back();
        }
    }
};//O(N*4^N) as worst case maps to 4 letterrs