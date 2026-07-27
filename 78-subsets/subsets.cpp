class Solution {
public:

        // tc and sc is n*2pown

       void subsets(vector<vector<int>>& ans,int index,vector<int>&arr,vector<int>& nums){
        if(index==nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[index]);
        subsets(ans,index+1,arr,nums);// for inclusion
        arr.pop_back();
        subsets(ans,index+1,arr,nums);   //for exclusing
       } 
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> ans;
        subsets(ans, 0, arr, nums);
        return ans;
    }

};