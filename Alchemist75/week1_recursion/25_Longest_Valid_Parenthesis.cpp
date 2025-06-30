class Solution {
public:
    //greedy, stack based
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxLen = 0;
        st.push(-1);// Prevents empty stack pop (underflow)
        for(int i  =0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    maxLen = max(maxLen,i-st.top());
                }
            }
        }
        return maxLen;
    }
};//O(N) and O(N)



// class Solution {
// public:
//     //forward-backward
//     int longestValidParentheses(string str) {
//         int open = 0, close = 0, maxLen = 0;
//         for (int index = 0; index < str.length(); index++) {
//             //go left to right to find first unmatched )
//             if (str[index] == '(') {
//                 open++;
//             } else {
//                 close++;
//             }
//             if (open == close) {
//                 maxLen = max(maxLen, 2 * close);
//             } else if (close > open) {
//                 open = close = 0;
//             }
//         }
//         open = close = 0;
//         for (int index = str.length() - 1; index >= 0; index--) {
//             //go right to left to find first unmatched (
//             if (str[index] == '(') {
//                 open++;
//             } else {
//                 close++;
//             }
//             if (open == close) {
//                 maxLen = max(maxLen, 2 * open);
//             } else if (open > close) {
//                 open = close = 0;
//             }
//         }
//         return maxLen;
//     }
// };//O(N) and O(1)