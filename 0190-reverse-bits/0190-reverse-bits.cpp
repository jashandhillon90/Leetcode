class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            // Take last bit of n
            ans = (ans << 1) | (n & 1);
            // Remove last bit from n
            n = n >> 1;
        }
        return ans;
    }
};