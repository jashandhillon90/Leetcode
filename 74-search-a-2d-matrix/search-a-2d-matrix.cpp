class Solution {
public:
   bool searchINRow(vector<vector<int>>& mat, int target,int row){
    int n=mat[0].size();
    int strtcol=0,endcol=n-1;
    while(strtcol<=endcol){
        int midcol=strtcol+(endcol-strtcol)/2;
        if(target==mat[row][midcol]) return true;
        else if(target<mat[row][midcol]) endcol=midcol-1;
        else strtcol=midcol+1;
    
    }
    return false;
   }

    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size();
        int strow=0,endrow=m-1;
        while(strow<=endrow){
            int midrow=strow+(endrow-strow)/2;
            if(target>=mat[midrow][0]&&target<=mat[midrow][n-1]){
                return searchINRow(mat,target,midrow);
            }else if(target>mat[midrow][n-1]){
                strow=midrow+1;
            }else{
                endrow=midrow-1;
            }
        }
        return false;
    }
};