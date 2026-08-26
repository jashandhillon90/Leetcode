class Solution {
public:
    int arraySign(vector<int>& nums) {
    int negative = 0;

    for (int x : nums) {
        if (x == 0)
            return 0;

        if (x < 0)
            negative++;
    }

    return (negative % 2 == 0) ? 1 : -1;

    }
};