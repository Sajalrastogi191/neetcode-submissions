class Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<char>>& board) {
        if(i>=0 && i<n && j>=0 && j<m && board[i][j] == 'O') {
            return true;
        }
        return false;
    }
    void dfs(int i,int j,int n,int m,vector<vector<char>>& board) {
        board[i][j] = 'Y';
        int ax[4] ={1,-1,0,0};
        int ay[4] ={0,0,1,-1};
        
        for(int k=0;k<4;k++) {
            int nx=i+ax[k];
            int ny=j+ay[k];

            if(isValid(nx,ny,n,m,board)){
                dfs(nx,ny,n,m,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(board[i][j] == 'O') dfs(i,j,n,m,board);
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};