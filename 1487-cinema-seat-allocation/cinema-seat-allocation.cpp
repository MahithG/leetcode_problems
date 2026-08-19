class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<int>> mp;

        for(auto x : reservedSeats) {
            mp[x[0]].push_back(x[1]);
        }

        int ans = 2 * n;

        for(auto x : mp) {

            int row = x.first;
            vector<int> seats = x.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            for(int seat : seats) {

                if(seat >= 2 && seat <= 5)
                    left = false;

                if(seat >= 4 && seat <= 7)
                    middle = false;

                if(seat >= 6 && seat <= 9)
                    right = false;
            }

            // This row initially contributed 2,
            // so remove its default 2 and calculate properly.
            ans -= 2;

            if(left && right)
                ans += 2;
            else if(left || middle || right)
                ans += 1;
        }

        return ans;
    }
};