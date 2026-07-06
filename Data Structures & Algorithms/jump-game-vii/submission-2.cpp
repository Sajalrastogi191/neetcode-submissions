class Solution {
public:
    vector<int> dp;
    bool helper(int idx,string& s,int l,int r) {
        if(idx == s.size()-1) {
            return true;
        }
        if(dp[idx] != -1) return dp[idx];
        for(int i = idx+l;i<=idx+r && i < s.size();i++) {
            if(s[i] == '0' && helper(i,s,l,r)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        dp.assign(s.size(), -1);
        return helper(0,s,minJump,maxJump);
    }
};