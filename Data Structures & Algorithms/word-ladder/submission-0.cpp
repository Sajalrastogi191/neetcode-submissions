class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> um;
        int st = -1;
        int en = -1;
        for(int i = 0;i<wordList.size();i++) {
            um[wordList[i]] = i;
            if(wordList[i] == endWord) en = i;
            if(wordList[i] == beginWord) st = i;
        }
        if(en == -1) return 0;
        if(st == -1) {
            wordList.push_back(beginWord);
            st = wordList.size()-1;
            um[beginWord] = wordList.size()-1;
        }
        vector<vector<int>> adj(wordList.size());
        for(auto word:wordList) {
            string temp = word;
            for(int i = 0;i<word.size();i++) {
                for(char c = 'a'; c <= 'z'; c++) {
                    if(c == word[i]) continue;
                    temp[i] = c;
                    if(um.count(temp)) adj[um[word]].push_back(um[temp]);
                }
                temp = word;
            }
        }
        queue<int> q;
        vector<int> vis(adj.size(),0);
        q.push(st);
        int dist = 1;
        vis[st]=1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front(); q.pop();
                if(node == en) return dist;

                for(int x : adj[node]) {
                    if(!vis[x]) {
                        vis[x] = 1;
                        q.push(x);
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};