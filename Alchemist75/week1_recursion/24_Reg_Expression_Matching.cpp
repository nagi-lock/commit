class Solution {
public:
/*
ab, .a -false
aa, .a -true
ab, .*b -true (2 option - don't take it,take it) so recursion
ab,a*ab  - don't take-true,
when pattern ends string must end as given matching must cover entire input string.
* will repeat the char before it
1. .* or <ch>* 
2. o times liya - pattern.substr(2)
3. first check that 0th index char is (.) or (ch)==input[0]
recursion,top down dp(memoi)
*/
    int t[21][21];
    bool solve(int i,int j,string s,string p){
		    //base case
        if(j== p.length()){
            return i==s.length();//j out of bound,i shd also be
        }
        if(t[i][j]!=-1){//check dp state
            return t[i][j];//0 then false,1 then true
        }
        bool first_char_matched = false;
        if(i<s.length() &&(p[j]==s[i]||p[j]=='.')){
            first_char_matched = true;
        }

        if(j+1 < p.length() && p[j+1]=='*'){
            bool not_take = solve(i,j+2,s,p);//no need for substr
            bool take = first_char_matched && solve(i+1,j,s,p);
            return t[i][j]=not_take || take;
        }
        //char 1 is not * eg. ab and ac.

        return t[i][j] = first_char_matched && solve(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s,p);
    }
};//O(2^N)