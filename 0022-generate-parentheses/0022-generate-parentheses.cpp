class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string current, int openCount, int closeCount, int maxPairs) {
        // Base case: If the current string reaches the maximum length, it's a valid combination
        if (current.length() == maxPairs * 2) {
            result.push_back(current);
            return;
        }

        // If we can still add an opening parenthesis, do so
        if (openCount < maxPairs) {
            backtrack(result, current + "(", openCount + 1, closeCount, maxPairs);
        }

        // If we have more opening than closing parentheses, we can safely add a closing one
        if (closeCount < openCount) {
            backtrack(result, current + ")", openCount, closeCount + 1, maxPairs);
        }
    }
};