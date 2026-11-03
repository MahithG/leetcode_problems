
class Solution {
public:
    int minMoves(vector<int>& nums) {

        int maxi = 0;
        int sum = 0;

        for(int x : nums) {
            maxi = max(maxi, x);
            sum += x;
        }

        return maxi * nums.size() - sum;
    }
};
