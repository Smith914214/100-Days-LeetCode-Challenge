class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        
        // Initialize dp array with the bottom row of the triangle
        std::vector<int> dp = triangle[n - 1];
        
        // Iterate upwards from the second to last row down to the top row
        for (int row = n - 2; row >= 0; --row) {
            for (int i = 0; i <= row; ++i) {
                // Find the minimum path sum for the current position
                dp[i] = triangle[row][i] + std::min(dp[i], dp[i + 1]);
            }
        }
        
        // The top element now contains the minimum path sum
        return dp[0];
    }
};