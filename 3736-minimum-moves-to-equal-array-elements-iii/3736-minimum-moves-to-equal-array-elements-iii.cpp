class Solution {
public:
    int minMoves(vector<int>& nums) {
        //isme 1 inc. kr skte h yani sabhi ko maximum ele. k brabar bnana h
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=maxi-nums[i];
        }
        return ans;
    }
};