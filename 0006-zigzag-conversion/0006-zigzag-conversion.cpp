class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: If 1 row or string is shorter than rows, no zigzag is possible
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create an array of strings for each row
        std::vector<std::string> rows(numRows, "");
        int currRow = 0;
        bool goingDown = false;

        // Walk through each character in the string
        for (char c : s) {
            rows[currRow] += c; // Add character to the current row

            // If we hit the top or bottom row, reverse the direction
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to the next row depending on direction
            currRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};