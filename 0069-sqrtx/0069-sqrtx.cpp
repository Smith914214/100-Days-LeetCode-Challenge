class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        
        int low = 1;
        int high = x;
        int ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long square = mid * mid;
            
            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid; // Record the potential floor answer
                low = mid + 1; // Look for a larger value
            } else {
                high = mid - 1; // Look for a smaller value
            }
        }
        
        return ans;
    }
};