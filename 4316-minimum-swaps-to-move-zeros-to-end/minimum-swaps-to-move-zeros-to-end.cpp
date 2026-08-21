class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int swaps=0;
        int n=nums.size();
        int i=0; 
        int j=n-1;
        while(i<j){
            if(nums[i]!=0) i++;
            else if(nums[j]==0) j--;
            else{
                swap(nums[i],nums[j]);
                swaps++;
                i++;
                j--;
            }
        }
        return swaps;
    }
};