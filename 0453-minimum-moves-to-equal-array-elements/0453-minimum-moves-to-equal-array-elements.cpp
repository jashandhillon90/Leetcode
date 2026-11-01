class Solution {
public:
    int minMoves(vector<int>& nums) {
        //n-1 elemt ko increment by 1 krna =ek element ko decrement by 1 k equal ho jayega so sabhi element ko smallest element k equal krdenge by decreasing one
        int ans=0;
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            ans+=nums[i]-mini;

        }
        return ans;
    }
};