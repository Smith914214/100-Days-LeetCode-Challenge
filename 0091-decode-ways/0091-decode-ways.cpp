class Solution {
public:
    int numDecodings(std::string s) {
        // A string starting with '0' cannot be decoded
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.length();
        
        // Tracks the number of ways for s[i-2] and s[i-1] respectively
        int prev2 = 1; // Base case for empty string
        int prev1 = 1; // Base case for string of length 1 (since s[0] != '0')
        
        for (int i = 1; i < n; ++i) {
            int current = 0;
            
            // Check if single digit valid (1-9)
            if (s[i] != '0') {
                current += prev1;
            }
            
            // Check if two digits valid (10-26)
            int twoDigit = std::stoi(s.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }
            
            // Shift values for the next iteration
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};