class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store the value and its corresponding index
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If the complement exists in the map, return the indices
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, store the current number and its index
            numMap[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found (though the problem guarantees one)
        return {};
    }
};