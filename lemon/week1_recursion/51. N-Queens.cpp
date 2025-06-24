class Solution {
public:
    vector<vector<string>> res;

    bool isValid(vector<string> &board, int row, int col){

        // up
        for(int i = row-1; i>=0; i--){
            if(board[i][col] == 'Q')
            return false;
        }
        // rightD
        for(int i = row-1, j = col+1; i>=0 && j<board.size(); i--, j++){
            if(board[i][j] == 'Q')
            return false;
        }
        // leftD
        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q')
            return false;
        }
        return true;

    }

    void solve(vector<string> board, int row){
        if(row==board.size()){
            res.push_back(board);
            return;
        }
        for(int col = 0; col<board.size(); col++){
            if(isValid(board, row, col)){

                board[row][col] = 'Q';
                solve(board, row+1);
                board[row][col] = '.';

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // empty as of now
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return res;
    }
};