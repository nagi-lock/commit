class Solution {
public:
    int solve(int i, int sm,int target,vector<int>& stones,vector<vector<int>>&dp){
        if(i==stones.size()){
            if(sm<=target)
                return sm;
            else
                return 0;
        }
        if(dp[i][sm]!=-1)return dp[i][sm];
        int left = solve(i+1,sm+stones[i],target,stones,dp);
        int right = solve(i+1,sm, target, stones, dp);
        return dp[i][sm] = max(left, right);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int target = accumulate(stones.begin(),stones.end(),0);
        int n = stones.size();
        // vector<vector<int>>dp(n,vector<int>(target,-1));
        // int s2= solve(0,0,target/2,stones,dp);
        // int s1 = target-s2;  
        // return abs(s1-s2);

// bottom up
        vector<vector<int>>dp(n+1, vector<int>((target/2)+1,0));
        for(int wt=stones[0];wt<=target/2;wt++){
            if (stones[0] <= target / 2)
                dp[0][wt]=stones[0];
        }
        
        for(int i=1;i<n;i++){
            for(int wt=0;wt<=target/2;wt++){
                int pick = 0;
                if(stones[i]<=wt){
                    pick = stones[i]+dp[i-1][wt-stones[i]];
                }
                int notPick = dp[i-1][wt];
                dp[i][wt] = max(pick, notPick);
            }
        }
        int s2 = dp[n-1][target/2];
        int s1 = target -s2;
        return abs(s2-s1);
    }
};