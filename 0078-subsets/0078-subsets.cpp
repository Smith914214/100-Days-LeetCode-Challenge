class Solution {
private:
    void backtrack(int index, std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if we have considered all elements, add the current subset to results
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        // Choice 1: Exclude nums[index] and move to the next element
        backtrack(index + 1, nums, current, result);

        // Choice 2: Include nums[index]
        current.push_back(nums[index]);
        backtrack(index + 1, nums, current, result);
        
        // Backtrack: remove the element before returning up the call stack
        current.pop_back();
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};