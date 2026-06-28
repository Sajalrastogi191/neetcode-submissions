class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string, vector<pair<string,double>>> adj;
        for(int i = 0;i<n;i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }
        vector<double> ans;
        for(auto &qr:queries) {
            queue<pair<string,double>> q;
            q.push({qr[0],1.0});
            unordered_map<string,int> vis;
            vis[qr[0]]++;
            bool found = false;
            if (!adj.count(qr[0]) || !adj.count(qr[1])) {
                ans.push_back(-1.0);
                continue;
            }
            while(!q.empty()) {
                auto [it,val] = q.front();
                q.pop();
                if(it == qr[1]) {
                    found = true;
                    ans.push_back(val);
                    break;
                }
                for(auto &nbr:adj[it]) {
                    if(!vis.count(nbr.first)) {
                        vis[nbr.first]++;
                        q.push({nbr.first,val*nbr.second});
                    }
                }
            }
            if(!found) {
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};