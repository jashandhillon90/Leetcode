class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m,string(n,'#'));
        // First row ko free kar do
        grid[0] = string(n, '.');
        // Last column ko free kar do
        for(int i=0;i<m;i++) {
            grid[i][n-1] = '.';
        }
        return grid;
    }
};