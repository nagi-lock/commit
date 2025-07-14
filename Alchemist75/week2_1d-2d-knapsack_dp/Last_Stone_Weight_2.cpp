class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalWeight = accumulate(stones.begin(),stones.end(),0);
        int targetWeight = totalWeight >> 1;
        //dp array
        vector<int> dp(targetWeight + 1,0);

        for(int stone:stones){
            //go backwards to avoid using stone twice
            for(int j = targetWeight;j>=stone;j--){
                //update to higher of two vals - dp[j] or sum of stone and dp[j-stone] if we include stone
                dp[j] = max(dp[j], dp[j-stone]+stone);
            }
        }

        return totalWeight - dp[targetWeight]*2;


    }//O(mn)
};