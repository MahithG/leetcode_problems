class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // start, end, weight, original index
        vector<array<int,4>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if(a[1] != b[1])
                return a[1] < b[1];

            return a[0] < b[0];
        });

        // prev[i] = number of intervals before i
        // which are compatible with interval i
        vector<int> prev(n);

        for(int i = 0; i < n; i++) {

            int l = 0;
            int r = i - 1;

            prev[i] = 0;

            while(l <= r) {

                int mid = (l + r) / 2;

                if(v[mid][1] < v[i][0]) {
                    prev[i] = mid + 1;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }

        // dp[k][i] = best result using at most k intervals
        // among first i intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            5,
            vector<pair<long long, vector<int>>>(n + 1)
        );

        for(int k = 1; k <= 4; k++) {

            for(int i = 1; i <= n; i++) {

                // Don't take current interval
                auto skip = dp[k][i - 1];

                // Take current interval
                auto take = dp[k - 1][prev[i - 1]];

                take.first += v[i - 1][2];

                take.second.push_back(v[i - 1][3]);

                // Sort indices because answer must be sorted
                sort(take.second.begin(), take.second.end());

                // Choose the better result
                if(take.first > skip.first) {

                    dp[k][i] = take;

                }
                else if(take.first < skip.first) {

                    dp[k][i] = skip;

                }
                else {

                    // Same weight → lexicographically smaller indices
                    if(take.second < skip.second)
                        dp[k][i] = take;
                    else
                        dp[k][i] = skip;
                }
            }
        }

        return dp[4][n].second;
    }
};