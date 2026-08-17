class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int maxpro=nums[0];
        int minpro=nums[0];
        for(int i=1;i<nums.size();i++){
         int a=maxpro*nums[i];
         int b=minpro*nums[i];
         int c=nums[i];
         maxpro=max(c,max(a,b));
         minpro=min(c,min(a,b));
         ans=max(ans,maxpro);
        }
        return ans;
    }
};