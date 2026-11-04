
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        multiset<int> left, right;

        long long sumL = 0, sumR = 0;

        // Maintain the two halves
        auto balance = [&]() {

            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();

                left.erase(left.find(val));
                sumL -= val;

                right.insert(val);
                sumR += val;
            }

            while (left.size() < right.size()) {
                int val = *right.begin();

                right.erase(right.find(val));
                sumR -= val;

                left.insert(val);
                sumL += val;
            }
        };

        // Insert an element
        auto add = [&](int val) {

            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumL += val;
            }
            else {
                right.insert(val);
                sumR += val;
            }

            balance();
        };

        // Remove an element
        auto remove = [&](int val) {

            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumL -= val;
            }
            else {
                it = right.find(val);
                right.erase(it);
                sumR -= val;
            }

            balance();
        };

        // Calculate median-based window cost
        auto getCost = [&]() -> long long {

            long long median = *left.rbegin();

            long long L = left.size();
            long long R = right.size();

            return median * L - sumL
                 + sumR - median * R;
        };

        // Step 1: Calculate cost of every window
        vector<long long> cost;

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost.push_back(getCost());

        for (int i = x; i < n; i++) {

            remove(nums[i - x]);
            add(nums[i]);

            cost.push_back(getCost());
        }

        // Step 2: DP
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j <= k; j++) {

                if (dp[j][i] == INF)
                    continue;

                // Option 1: Skip current position
                dp[j][i + 1] = min(
                    dp[j][i + 1],
                    dp[j][i]
                );

                // Option 2: Select current window
                if (j < k && i + x <= n) {

                    dp[j + 1][i + x] = min(
                        dp[j + 1][i + x],
                        dp[j][i] + cost[i]
                    );
                }
            }
        }

        return *min_element(dp[k].begin(), dp[k].end());
    }
};
