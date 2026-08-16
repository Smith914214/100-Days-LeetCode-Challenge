class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case: -2147483648 / -1 = 2147483648 (overflows INT_MAX)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to absolute values using long long to prevent overflow
        long long absDividend = std::abs((long long)dividend);
        long long absDivisor = std::abs((long long)divisor);

        long long quotient = 0;

        // Perform bitwise division (Exponential Search)
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Shift left until tempDivisor is just under absDividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest found multiple
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        return isNegative ? -quotient : quotient;
    }
};