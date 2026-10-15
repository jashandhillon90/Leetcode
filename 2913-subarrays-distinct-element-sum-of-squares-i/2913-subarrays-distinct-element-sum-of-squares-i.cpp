class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int> s;
            for(int j=i;j<n;j++){// subarray create krne k liye
               s.insert(nums[j]);
               int count=s.size();
               ans+=count*count;
            }
        }
        return ans;
    }
};