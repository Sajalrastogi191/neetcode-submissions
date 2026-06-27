class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = '0';
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto &d:dir) {
            int ni=i+d[0],nj=j+d[1];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1') {
                dfs(ni,nj,grid);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == '1') {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
