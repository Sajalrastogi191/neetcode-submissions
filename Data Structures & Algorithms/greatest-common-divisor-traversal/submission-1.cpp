class Solution {
public:
    void dfs(int u,vector<int>&vis,vector<vector<int>>& adj) {
        vis[u] = 1;
        for(int &x:adj[u]) {
            if(!vis[x]) {
                dfs(x,vis,adj);
            }
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                if(gcd(nums[i],nums[j]) > 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n);
        dfs(0,vis,adj);   
        for(int i = 0;i<n;i++) {
            if(!vis[i]) return false;
        }
        return true;
    }
};