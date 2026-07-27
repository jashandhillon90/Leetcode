class Solution {
public:

        // tc and sc is n*2pown

       void subsets(vector<vector<int>>& ans,int index,vector<int>&subset,vector<int>& nums){
        if(index==nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        subsets(ans,index+1,subset,nums);// for inclusion
        subset.pop_back();
        subsets(ans,index+1,subset,nums);   //for exclusing
       } 
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        subsets(ans, 0, subset, nums);
        return ans;
    }

};