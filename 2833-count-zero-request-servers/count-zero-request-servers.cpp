
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        int m = queries.size();

        vector<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(m, 0);
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0;
        int active = 0;
        int L = logs.size();

        for (auto [time, idx] : q) {

            // Add requests up to current query time
            while (right < L && logs[right][1] <= time) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    active++;
                }

                freq[server]++;
                right++;
            }

            // Remove requests outside the time window
            while (left < right &&
                   logs[left][1] < time - x) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    active--;
                }

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
