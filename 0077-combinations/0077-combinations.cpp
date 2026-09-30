class Solution {
private:
    void backtrack(int start, int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // If the combination is done
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Optimization: Only loop if there are enough remaining elements to form a valid combination
        for (int i = start; i <= n - (k - current.size()) + 1; ++i) {
            // Add i into the current combination
            current.push_back(i);
            
            // Move on to the next element
            backtrack(i + 1, n, k, current, result);
            
            // Backtrack by removing i
            current.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};