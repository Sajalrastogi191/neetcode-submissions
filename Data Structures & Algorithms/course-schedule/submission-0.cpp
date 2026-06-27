class Solution {
public:
    bool iscycle(int node,vector<vector<int>> adj,vector<int>& vis,vector<int> &dfsvis) {
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto &x:adj[node]) {
            if(!vis[x]) {
                if(iscycle(x,adj,vis,dfsvis)) return true;
            } else if(vis[x] && dfsvis[x]) {
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites) {
            int u = it[0], v = it[1];
            adj[v].push_back(u);
        }
        vector<int> vis(numCourses,0);
        vector<int> dfsvis(numCourses,0);
        for(int i = 0;i<numCourses;i++) {
            if(iscycle(i,adj,vis,dfsvis)) return false;
        }
        return true;
    }
};
