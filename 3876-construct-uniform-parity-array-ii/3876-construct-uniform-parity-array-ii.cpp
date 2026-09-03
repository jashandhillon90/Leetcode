class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEven = INT_MAX;
        int minOdd = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 0)
                minEven = min(minEven, x);
            else
                minOdd = min(minOdd, x);
        }

        // Make everything even
        bool even = true;
        for (int x : nums1) {
            if (x % 2 != 0 && minOdd >= x) {
                even = false;
                break;
            }
        }

        // Make everything odd
        bool odd = true;
        for (int x : nums1) {
            if (x % 2 == 0 && minOdd >= x) {
                odd = false;
                break;
            }
        }

        return even || odd;
    }
};