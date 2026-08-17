class Solution {
public:
   int squaredsum(int n){
    int sum=0;
    while(n>0){
        int r=n%10;
        sum+=r*r;
        n/=10;
    }
    return sum;
   }
    bool isHappy(int n) {
        // unordered_set<int> s;
        // while (n != 1) {
        //     if (s.find(n) != s.end())
        //         return false;
        //     s.insert(n);
        //     int sum = 0;
        //     while (n > 0) {
        //         int r = n % 10;
        //         sum += r * r;
        //         n = n / 10;
        //     }
        //     n = sum;
        // }
        // return true;
        // cycle ban rhi then we use fast and slow pointer.
        int slow=squaredsum(n);
        int fast=squaredsum(squaredsum(n));
        while(fast!=slow){
            slow=squaredsum(slow);
            fast=squaredsum(squaredsum(fast));
        }
        return slow==1;
    }
};