class Solution {
public:
    bool isVisited(int i,int j,int m,int n,vector<vector<char>>& board,vector<vector<int>>& visited,string word,int idx) {
        if(i >= 0 && i<m && j >= 0 && j<n && visited[i][j] == 0 && idx < word.size() && board[i][j] == word[idx]) return true;
        return false;
    }
    bool existHelper(int i,int j,int m,int n,vector<vector<char>>& board,string word,int idx,vector<vector<int>>& visited) {
        if(idx >= word.size()) {
            return true;
        }
        visited[i][j] = 1;
        //up
        if(isVisited(i-1,j,m,n,board,visited,word,idx) && existHelper(i-1,j,m,n,board,word,idx+1,visited)) {
            return true;
        }
        //down
        if(isVisited(i+1,j,m,n,board,visited,word,idx) && existHelper(i+1,j,m,n,board,word,idx+1,visited)) {
            return true;
        }
        //left
        if(isVisited(i,j-1,m,n,board,visited,word,idx) && existHelper(i,j-1,m,n,board,word,idx+1,visited)) {
            return true;
        }
        //right
        if(isVisited(i,j+1,m,n,board,visited,word,idx) &&  existHelper(i,j+1,m,n,board,word,idx+1,visited)) {
            return true;
        }
        visited[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;

        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0]) {
                    if(existHelper(i,j,m,n,board,word,1,visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};