class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
     //first we can do transpose then rotate every row then it is the rotated at 90degree.
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);//yaha transpose ho jayega
        }
     }   
     //an reverse krna h har row ko
     for(int i=0;i<n;i++){
        //reverse(matrix[i].begin(),matrix[i].end());
        int left=0;
        int right=n-1;
    while (left<right) {
        swap(matrix[i][left], matrix[i][right]);
        left++;
        right--;
     }
     }
    }
};