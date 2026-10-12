class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        // Initialize the row vector with a size of rowIndex + 1, filled with 1s
        std::vector<int> row(rowIndex + 1, 1);
        
        // Build the triangle row by row up to rowIndex
        for (int i = 1; i < rowIndex; ++i) {
            // Update the elements from right to left
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        
        return row;
    }
};