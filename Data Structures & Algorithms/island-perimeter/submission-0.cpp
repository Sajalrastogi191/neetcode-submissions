class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
        int ans = 0;
        grid[i][j] = 2;
        for(auto &d:dir) {
            int ni = i+d[0];
            int nj = j+d[1];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 0) {
                ans++;
            } else if(ni < 0 || ni >= n || nj < 0 || nj >= m) {
                ans++;
            } else if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1){
                ans += helper(ni,nj,grid);
            }
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]) {
                    return helper(i,j,grid);
                }
            }
        }
        return 0;
    }
};