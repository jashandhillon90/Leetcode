class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int i=0;i<4;i++){//bcoz 4 rotation hi possible h 0 90 180 270
         bool same=true;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j]){
                    same=false;
                    break;
                }
            }
        if(!same)break;
         }
        if (same)return true;            
         // rotate krege mat ko 90 se
         vector<vector<int>> temp(n, vector<int>(n));
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[j][n-1-i]=mat[i][j];//jse 2*2 me 0,0 pahunch jayega 0,1 pr
            }
         }
         mat=temp;
        }
        return false;
    }
};