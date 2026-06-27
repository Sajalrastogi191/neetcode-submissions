class Solution {
public:
    bool isvalid(int i,int j,vector<vector<char>>& board) {
        char ch = board[i][j];
        for(int l = 0;l<9;l++) {
            if(l == j) continue;
            if(board[i][l] == ch) return false; 
        }
        for(int l = 0;l<9;l++) {
            if(l == i) continue;
            if(board[l][j] == ch) return false; 
        }

        int sr = (i / 3) * 3;
        int sc = (j / 3) * 3;

        for (int r = sr; r < sr + 3; r++) {
            for (int c = sc; c < sc + 3; c++) {
                if (r == i && c == j)
                    continue;
                if (board[r][c] == ch)
                    return false;
            }
        }

        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++) {
            for(int j = 0;j<9;j++) {
                if(board[i][j] != '.' && !isvalid(i,j,board)) {
                    return false;
                }
            }
        }
        return true;
    }
};
