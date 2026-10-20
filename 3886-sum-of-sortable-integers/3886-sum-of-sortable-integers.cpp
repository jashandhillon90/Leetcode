
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            bool valid = true;
            int prevMax = INT_MIN;
            for (int start = 0; start < n; start += k) {
                int mn = nums[start];
                int mx = nums[start];
                int desc = 0;
                for (int i = start; i < start + k; i++) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                    int next = (i + 1 == start + k) ? start : i + 1;
                    if (nums[i] > nums[next])
                        desc++;
                }
                // A block must be sortable by rotation
                if (desc > 1 || mn < prevMax) {
                    valid = false;
                    break;
                }
                prevMax = mx;
            }
            if (valid)
                ans += k;
        }
        return ans;
    }
};
