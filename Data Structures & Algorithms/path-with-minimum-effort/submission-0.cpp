class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        effort[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()) {
            auto [eff,it] = pq.top();
            auto [i,j] = it;
            pq.pop();

            vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
            for(auto &d:dir) {
                int ni = i + d[0], nj = j + d[1];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int neweff = max(eff,abs(heights[ni][nj] - heights[i][j]));
                    if(neweff < effort[ni][nj]) {
                        effort[ni][nj] = neweff;
                        pq.push({neweff,{ni,nj}});
                    }
                }
            }
        }
        return effort[n-1][m-1];
    }
};