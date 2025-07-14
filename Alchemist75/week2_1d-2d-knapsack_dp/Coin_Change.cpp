class Solution {
public:
//bottom up dp
    int coinChange(vector<int>& coins, int amount) {
        // Create vector with size amount + 1 to store minimum coins required for each total amount.
        vector<int> minCoins(amount + 1, INT_MAX);
        // Base case: 0 coins are needed for amount 0.
        minCoins[0] = 0;

        for (int coin : coins) {
            // For each coin, compute min coins needed for all amounts from coin value up to the given amount.
            for (int currentAmount = coin; currentAmount <= amount; ++currentAmount) {
                // If it's possible to use coin to reach currentAmount, update minCoins for currentAmount.
                if (minCoins[currentAmount - coin] != INT_MAX) {
                    minCoins[currentAmount] = min(minCoins[currentAmount], minCoins[currentAmount - coin] + 1);
                }
            }
        }

        // If minCoins for the given amount is still INT_MAX, return -1 as it's not possible to form the amount with given coins.
        // Otherwise, return the minCoins for the given amount.
        return minCoins[amount] == INT_MAX ? -1 : minCoins[amount];
    }
};//O(S*n) and O(S)