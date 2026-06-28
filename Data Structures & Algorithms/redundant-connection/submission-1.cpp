class Solution {
   public:
    class DSU {
       public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int node) {
            if (parent[node] == node) return node;
            return parent[node] = find(parent[node]);
        }

        void unite(int u, int v) {
            u = find(u);
            v = find(v);

            if (u == v) return;

            if (size[u] < size[v]) swap(u, v);

            parent[v] = u;
            size[u] += size[v];
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU d(n+1);
        vector<int> ans;
        for(auto &it:edges) {
            int u = it[0];
            int v = it[1];
            if(d.find(u) != d.find(v)) {
                d.unite(u,v);
            } else {
                return {u,v};
            }
        }
        return ans;
    }
};
