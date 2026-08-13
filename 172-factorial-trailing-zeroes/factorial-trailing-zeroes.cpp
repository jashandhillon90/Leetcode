class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n>0){
            n/=5;  //n/5+n/25+/125.......
            count+=n;
            
        }

return count;
        
    }
};