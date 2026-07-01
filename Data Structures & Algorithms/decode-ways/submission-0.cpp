class Solution {
public:
    vector<int> dp;
    int helper(int idx,string &s) {
        if(idx == s.size()) return 1;
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        int ans = 0;
        ans += helper(idx+1,s);
        if(idx+1<s.size()) {
            int num = stoi(s.substr(idx, 2));
            if(num >= 10 && num <= 26) {
                ans += helper(idx+2,s);
            }
        }
        return dp[idx] = ans;
    }
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return helper(0,s);
    }
};
