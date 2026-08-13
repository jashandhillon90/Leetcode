class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int j = nums.size() - 1;

        while (j >= 0 && k > 0) {
            int r = k % 10;
            int sum = nums[j] + r;
            nums[j] = sum % 10;
            k = k / 10 + sum / 10; //sum/10=carry
            j--;
        }

        // If k still has digits
        while (k > 0) {
            nums.insert(nums.begin(), k % 10);
            k /= 10;
        }
        return nums;
    }
};