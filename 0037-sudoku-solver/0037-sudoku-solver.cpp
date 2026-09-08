class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // Horizontal
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == dig)
                return false;
        }

        // Vertical
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == dig)
                return false;
        }

        // 3x3 Grid
        int strow = (row / 3) * 3;
        int stcol = (col / 3) * 3;

        for(int i = strow; i < strow + 3; i++) {
            for(int j = stcol; j < stcol + 3; j++) {
                if(board[i][j] == dig)
                    return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {

        // All cells filled
        if(row == 9)
            return true;

        int nextrow = row;
        int nextcol = col + 1;

        if(nextcol == 9) {
            nextrow = row + 1;
            nextcol = 0;
        }

        // Already filled
        if(board[row][col] != '.') {
            return helper(board, nextrow, nextcol);
        }

        // Try digits 1 to 9
        for(char dig = '1'; dig <= '9'; dig++) {

            if(isSafe(board, row, col, dig)) {

                board[row][col] = dig;

                if(helper(board, nextrow, nextcol))
                    return true;

                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};