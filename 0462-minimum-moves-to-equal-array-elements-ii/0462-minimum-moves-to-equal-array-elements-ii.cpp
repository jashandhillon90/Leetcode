class Solution {
public:
    int minMoves2(vector<int>& nums) {
      //yaha  median find krenge uske according minimum distance hoti h sabhi element ki
      sort(nums.begin(),nums.end());
      int n=nums.size();
      int median=nums[n/2];
      int ans=0;
      for(int i=0;i<n;i++){
        ans+=abs(nums[i]-median);
      }  
      return ans;
    }
};