class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& nums) {
        int totalsum=0;
        int leftsum=0,rightsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        if(totalsum%3!=0) return false;
        int sum=0;
        int parts=0;
        int target=totalsum/3;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==target){
                parts++;
                sum=0;
            }
        }
        return parts>=3;
    }
};