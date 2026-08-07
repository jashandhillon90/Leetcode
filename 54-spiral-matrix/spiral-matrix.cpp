class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m=mat.size(),n=mat[0].size();
        int srow=0,scol=0,erow=m-1,ecol=n-1;
        while(srow<=erow&&scol<=ecol){
            //TOP
            for(int j=scol;j<=ecol;j++){
                ans.push_back(mat[srow][j]);
            }
            //Right
            for(int i=srow+1;i<=erow;i++){
                ans.push_back(mat[i][ecol]);
            }
            //Bottom
            for(int j=ecol-1;j>=scol;j--){
                if(srow==erow){
                    break;
                }
                ans.push_back(mat[erow][j]);
            }
            //Left
            for(int i=erow-1;i>=scol+1;i--){
                if(scol==ecol){
                    break;
                }
                ans.push_back(mat[i][scol]);
            }
            srow++; scol++;erow--;ecol--;
        }
        return ans;
    }
};