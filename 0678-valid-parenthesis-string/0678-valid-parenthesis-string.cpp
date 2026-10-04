class Solution {
public:
    bool checkValidString(string s) {
        int low=0,high=0;
        for(char c:s){
            if(c=='('){
                low++;high++;
            }else if(c==')'){
                low--;high--;
            }else{
                low--;//* treated as')'
                high++;
            }
            if(high<0) return false;
            low=max(low,0);//low can't be neagtive
        }
        return low==0;//TC=O(n),SC=O(1)
    }
};