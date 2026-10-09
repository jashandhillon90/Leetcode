class Solution {
public:
    int minInsertions(string s) {
      int open=0;
      int ans=0;
      for(int i=0;i<s.size();i++){
        if(s[i]=='('){
          open++;
       }else{
        //check next character is also ')'
        if(i+1<s.size()&&s[i+1]==')'){
            i++; //kyuki 2 consecutive right honge isliye
        }else{
            ans++;//agar nhi h toh')' ek add krege to complete pair
        }if (open>0){
            open--;//pair ko match krne k liye
        }else{
            ans++;//'('not available so insert
        }
       }
      }
      return ans+2*open;//kyuki ek k liye 2 chahiye
    }
};