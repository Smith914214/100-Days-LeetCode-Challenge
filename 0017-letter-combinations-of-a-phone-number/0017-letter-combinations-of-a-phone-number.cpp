class Solution {
private:
    // Mapping of digits to letters corresponding to telephone buttons
    const std::vector<std::string> phoneMap = {
        "",     "",     "abc",  "def", 
        "ghi",  "jkl",  "mno",  "pqrs", 
        "tuv",  "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        // Base case: if the current combination length equals the digits length, store it
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters that the current digit maps to
        std::string letters = phoneMap[digits[index] - '0'];
        
        // Loop through all letters for this digit
        for (char c : letters) {
            current.push_back(c);             // Choose
            backtrack(digits, index + 1, current, result); // Explore
            current.pop_back();              // Unchoose (backtrack)
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        
        // Edge case: if input is empty, return an empty list
        if (digits.empty()) {
            return result;
        }

        std::string current = "";
        backtrack(digits, 0, current, result);
        return result;
    }
};