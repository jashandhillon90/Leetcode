class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,m;
        while(l<=r){
            m=l+(r-l)/2;
            if(target==nums[m]){
                 return m;
                 }
            else if(target>nums[m]) {
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return l;
    }
};