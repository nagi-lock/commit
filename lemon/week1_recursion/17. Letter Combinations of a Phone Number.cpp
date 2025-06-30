class Solution {
public:
    vector<string> ans;
    void solve(int ind, string digits, unordered_map<char, string> mp, string temp){
        if(ind>=digits.size()){
            ans.push_back(temp);
            return;
        }

        char ch = digits[ind];
        string s = mp[ch];

        for(int i = 0; i< s.size(); i++){
            temp.push_back(mp[ch][i]);
            solve(ind+1, digits, mp, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
        };

        solve(0, digits, mp, "");


        return ans;

    }
};
// tc - O(4^n)
// sc - 4.O(4^n)