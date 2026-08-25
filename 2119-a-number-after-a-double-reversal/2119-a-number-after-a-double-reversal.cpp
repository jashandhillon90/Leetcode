class Solution {
public:
    bool isSameAfterReversals(int num) {
      int sum=0;
      if(num==0) return true;
       int original=num;
        while(num>0){
            int r=num%10;
             sum=r+sum*10;
             num/=10;
        }
        int rev1=sum;
        int rev2=0;
        while(rev1>0){
            int r=rev1%10;
            rev2=r+rev2*10;
            rev1/=10;
        }
        return original==rev2;
    }
};