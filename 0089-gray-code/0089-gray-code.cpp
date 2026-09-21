class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> result;
        // Total numbers in the sequence is 2^n
        int numElements = 1 << n; 
        result.reserve(numElements);
        
        for (int i = 0; i < numElements; ++i) {
            // The standard formula to generate the i-th Gray code
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};