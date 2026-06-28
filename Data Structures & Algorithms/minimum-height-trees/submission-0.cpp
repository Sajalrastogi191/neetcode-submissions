class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it:edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++) {
            queue<int> q;
            q.push(i);
            vector<int> vis(n,0);
            vis[i] = 1;
            int h = 0;
            while(!q.empty()) {
                int level = q.size();
                for(int j = 0;j<level;j++) {
                    auto node = q.front();
                    q.pop();
                    for(auto &x:adj[node]) {
                        if(!vis[x]) {
                            vis[x] = 1;
                            q.push(x);
                        }
                    }
                }
                h++;
            }
            if(h < mini) {
                mini = h;
                ans = {};
                ans.push_back(i);
            } else if(h == mini) {
                ans.push_back(i);
            }
        }
        return ans;
    }
}; 