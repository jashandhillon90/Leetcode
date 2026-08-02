class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int xor1 = 0;
        int n = nums.size();

        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR all elements of the array
        for (int num : nums) {
            xor1 ^= num;
        }

        return xor1; 
    }
};