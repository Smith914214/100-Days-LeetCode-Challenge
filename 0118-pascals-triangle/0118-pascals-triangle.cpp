#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            // Create a row filled with 1s, sized according to the current row index (i + 1)
            std::vector<int> row(i + 1, 1);
            
            // Calculate the internal values between the first and last element of the row
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            // Add the completed row to the triangle
            triangle.push_back(row);
        }

        return triangle;
    }
};