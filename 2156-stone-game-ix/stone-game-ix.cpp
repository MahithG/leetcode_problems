class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int x : stones) {
            if (x % 3 == 0)
                cnt0++;
            else if (x % 3 == 1)
                cnt1++;
            else
                cnt2++;
        }

        // If one of cnt1 or cnt2 is zero
        if (min(cnt1, cnt2) == 0) {
            return max(cnt1, cnt2) > 2 && cnt0 % 2 == 1;
        }

        // Both cnt1 and cnt2 are present
        return abs(cnt1 - cnt2) > 2 || cnt0 % 2 == 0;
    }
};