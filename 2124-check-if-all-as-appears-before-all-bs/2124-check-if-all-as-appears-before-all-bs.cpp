class Solution {
public:
    bool checkString(string s) {
        bool seenB=false;
        for(char ch:s){
            if(ch=='b') seenB=true;
            if(ch=='a'&&seenB) return false;
        }
        return true;
    }
};