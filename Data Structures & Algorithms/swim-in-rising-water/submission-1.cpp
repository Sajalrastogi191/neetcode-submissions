class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()) {
            auto [maxi,it] = pq.top();
            auto [i,j] = it;
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            if(i == n-1 && j == m-1) return maxi;
            vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
            for(auto &d:dir) {
                int ni = i+d[0],nj = j + d[1];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
                    int newmaxi = max(maxi,grid[ni][nj]);
                    pq.push({newmaxi,{ni,nj}});
                }
            }
        }
        return -1;
    }
};
