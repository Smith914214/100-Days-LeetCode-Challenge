class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 1D array initialized to 1 for the first row
        vector<int> dp(n, 1);
        
        // Loop through the rest of the rows
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // dp[j] currently holds the value from the row above: dp[i-1][j]
                // dp[j-1] holds the updated value from the left cell: dp[i][j-1]
                dp[j] += dp[j - 1];
            }
        }
        
        // The last element contains the total paths to the bottom-right corner
        return dp[n - 1];
    }
};