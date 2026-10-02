class Solution {
public:
    int numTrees(int n) {
        // dp[i] stores the number of unique BSTs formed by i nodes
        vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // An empty tree is 1 valid structure
        dp[1] = 1; // A tree with 1 node is 1 valid structure
        
        // Fill the DP table sequentially
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                // j represents the root node chosen for a tree of size i
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};