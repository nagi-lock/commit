class Solution {
public:
        vector<string> mapping = {
        "",     "",     "abc", "def",  
        "ghi",  "jkl",  "mno",         
        "pqrs", "tuv",  "wxyz"         
    };
    void solve(int i, string digits,string temp, vector<string>&res){
        if(i>=digits.size()){
            res.push_back(temp);
            return;
        }
        int  ch= digits[i] - '0';
        string str = mapping[ch];
        for(auto &j:str){
            temp.push_back(j);
            solve(i+1,digits,temp,res);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.empty())return res;
        string temp;
        solve(0,digits,temp,res);
        return res;
    }
};