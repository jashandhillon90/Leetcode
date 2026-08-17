class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int currSum = 0;
        // int maxSum = INT_MIN;

        // for (int i=0;i<nums.size();i++) {
        //     currSum += nums[i];
        //     maxSum = max(maxSum, currSum);
        
        // if(currSum<0){   agar negative ho gya toh 0 kr rhe h
        //     currSum=0;
        // }
        // }
        int maxsum=nums[0];
        int ans=nums[0];
        for (int i=1;i<nums.size();i++) {
            int a=maxsum+nums[i];
            int b=nums[i];
            maxsum=max(a,b);
            ans=max(ans,maxsum);
        }
        return ans;
    }
};