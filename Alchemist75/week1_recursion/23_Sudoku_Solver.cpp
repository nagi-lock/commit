class Solution {//apna college
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Check row and column
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == dig || board[i][col] == dig) {
                return false;
            }
        }

        // Check 3x3 grid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for (int i = srow; i < srow + 3; ++i) {
            for (int j = scol; j < scol + 3; ++j) {
                if (board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true; 
    }

    bool solver(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;  //base case

        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if (board[row][col] != '.') {
            return solver(board, nextRow, nextCol);
        }

        for (char dig = '1'; dig <= '9'; ++dig) {
            if (isSafe(board, row, col, dig)) {
                board[row][col] = dig;
                if (solver(board, nextRow, nextCol)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0, 0);
    }
};//O(9^empty cells)