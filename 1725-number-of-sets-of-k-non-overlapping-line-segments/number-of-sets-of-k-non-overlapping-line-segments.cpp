class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> C(n + k, 
                                    vector<long long>(2 * k + 1));

        for (int i = 0; i <= n + k - 1; i++) {
            C[i][0] = 1;

            for (int j = 1; j <= min(i, 2 * k); j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return C[n + k - 1][2 * k];
    }
};