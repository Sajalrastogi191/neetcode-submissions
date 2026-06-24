class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});
        
        string ans = "";
        while(!pq.empty()) {
            auto [fre,ch] = pq.top();
            pq.pop();
            int n = ans.size();
            if(n>=2 && ans[n-1] == ans[n-2] && ans[n-1] == ch) {
                if(pq.empty()) break;
                auto [fre2,ch2]= pq.top();
                pq.pop();
                ans += ch2;
                fre2--;
                if(fre2 > 0) pq.push({fre2,ch2});
                pq.push({fre,ch});
            }
            else {
                ans += ch;
                fre--;
                if(fre > 0) pq.push({fre,ch});
            }
        }
        return ans;
    }
};