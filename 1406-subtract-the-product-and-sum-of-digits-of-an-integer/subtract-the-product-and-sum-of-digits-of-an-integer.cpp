class Solution {
public:
    int subtractProductAndSum(int n) {
     int sum=0,product=1,c;
     if(n==0)return 0;
     while(n>0){
        c=n%10;
        sum+=c;
        product*=c;
        n/=10;
     }   
     int diff = product-sum;
     return diff;
    }
};