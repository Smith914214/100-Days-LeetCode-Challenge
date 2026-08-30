class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> visited(nums.size(), false);
        
        // 1. Sort to bring duplicates together
        std::sort(nums.begin(), nums.end());
        
        // 2. Start backtracking
        backtrack(nums, visited, current, result);
        
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, std::vector<bool>& visited, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: current permutation is complete
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            // Skip if already used in the current path
            if (visited[i]) continue;
            
            // Skip duplicates to prevent duplicate permutations
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            
            // Make choice
            visited[i] = true;
            current.push_back(nums[i]);
            
            // Recurse
            backtrack(nums, visited, current, result);
            
            // Undo choice (backtrack)
            current.pop_back();
            visited[i] = false;
        }
    }
};