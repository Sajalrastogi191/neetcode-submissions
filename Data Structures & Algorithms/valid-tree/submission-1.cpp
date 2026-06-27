class Solution {
public:
    bool iscycle(int node,vector<vector<int>>& adj,vector<int>& vis,int parent) {
        vis[node] = 1;
        for(auto &x:adj[node]) {
            if(!vis[x]) {
                if(iscycle(x,adj,vis,node)) return true;
            } else if(parent != x) {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        if(iscycle(0,adj,vis,-1)) return false;
        for(int i = 0;i<n;i++) {
            if(!vis[i]) return false;
        }
        return true;
    }
};
