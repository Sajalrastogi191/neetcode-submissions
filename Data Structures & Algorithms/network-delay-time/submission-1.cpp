class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it:times) {
            int u = it[0],v = it[1], t = it[2];
            adj[u-1].push_back({v-1,t});
        }
        queue<int> q;
        q.push(k-1);
        vector<int> dist(n,INT_MAX);
        dist[k-1] = 0;
        while(!q.empty()) {
            auto u = q.front();
            q.pop();

            for(auto &[v,wt]:adj[u]) {
                if(dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++) {
            ans = max(ans,dist[i]);
        }
        return (ans==INT_MAX)? -1:ans;
    }
};
