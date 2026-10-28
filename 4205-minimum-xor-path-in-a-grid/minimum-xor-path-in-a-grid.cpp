
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[j][x] = can XOR value x reach this cell?
        vector<vector<bool>> dp(n, vector<bool>(1024, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<bool> cur(1024, false);

                if (i == 0 && j == 0) {
                    cur[grid[i][j]] = true;
                } else {
                    // From above
                    if (i > 0) {
                        for (int x = 0; x < 1024; x++) {
                            if (dp[j][x]) {
                                cur[x ^ grid[i][j]] = true;
                            }
                        }
                    }

                    // From left
                    if (j > 0) {
                        // dp[j-1] is the current row's left cell
                        for (int x = 0; x < 1024; x++) {
                            if (dp[j - 1][x]) {
                                cur[x ^ grid[i][j]] = true;
                            }
                        }
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};
