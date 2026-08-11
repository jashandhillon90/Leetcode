class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //Sliding window array subarray(continuous)
        //if given minimum sum then fixed sliding window
        //so we use dynamic sliding window not size fixed
        int n=nums.size();
        int left=0;
        int sum=0;
        int size=INT_MAX;
        for(int right=0;right<n;right++){
            sum+=nums[right];
        
            while(sum>=target){
                size=min(size,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return size==INT_MAX ? 0:size;
    }
};