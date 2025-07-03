class Solution {
public:
    void combination(int i,vector<int>&temp,vector<vector<int>>&res,vector<int>&range,int &k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        if(i==range.size())return;
        temp.push_back(range[i]);
        combination(i+1,temp,res,range,k);
        temp.pop_back();
        combination(i+1,temp,res,range,k);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>range;
        for(int i=1;i<=n;i++)range.push_back(i);
        vector<int>temp;
        vector<vector<int>>res;
        combination(0,temp,res,range,k);
        return res;
    }
};