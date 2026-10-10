
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long total = (long long)k1 + k2;
        vector<long long> diff(nums1.size());

        long long sum = 0, maxi = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            maxi = max(maxi, diff[i]);
        }

        if (sum <= total) return 0;

        vector<long long> freq(maxi + 1, 0);

        for (long long d : diff) {
            freq[d]++;
        }

        for (long long d = maxi; d > 0 && total > 0; d--) {
            long long count = freq[d];
            long long use = min(total, count);

            freq[d] -= use;
            freq[d - 1] += use;
            total -= use;
        }

        long long ans = 0;

        for (long long d = 1; d < freq.size(); d++) {
            ans += d * d * freq[d];
        }

        return ans;
    }
};
