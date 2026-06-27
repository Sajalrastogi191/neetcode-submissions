class Solution {
public:
    bool isvalid(int i,int j,vector<vector<int>>& board,int n) {
        //row 
        for(int l = j-1;l>=0;l--) {
            if(board[i][l]) return false;
        }
        //col
        for(int l = i-1;l>=0;l--) {
            if(board[l][j]) return false;
        }
        //left diagonal
        for(int l = i-1,m=j-1;l>=0 && m >= 0;l--,m--) {
            if(board[l][m]) return false;
        }
        //right diagonal
        for(int l = i-1,m=j+1;l>=0 && m < n;l--,m++) {
            if(board[l][m]) return false;
        }
        return true;
    }
    void helper(int i,int n,vector<vector<string>>& ans,vector<vector<int>>& board) {
        if(i == n) {
            vector<string> sol;
            for(int i = 0;i<n;i++) {
                string tmp;
                for(int j = 0;j<n;j++) {
                    if(board[i][j]) {
                        tmp.push_back('Q');
                    } else {
                        tmp.push_back('.');
                    }
                }
                sol.push_back(tmp);
            }
            ans.push_back(sol);
            return;
        }

        for(int j = 0;j<n;j++) {
            board[i][j] = 1;
            if(isvalid(i,j,board,n)) {
                helper(i+1,n,ans,board);
            }
            board[i][j] = 0;
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<string>> ans;
        vector<string> sol;
        helper(0,n,ans,board);
        return ans;
    }
};
