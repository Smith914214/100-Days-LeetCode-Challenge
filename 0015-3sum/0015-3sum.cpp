class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // 1. Sort the array to easily manage duplicates and use two pointers
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // If the current smallest number is greater than 0, a sum of 0 is impossible
            if (nums[i] > 0) break;
            
            // Skip duplicate values for the first element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 2. Use two pointers for the remaining target sum (-nums[i])
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move pointers past duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Sum is too small, increase the left pointer
                } 
                else {
                    right--; // Sum is too large, decrease the right pointer
                }
            }
        }
        
        return result;
    }
};