class Solution {
   public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis) {
        vis[node] = 1;
        for(int x:adj[node]) {
            if(!vis[x]) {
                dfs(x,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
};
