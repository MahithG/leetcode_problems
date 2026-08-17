class Solution {
public:

    int solve(int i, int j, vector<int>& stoneValue,
              vector<vector<int>>& dp,
              vector<int>& prefix) {

        // Only one stone remains
        if (i == j)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        // Try every possible split
        for (int k = i; k < j; k++) {

            int leftSum = prefix[k + 1] - prefix[i];

            int rightSum = prefix[j + 1] - prefix[k + 1];

            // Left side is smaller
            if (leftSum < rightSum) {

                ans = max(ans,
                          leftSum + solve(i, k, stoneValue,
                                          dp, prefix));
            }

            // Right side is smaller
            else if (leftSum > rightSum) {

                ans = max(ans,
                          rightSum + solve(k + 1, j, stoneValue,
                                          dp, prefix));
            }

            // Both sides are equal
            else {

                ans = max(ans,
                          leftSum +
                          max(solve(i, k, stoneValue, dp, prefix),
                              solve(k + 1, j, stoneValue, dp, prefix)));
            }
        }

        return dp[i][j] = ans;
    }


    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // Prefix sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[i][j] = maximum score from i to j
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, stoneValue, dp, prefix);
    }
};