#include <vector>

using namespace std;

class Solution {
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

public:
    void solveSudoku(vector<vector<char>>& board) {
        // 1. Initialize bitmasks with the pre-filled numbers
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int bit = 1 << (board[r][c] - '1');
                    int boxIdx = (r / 3) * 3 + (c / 3);
                    rows[r] |= bit;
                    cols[c] |= bit;
                    boxes[boxIdx] |= bit;
                }
            }
        }

        // 2. Start backtracking from the top-left cell
        backtrack(board, 0, 0);
    }

private:
    bool backtrack(vector<vector<char>>& board, int r, int c) {
        // Reached the end of the board -> solved!
        if (r == 9) return true;

        // Calculate the next cell's coordinates
        int nextR = (c == 8) ? r + 1 : r;
        int nextC = (c == 8) ? 0 : c + 1;

        // Skip cells that are already filled
        if (board[r][c] != '.') {
            return backtrack(board, nextR, nextC);
        }

        int boxIdx = (r / 3) * 3 + (c / 3);

        // Try placing digits '1' through '9'
        for (int d = 0; d < 9; ++d) {
            int bit = 1 << d;

            // Check if digit is valid using your bitmask check
            if ((rows[r] & bit) || (cols[c] & bit) || (boxes[boxIdx] & bit)) {
                continue;
            }

            // Place the digit and update bitmasks
            board[r][c] = '1' + d;
            rows[r] |= bit;
            cols[c] |= bit;
            boxes[boxIdx] |= bit;

            // Recurse to the next cell
            if (backtrack(board, nextR, nextC)) {
                return true;
            }

            // Backtrack: undo the placement and clear the bitmasks
            board[r][c] = '.';
            rows[r] ^= bit;
            cols[c] ^= bit;
            boxes[boxIdx] ^= bit;
        }

        return false;
    }
};

