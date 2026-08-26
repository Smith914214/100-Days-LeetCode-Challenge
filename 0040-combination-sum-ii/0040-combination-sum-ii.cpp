class Solution {
private:
    void backtrack(int index, int target, std::vector<int>& candidates, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: if the target is met, store the combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip elements greater than the remaining target to optimize performance
            if (candidates[i] > target) {
                break;
            }

            // Skip duplicate elements at the same position to avoid duplicate combinations
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Include the current element
            current.push_back(candidates[i]);

            // Move to the next element (i + 1 ensures each number is used only once)
            backtrack(i + 1, target - candidates[i], candidates, current, result);

            // Backtrack by removing the last element
            current.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        // Sort candidates to handle duplicates and enable early pruning
        std::sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, current, result);
        return result;
    }
};