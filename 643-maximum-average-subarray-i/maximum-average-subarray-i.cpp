class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    // pahle 4no. ka sum nikal lenge then ek ek aage bdege
    int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int maxsum=sum;
        for(int j=k;j<nums.size();j++){
            sum+=nums[j];
            sum-=nums[j-k];
            maxsum=max(sum,maxsum);

        }
        return double(maxsum)/k;
        
    }
};