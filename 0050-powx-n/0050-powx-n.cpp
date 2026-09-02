class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to handle the overflow case when n = -2^31
        long long N = n; 
        
        // If the exponent is negative, invert the base and make the exponent positive
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0;
        double current_product = x;
        
        // Binary exponentiation loop
        while (N > 0) {
            // If the current bit is 1, multiply the answer by current_product
            if (N % 2 == 1) {
                ans *= current_product;
            }
            // Square the base for the next bit position
            current_product *= current_product;
            // Shift to the next bit
            N /= 2;
        }
        
        return ans;
    }
};