class Solution {
public:
    //backtracking with dfs
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();//cols

        //go through each char on board and see if it can start a word
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(dfs(i,j,0,word,board,n,m)){
                    //if dfs works 
                    return true;
                }
            }
        }
        return false;//word not found
    }

    bool dfs(int i,int j,int wordIndex,string word,vector<vector<char>>& board,int n,int m){
        int directions[5] = {-1, 0, 1, 0, -1};
        //base case
        if(wordIndex==word.size()){
            return true;
        }
       
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[wordIndex]) {
            return false;
        }


        //temp store curr char
        char temp = board[i][j];
        board[i][j]='0';//mark visited

        //explore adjacent cells in 4 dirs
        for(int dir=0;dir<4;dir++){
            int newRow = i+directions[dir];
            int newCol = j+directions[dir+1];

            //in limits of board and not visited and able to complete word from this pos
            if(dfs(newRow,newCol,wordIndex+1,word,board,n,m)){
                return true;
            }
        }

        //backtracking,restore back to original char
        board[i][j] = temp;
        return false;
    }
};//O(m*n*3^l-1) where l is length of word and O(length of word) as rec call stack