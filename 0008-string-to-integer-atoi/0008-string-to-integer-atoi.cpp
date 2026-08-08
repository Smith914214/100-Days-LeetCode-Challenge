class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Discard leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Check for sign indicator
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Convert valid digits and handle overflow
        int result = 0;
        while (i < n && std::isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for 32-bit signed integer overflow/underflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return result * sign;
    }
};