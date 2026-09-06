class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If the current index is unreachable, return false
            if (i > maxReach) {
                return false;
            }
            
            // Update the furthest index we can reach
            maxReach = std::max(maxReach, i + nums[i]);
            
            // Optimization: If we can already reach the last index, return true
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};