class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,int final,bool &canvis) {
        if(node == final) {
            canvis =true;
            return;
        }
        vis[node] = 1;
        for(int x:adj[node]) {
            if(!vis[x]) {
                dfs(x,adj,vis,final,canvis);
            }
        }
        return;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(auto e:prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vector<bool> ans;
        for(auto &q:queries) {
            vector<int> vis(numCourses,0);
            bool tmp = false;
            dfs(q[0],adj,vis,q[1],tmp);
            ans.push_back(tmp);
        }
        return ans;
    }
};