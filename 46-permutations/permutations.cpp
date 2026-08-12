class Solution {
public:
  void getpermu(vector<int>& nums,int idx,vector<vector<int>>& ans){
     if(idx==nums.size()){
        ans.push_back({nums});
        return;
     }   
     for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);//to save space we are using same array
        getpermu(nums,idx+1,ans);//backtrack
        swap(nums[idx],nums[i]);//dubara original value pr lekr gye h
     }
  }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getpermu(nums,0,ans);
        return ans;
        
    }
};