
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // A valid parentheses string has even length.
        if ((m + n) % 2 == 0)
            return false;

        // dp[i][j][b] means balance b is possible
        // when reaching cell (i, j).
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(
                n, vector<bool>(m + n, false)
            )
        );

        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int b = 0; b < m + n; b++) {
                    if (!dp[i][j][b])
                        continue;

                    // Move right
                    if (j + 1 < n) {
                        int nb = b + (grid[i][j + 1] == '(' ? 1 : -1);
                        if (nb >= 0 && nb < m + n) {
                            dp[i][j + 1][nb] = true;
                        }
                    }

                    // Move down
                    if (i + 1 < m) {
                        int nb = b + (grid[i + 1][j] == '(' ? 1 : -1);
                        if (nb >= 0 && nb < m + n) {
                            dp[i + 1][j][nb] = true;
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};