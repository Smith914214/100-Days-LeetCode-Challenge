class Solution {
public:
    std::string countAndSay(int n) {
        // Base case
        std::string current = "1";
        
        // Generate the sequence iteratively up to n
        for (int i = 1; i < n; ++i) {
            std::string next_str = "";
            int len = current.length();
            
            int j = 0;
            while (j < len) {
                int count = 1;
                // Count consecutive identical characters
                while (j + 1 < len && current[j] == current[j + 1]) {
                    count++;
                    j++;
                }
                // Append the frequency followed by the character
                next_str += std::to_string(count) + current[j];
                j++;
            }
            current = next_str;
        }
        
        return current;
    }
};