
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<long long> diff(n);
        long long maxDiff = 0;
        long long totalDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            totalDiff += diff[i];
        }

        // All differences can become zero.
        if (k >= totalDiff) return 0;

        // Find the smallest threshold T.
        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long operations = 0;

            for (long long d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long T = low;
        long long operations = 0;
        long long ans = 0;
        long long count = 0;

        for (long long d : diff) {
            if (d > T) {
                operations += d - T;
                ans += T * T;
                count++;
            } else {
                ans += d * d;
            }
        }

        // Spend the remaining operations.
        long long remaining = k - operations;

        // Each remaining operation reduces T to T - 1.
        ans -= remaining * (2 * T - 1);

        return ans;
    }
};
