class Solution {
public:
    int solve(int n){
        if(n<=1)return 1;
        int ans=0;
        for
        (int i=1;i<=n;i++){
            int left=solve(i-1);
            int right=solve(n-i);
            ans+=left*right;
        }
        return ans;
    }
    int numTrees(int n) {
     return solve(n);   
    }
};