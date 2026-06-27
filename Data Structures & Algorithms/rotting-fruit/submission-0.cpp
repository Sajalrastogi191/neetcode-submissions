class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        bool find = false;
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) find = true;
            }
        } 
        if(!find) return 0;
        int ans = -1;
        vector<vector<int>> dir ={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            int level = q.size();
            for(int i=0;i<level;i++) {
                auto [x,y] = q.front();
                q.pop();
                for(auto d:dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            ans++;
        }
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) ans = -1;
            }
        } 
        return ans;
    }
};