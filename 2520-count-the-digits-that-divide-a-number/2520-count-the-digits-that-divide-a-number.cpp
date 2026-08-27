class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int original = num;

        while (num > 0) {
            int r = num % 10;

            if (r != 0 && original % r == 0) {
                count++;
            }

            num /= 10;
        }

        return count;
    }
};