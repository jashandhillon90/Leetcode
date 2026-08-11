class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end())
                return false;
            s.insert(n);
            int sum = 0;
            while (n > 0) {
                int r = n % 10;
                sum += r * r;
                n = n / 10;
            }
            n = sum;
        }
        return true;
    }
};