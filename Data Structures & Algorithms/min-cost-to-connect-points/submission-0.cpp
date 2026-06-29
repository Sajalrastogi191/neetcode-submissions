class Solution {
public:
    class DSU {
        public:
        vector<int> parent;
        vector<int> rank;
        
        DSU(int n){
            parent.resize(n);
            rank.resize(n);

            for(int i = 0;i<n;i++) parent[i] = i;
            for(int i = 0;i<n;i++) rank[i] = 0;
        }
        
        int findParent(int u) {
            if(parent[u] == u) return u;
            return parent[u] = findParent(parent[u]);
        }
        
        void unionSet(int u,int v) {
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu == pv) return;
            if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
            return;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({i,j,d});
            }
        }
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>& b) {
            return a[2] < b[2];
        });
        DSU D(n);
        int ans = 0;
        for(auto e:edges) {
            if(D.findParent(e[0]) != D.findParent(e[1])) {
                ans += e[2];
                D.unionSet(e[0],e[1]);
            }
        }
        return ans;
    }
};
