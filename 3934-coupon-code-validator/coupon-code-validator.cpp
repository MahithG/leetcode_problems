class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                    vector<string>& businessLine,
                                    vector<bool>& isActive) {

        int n = code.size();

        vector<int> valid;

        for(int i = 0; i < n; i++) {

            // Code must not be empty
            if(code[i].empty())
                continue;

            // Check every character
            bool ok = true;

            for(char c : code[i]) {

                if(!((c >= 'a' && c <= 'z') ||
                     (c >= 'A' && c <= 'Z') ||
                     (c >= '0' && c <= '9') ||
                     c == '_')) {

                    ok = false;
                    break;
                }
            }

            if(!ok)
                continue;

            // Check business line
            if(businessLine[i] != "electronics" &&
               businessLine[i] != "grocery" &&
               businessLine[i] != "pharmacy" &&
               businessLine[i] != "restaurant") {

                continue;
            }

            // Check active
            if(!isActive[i])
                continue;

            valid.push_back(i);
        }

        map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        sort(valid.begin(), valid.end(), [&](int a, int b) {

            if(order[businessLine[a]] != order[businessLine[b]]) {
                return order[businessLine[a]] < order[businessLine[b]];
            }

            return code[a] < code[b];
        });

        vector<string> ans;

        for(int i : valid) {
            ans.push_back(code[i]);
        }

        return ans;
    }
};