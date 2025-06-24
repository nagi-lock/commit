class Solution {
public:
    vector<string> ans;

    void solve(int open , int closed, string op){
        if(closed == 0){
            ans.push_back(op);
            return;
        }
        if(open>0){
            string op1 = op;
            op1.push_back('(');
            solve(open-1, closed, op1);
        } 
        if(closed>open){
            string op2 = op;
            op2.push_back(')');
            solve(open, closed-1, op2);
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = n;
        int closed = n;
        string op = "";
        solve(open, closed, op);
        return ans;
    }
};