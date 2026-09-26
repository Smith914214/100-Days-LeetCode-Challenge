#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int start, std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicate elements at the same recursion level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Include nums[i] in the current subset
            current.push_back(nums[i]);
            
            // Move to the next element
            backtrack(i + 1, nums, current, result);
            
            // Backtrack: remove nums[i] before the next iteration
            current.pop_back();
        }
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Sort the array to easily identify duplicates
        std::sort(nums.begin(), nums.end());
        
        backtrack(0, nums, current, result);
        return result;
    }
};