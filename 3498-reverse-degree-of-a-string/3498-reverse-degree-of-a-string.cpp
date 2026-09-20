class Solution {
public:
    int reverseDegree(string s) {
       int ans=0;
       for(int i=0;i<s.length();i++){
        int val=26-(s[i]-'a');
        ans+=val*(i+1);
       } 
       return ans;
    }
};