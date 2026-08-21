class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Track seen numbers (1-9 mapped to indices 0-8)
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                // Skip empty cells
                if (board[r][c] == '.') continue;
                
                // Convert char digit ('1'-'9') to index (0-8)
                int num = board[r][c] - '1';
                int box_index = (r / 3) * 3 + (c / 3);
                
                // If the number already exists in this row, col, or box
                if (rows[r][num] || cols[c][num] || boxes[box_index][num]) {
                    return false;
                }
                
                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box_index][num] = true;
            }
        }
        
        return true;
    }
};