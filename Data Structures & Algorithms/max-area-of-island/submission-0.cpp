class Solution {
   public:
    void dfs(int i, int j, vector<vector<int>>& grid,int &cnt) {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = 0;
        cnt++;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj]) {
                dfs(ni, nj, grid,cnt);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int cnt = 0;
                    dfs(i, j, grid,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
