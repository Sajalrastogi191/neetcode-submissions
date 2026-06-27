class Solution {
public:
    bool iscycle(int node,vector<vector<int>> adj,vector<int>& vis,vector<int> &dfsvis,stack<int>& st) {
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto &x:adj[node]) {
            if(!vis[x]) {
                if(iscycle(x,adj,vis,dfsvis,st)) return true;
            } else if(vis[x] && dfsvis[x]) {
                return true;
            }
        }
        dfsvis[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites) {
            int u = it[0], v = it[1];
            adj[v].push_back(u);
        }
        stack<int> st;
        vector<int> vis(numCourses,0);
        vector<int> dfsvis(numCourses,0);
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(iscycle(i, adj, vis, dfsvis, st))
                    return {};
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
