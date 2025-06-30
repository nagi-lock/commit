class Solution {
public:
    //backtracking
    //start with col as 0 till n.
    vector<vector<string>> result;
    vector<bool> rows_taken;
    vector<bool> diag1;//top left to bottom right
    vector<bool> diag2;// top right to bottom left.
    int DIM;

    void solve(vector<string>& board, int col) {
        if (col == DIM) {
            result.push_back(board);
            return;
        }
        for (int row = 0; row < DIM; ++row) {
            if (!rows_taken[row] && !diag1[row + col] && !diag2[row - col + DIM - 1]) {
                board[row][col] = 'Q';
                rows_taken[row] = diag1[row + col] = diag2[row - col + DIM - 1] = true;

                solve(board, col + 1);

                //backtracking
                board[row][col] = '.';
                rows_taken[row] = diag1[row + col] = diag2[row - col + DIM - 1] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        DIM = n;
        rows_taken = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return result;
    }
};//O(N!) and O(N^2)
