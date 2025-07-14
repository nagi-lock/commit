class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Create a 2D array (dp) with dimensions m+1 and n+1
        // Initialize all elements to zero
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        // Iterate over each string in the given vector 'strs'
        for (auto& str : strs) {
            // Count the number of zeroes and ones in the current string
            pair<int, int> zeroOneCount = countZeroesAndOnes(str);
            int zeroes = zeroOneCount.first;
            int ones = zeroOneCount.second;

            // Iterate over the matrix in reverse, to avoid over-counting
            // when using previously computed sub-solutions
            for (int i = m; i >= zeroes; --i) {
                for (int j = n; j >= ones; --j) {
                    // Update the dp matrix by taking the maximum between:
                    // 1. Current cell value (previous computed max)
                    // 2. Value computed by including the current string
                    // Add 1 to the subproblem solution because
                    // we are including one more string
                    dp[i][j] = max(dp[i][j], dp[i - zeroes][j - ones] + 1);
                }
            }
        }
        // Return the maximum number of strings that can be formed
        // with given 'm' zeroes and 'n' ones
        return dp[m][n];
    }

private:
    // Helper function to count the number of zeroes and ones in a string
    pair<int, int> countZeroesAndOnes(string& str) {
        int countZeroes = count_if(str.begin(), str.end(), [](char c) { return c == '0'; });
        // First of the pair is number of zeroes, second is the number of ones
        // Since the total length minus zeroes gives the number of ones
        return {countZeroes, static_cast<int>(str.size()) - countZeroes};
    }
};