class Solution {
public:
    void getallsubsets(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>& subsets){
        if(i==nums.size()){
            subsets.push_back(ans);
            return;
        }
        // include
        ans.push_back(nums[i]);
        getallsubsets(nums,ans,i+1,subsets);
        ans.pop_back();//backtracking
        //exclude
        int idx=i+1;
        while(idx<nums.size()&&nums[idx]==nums[idx-1]) idx++;//repetation of inclusion and exclusion ko htane k liye
        getallsubsets(nums,ans,idx,subsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());// same repeated elements ek saath laane k liye
        vector<int>ans;
        vector<vector<int>>subsets;
        getallsubsets(nums,ans,0,subsets);
        return subsets;
    }
};