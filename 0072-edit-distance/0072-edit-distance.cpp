class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] stores the edit distance for word1[0...i-1] and word2[0...j-1]
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        // Base case: converting word1[0...i-1] to an empty string (requires i deletions)
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        
        // Base case: converting an empty string to word2[0...j-1] (requires j insertions)
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match, no operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Find minimum of: Deletion, Insertion, Replacement
                    dp[i][j] = 1 + std::min({
                        dp[i - 1][j],     // Delete from word1
                        dp[i][j - 1],     // Insert into word1
                        dp[i - 1][j - 1]  // Replace in word1
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};