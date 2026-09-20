class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // dp array storing the number of paths for each column
        std::vector<int> dp(n, 0);
        
        // Starting point base case
        if (obstacleGrid[0][0] == 0) {
            dp[0] = 1;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If there's an obstacle, no paths can pass through this cell
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } 
                // Otherwise, add paths coming from the left cell
                else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n - 1];
    }
};