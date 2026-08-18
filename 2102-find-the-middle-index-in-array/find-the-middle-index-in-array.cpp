class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
       int leftsum=0;
       int rightsum=0;
       int finalsum=0;
       for(int i=0;i<nums.size();i++){
        finalsum+=nums[i];
       } 
        for(int i=0;i<nums.size();i++){
            rightsum=finalsum-nums[i]-leftsum;
            if(leftsum==rightsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};