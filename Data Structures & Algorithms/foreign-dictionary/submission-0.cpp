class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (auto& word : words) {
            for (char c : word) {
                indegree[c];
            }
        }
        for (int i = 1; i < words.size(); i++) {
            string w1 = words[i - 1], w2 = words[i];
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) return "";
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] == w2[j])
                    continue;
                else {
                    if (adj[w1[j]].insert(w2[j]).second) {
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;

        for (auto& it : indegree) {
            if (it.second == 0) q.push(it.first);
        }

        string ans;

        while (!q.empty()) {
            char node = q.front();
            q.pop();
            ans += node;

            for (char nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }

        if (ans.size() != indegree.size()) return "";

        return ans;
    }
};
