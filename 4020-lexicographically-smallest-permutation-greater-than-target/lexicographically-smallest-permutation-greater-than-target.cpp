class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        string ans;

        for(int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Same character is available
            if(freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            }
            else {

                // Find smallest character greater than target[i]
                int bigger = -1;

                for(int c = x + 1; c < 26; c++) {
                    if(freq[c] > 0) {
                        bigger = c;
                        break;
                    }
                }

                if(bigger != -1) {

                    ans += char('a' + bigger);
                    freq[bigger]--;

                    // Put remaining characters in sorted order
                    for(int c = 0; c < 26; c++) {
                        while(freq[c] > 0) {
                            ans += char('a' + c);
                            freq[c]--;
                        }
                    }

                    return ans;
                }

                // Cannot continue matching.
                // We need to backtrack.
                break;
            }
        }

        // Backtrack
        for(int j = ans.size() - 1; j >= 0; j--) {

            // Return ans[j] back to freq
            freq[ans[j] - 'a']++;

            int x = target[j] - 'a';

            // Find smallest character > target[j]
            int bigger = -1;

            for(int c = x + 1; c < 26; c++) {
                if(freq[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if(bigger != -1) {

                string res = ans.substr(0, j);

                res += char('a' + bigger);
                freq[bigger]--;

                // Remaining characters in sorted order
                for(int c = 0; c < 26; c++) {
                    while(freq[c] > 0) {
                        res += char('a' + c);
                        freq[c]--;
                    }
                }

                return res;
            }
        }

        return "";
    }
};