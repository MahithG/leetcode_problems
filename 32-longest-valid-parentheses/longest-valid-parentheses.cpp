class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int ans = 0;

        for (int i = 1; i < n; i++) {

            // Case 1: current character is ')'
            if (s[i] == ')') {

                // Previous character is '('
                if (s[i - 1] == '(') {
                    dp[i] = 2;

                    // Add valid parentheses before this "()"
                    if (i >= 2)
                        dp[i] += dp[i - 2];
                }

                // Previous character is ')'
                else {
                    int j = i - dp[i - 1] - 1;

                    // Check if there is a matching '('
                    if (j >= 0 && s[j] == '(') {
                        dp[i] = dp[i - 1] + 2;

                        // Add valid substring before the matching '('
                        if (j >= 1)
                            dp[i] += dp[j - 1];
                    }
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};