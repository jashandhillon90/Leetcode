class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int lp=0;
        int rp=n-1;
        int index=n-1;
        while(lp<=rp){
         if(abs(nums[lp])>abs(nums[rp])){
            ans[index]=nums[lp]*nums[lp];
            lp++;
         }else{
            ans[index]=nums[rp]*nums[rp];
            rp--;
         }
         index--;
        }
        return ans;
    }
};