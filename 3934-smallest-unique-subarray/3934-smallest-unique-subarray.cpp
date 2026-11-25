class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const long long B1 = 1000003, B2 = 1000033;
        const int M1 = 1000000007, M2 = 1000000009;

        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);

        // Prefix hashes and powers
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * B1 + nums[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + nums[i]) % M2;

            p1[i + 1] = (p1[i] * B1) % M1;
            p2[i + 1] = (p2[i] * B2) % M2;
        }

        // Check whether any subarray of length len is unique
        auto check = [&](int len) {
            unordered_map<unsigned long long, int> freq;

            for (int i = 0; i + len <= n; i++) {
                int j = i + len;

                long long hash1 = (h1[j] - h1[i] * p1[len] % M1 + M1) % M1;
                long long hash2 = (h2[j] - h2[i] * p2[len] % M2 + M2) % M2;

                unsigned long long key = (hash1 << 32) | hash2;

                freq[key]++;
            }

            for (auto& it : freq) {
                if (it.second == 1)
                    return true;
            }

            return false;
        };

        // Binary Search
        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};