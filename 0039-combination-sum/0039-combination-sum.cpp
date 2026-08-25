class Solution {
public:
    void backtrack(int index, int target, std::vector<int>& candidates, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if target is reached, save the combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Base case: if target becomes negative or all elements are explored
        if (target < 0 || index >= candidates.size()) {
            return;
        }

        // Decision 1: Include the current element (unlimited times, so index remains same)
        current.push_back(candidates[index]);
        backtrack(index, target - candidates[index], candidates, current, result);
        current.pop_back(); // Backtrack

        // Decision 2: Move to the next element (exclude current element)
        backtrack(index + 1, target, candidates, current, result);
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(0, target, candidates, current, result);
        return result;
    }
};