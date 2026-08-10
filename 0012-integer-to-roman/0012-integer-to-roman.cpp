class Solution {
public:
    std::string intToRoman(int num) {
        // Map values to Roman symbols in descending order
        std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::vector<std::string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        std::string result = "";
        
        // Loop through each value
        for (size_t i = 0; i < values.size(); ++i) {
            // Repeat symbol while num is greater or equal
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];
            }
        }
        
        return result;
    }
};