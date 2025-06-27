class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> curr;

        helper(ans,s,curr,0);//pass index as curr index parameter to use in for loop 
        return ans;
    }
    void helper(vector<string>& ans,string s,vector<string>& curr,int index){
        //base case
        if(curr.size()==4 && index>=s.size()){
            //success
            ans.push_back(curr[0]+"."+curr[1]+"."+curr[2]+"."+curr[3]);
            return;
        }

        if (index >= s.size() || curr.size() >= 4) {
            //failed
            return;
        }

        int segmentValue = 0;
        int length = static_cast<int>(s.size());//s.size() gives size_t so typecast it
        for(int i = index; i<min(length,index+3); i++){
            segmentValue = segmentValue*10+s[i]-'0';
            //if more than 255 or not single digit and starts with 0
            if(segmentValue>255 || ( i > index && s[index]=='0')){
                break;
            }
            curr.push_back(s.substr(index,i-index+1));
            helper(ans,s,curr,i+1);
            curr.pop_back();
        }
    }
};//O(1) coz length of string between 4 and 12 max and O(1) as problem constraints output size.