class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>>& visited) {
        visited[i][j] = 1;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto &d:dir) {
            int ni = i+d[0],nj = j+d[1];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(ni,nj,heights,visited);
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis1(n,vector<int>(m,0));
        vector<vector<int>> vis2(n,vector<int>(m,0));
        for(int i = 0;i<n;i++) {
            dfs(i,0,heights,vis1);
        }
        for(int i = 1;i<m;i++) {
            dfs(0,i,heights,vis1);
        }
        for(int i = 0;i<m;i++) {
            dfs(n-1,i,heights,vis2);
        }
        for(int i = 0;i<n-1;i++) {
            dfs(i,m-1,heights,vis2);
        }
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(vis1[i][j] && vis2[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
