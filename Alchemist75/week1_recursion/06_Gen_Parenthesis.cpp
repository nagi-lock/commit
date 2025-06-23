class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("",0,0,ans,n);
        return ans;
    }
    void helper(string current,int open,int close,vector<string> &ans,int max){//pass by ref
        if(current.size()==2*max){
            ans.push_back(current);
            return;
        }

        if(open<max){
            helper(current+"(",open+1,close,ans,max);
        }
        

        if(close<open){
            helper(current+")",open,close+1,ans,max);
        }
    }
};