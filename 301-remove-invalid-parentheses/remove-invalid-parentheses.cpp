class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int index, int leftRemove,
               int rightRemove, int balance, string curr) {

        // End of string
        if (index == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && balance == 0) {
                ans.insert(curr);
            }
            return;
        }

        char ch = s[index];

        // Case 1: '('
        if (ch == '(') {

            // Remove it
            if (leftRemove > 0) {
                solve(s, index + 1, leftRemove - 1,
                      rightRemove, balance, curr);
            }

            // Keep it
            solve(s, index + 1, leftRemove,
                  rightRemove, balance + 1, curr + ch);
        }

        // Case 2: ')'
        else if (ch == ')') {

            // Remove it
            if (rightRemove > 0) {
                solve(s, index + 1, leftRemove,
                      rightRemove - 1, balance, curr);
            }

            // Keep it only if it doesn't make balance negative
            if (balance > 0) {
                solve(s, index + 1, leftRemove,
                      rightRemove, balance - 1, curr + ch);
            }
        }

        // Case 3: normal character
        else {
            solve(s, index + 1, leftRemove,
                  rightRemove, balance, curr + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum number of removals required
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        solve(s, 0, leftRemove, rightRemove, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};