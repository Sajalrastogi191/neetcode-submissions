class DisjointSet {
   public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] < rank[pv])
                parent[pu] = pv;
            else if (rank[pu] > rank[pv])
                parent[pv] = pu;
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
};
class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> emailmap;
        DisjointSet D(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string temp = accounts[i][j];
                if (emailmap.find(temp) == emailmap.end()) {
                    emailmap[temp] = i;
                } else {
                    D.unite(i, emailmap[temp]);
                }
            }
        }

        vector<vector<string>> merged(n);

        for (auto& it : emailmap) {
            string email = it.first;
            int account = it.second;

            int root = D.find(account);
            merged[root].push_back(email);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), merged[i].begin(), merged[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};