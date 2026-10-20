
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> prefDrop(n, 0);

        // Prefix maximum
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // Suffix minimum
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        // Count adjacent descents
        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        // Try every divisor k of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool valid = true;

            // Check every block of length k
            for (int l = 0; l < n; l += k) {
                int r = l + k - 1;

                // Number of descents inside the block
                int drops = prefDrop[r] - prefDrop[l];

                // Include the circular edge from last to first
                if (nums[r] > nums[l]) {
                    drops++;
                }

                // The block must be sortable by rotation
                if (drops > 1) {
                    valid = false;
                    break;
                }

                // All earlier elements must be <=
                // all elements from this block onward
                if (prefMax[l] > suffMin[l]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};
