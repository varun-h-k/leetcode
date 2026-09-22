class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int currentRow = 0;
        int direction = 1;

        for (char c : s) {
            rows[currentRow] += c;

            // Change direction at the top or bottom
            if (currentRow == 0)
                direction = 1;
            else if (currentRow == numRows - 1)
                direction = -1;

            currentRow += direction;
        }

        string result;

        for (string row : rows)
            result += row;

        return result;
    }
};