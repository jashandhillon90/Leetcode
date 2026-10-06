class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int ans=0;
        for(char c:s){
            if(c=='('){
                open++;
            }else{//')' aa gya
                 if(open>0){//'('jyada h
                    open--;
                 }else{//')'jyada h
                    ans++;
                 }
            }
        }
        return open+ans;
    }
};