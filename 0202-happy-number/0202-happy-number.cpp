class Solution {
public:
    int helper(int n){
        int sum = 0;
        while(n>0){
            int d = n%10;
            n = n/10;
            sum = sum + d*d; 
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        while(n!=1){
            n = helper(n);
            if(n<10) return n==1||n==7;
        }
        return true; 
    }
};