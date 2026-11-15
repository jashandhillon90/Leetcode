class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        int even=1;
        int odd=0;
        int sum=0;
        int ans=0;
        for(int x:arr){
            sum+=x;
            if(sum%2==0){
                ans=(ans+odd)% MOD;
                even++;
            }
            else{
                ans=(ans+even)%MOD;
                odd++;
            }
        }
        return ans;
    }
};