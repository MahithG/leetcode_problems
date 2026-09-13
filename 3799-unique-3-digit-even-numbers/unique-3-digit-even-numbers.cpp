class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int x : digits)
            freq[x]++;

        int ans = 0;

        for (int i = 1; i <= 9; i++) {          // hundreds
            for (int j = 0; j <= 9; j++) {      // tens
                for (int k = 0; k <= 8; k += 2) { // units
                    vector<int> used(10, 0);

                    used[i]++;
                    used[j]++;
                    used[k]++;

                    bool possible = true;

                    for (int d = 0; d <= 9; d++) {
                        if (used[d] > freq[d]) {
                            possible = false;
                            break;
                        }
                    }

                    if (possible)
                        ans++;
                }
            }
        }

        return ans;
    }
};