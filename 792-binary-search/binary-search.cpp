class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lp=0,rp=n-1;
        while(lp<=rp){
            int mid=lp+(rp-lp)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target){
                rp=mid-1;
            }else{
                lp=mid+1;
            }
        }
        return -1;
    }
};