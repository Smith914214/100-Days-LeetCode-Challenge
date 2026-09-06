class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the array from the least significant digit (right to left)
        for (int i = n - 1; i >= 0; --i) {
            // If the current digit is less than 9, just increment it and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // If the digit is 9, it becomes 0 due to the carry over
            digits[i] = 0;
        }
        
        // If the loop finishes, it means all digits were 9 (e.g., 999 -> 000)
        // We need to add a '1' at the front of the vector (e.g., 1000)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};