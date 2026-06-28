class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        q.push({"0000",0});
        unordered_map<string,int>  um;
        for(auto &it:deadends) {
            um[it]++;
        }
        unordered_map<string,int> vis;
        vis["0000"]++;
        if(um.count("0000")) return -1;
        while(!q.empty()) {
            auto [code,cnt] = q.front();
            q.pop();
            if(code == target) return cnt;
            
            for(int i = 0;i<4;i++) {
                string next = code;
                next[i] = (code[i]=='9')? '0':code[i]+1;
                if(!um.count(next) && !vis.count(next)) {
                    vis[next]++;
                    q.push({next,cnt+1});
                }

                next = code;
                next[i] = (code[i] == '0') ? '9' : code[i] - 1;

                if(!um.count(next) && !vis.count(next)) {
                    vis[next]++;
                    q.push({next,cnt+1});
                }
            }
        }
        return -1;

    }
};