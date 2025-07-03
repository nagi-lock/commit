class Solution {
public:
    bool dfs(int i,int j, vector<vector<bool>>&vis,vector<vector<char>>&board,string& word,int idx,int m,int n){
        if(idx==word.size()-1)return true;
        vis[i][j]=1;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        for(int dir=0;dir<4;++dir){
            int ni=i+dx[dir];
            int nj=j+dy[dir];

            if(ni>=0&&ni<m && nj>=0&&nj<n&& !vis[ni][nj]&&board[ni][nj]==word[idx+1]){
                if(dfs(ni,nj,vis,board,word,idx+1,m,n))
                    return true;
            }
        }

        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && dfs(i,j,vis,board,word,0,m,n))
                    return true;
            }
        }
        return false;
    }
};