class Solution {
public:
    int integerBreak(int n) {
       if(n<=3)return n-1;//agar 3 h toh 2 or 2 h toh 1
       int ans=1;
       while(n>4){
        ans*=3;
        n-=3;
       } 
       return ans*n;//kyuki last n ki value bachegi usko bhi multiply krna hoga na
    }
};