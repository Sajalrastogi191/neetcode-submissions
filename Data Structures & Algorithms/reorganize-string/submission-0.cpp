class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> um;
        for(char &ch:s) {
            um[ch]++;
        }
        for(auto it:um) {
            pq.push({it.second,it.first});
        }
        string ans = "";
        while(!pq.empty()) {
            if(!ans.empty() && ans.back() == pq.top().second) {
                auto first = pq.top();
                pq.pop();
                if(pq.empty()) return "";
                auto [fre,ch] = pq.top();
                pq.pop();
                ans += ch;
                if(fre > 1) pq.push({fre-1,ch});
                pq.push(first);
            }
            auto [fre,ch] = pq.top();
            pq.pop();
            ans += ch;
            if(fre > 1) pq.push({fre-1,ch});
        }
        return ans;
    }
};