class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n,0);
        dp[n-1] = true;
        for(int idx = n-2;idx>=0;idx--) {
            for(int i = idx+minJump;i<=idx+maxJump && i < s.size();i++) {
                if(s[i] == '0' && dp[i]) dp[idx] = true;
            }
        }
        return dp[0];
    }
};