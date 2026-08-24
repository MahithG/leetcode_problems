class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefixsum(n, 0);

        prefixsum[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + stones[i];
        }

        vector<long long> t(n, 0);

        t[n - 1] = prefixsum[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            long long take = prefixsum[i] - t[i + 1];
            long long skip = t[i + 1];

            t[i] = max(take, skip);
        }

        return (int)t[1];
    }
};