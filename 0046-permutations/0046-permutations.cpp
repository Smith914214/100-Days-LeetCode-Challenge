class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
        // Base case: a complete permutation is formed
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        // Explore all choices for the current position
        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);       // Make choice
            backtrack(nums, start + 1, result);    // Recurse
            std::swap(nums[start], nums[i]);       // Undo choice (backtrack)
        }
    }
};