class Solution {
   public:
    vector<int> topo(int k, vector<vector<int>>& conditions) {
        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k + 1, 0);

        for (auto& it : conditions) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> order;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);

            for (int nxt : adj[node]) {
                indegree[nxt]--;

                if (indegree[nxt] == 0) q.push(nxt);
            }
        }

        if (order.size() != k) return {};

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topo(k, rowConditions);
        vector<int> colOrder = topo(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) return {};

        vector<int> rowPos(k + 1), colPos(k + 1);

        for (int i = 0; i < k; i++) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int num = 1; num <= k; num++) {
            ans[rowPos[num]][colPos[num]] = num;
        }

        return ans;
    }
};