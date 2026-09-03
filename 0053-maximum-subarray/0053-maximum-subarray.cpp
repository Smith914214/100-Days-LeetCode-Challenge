#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // Initialize with the first element
        int max_so_far = nums[0];
        int current_max = nums[0];
        
        // Loop through the rest of the array
        for (size_t i = 1; i < nums.size(); ++i) {
            // Decide whether to add the current number to the existing subarray
            // or start a completely new subarray from the current number
            current_max = std::max(nums[i], current_max + nums[i]);
            
            // Track the maximum sum found so far
            max_so_far = std::max(max_so_far, current_max);
        }
        
        return max_so_far;
    }
};