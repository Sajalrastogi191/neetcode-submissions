class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i,int j,string s, string t) {
        if(i == s.size() && j != t.size()) return 0;
        if(i == s.size() && j == t.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) {
            return dp[i][j] = helper(i+1,j+1,s,t)+helper(i+1,j,s,t);
        }
        return dp[i][j] = helper(i+1,j,s,t);
    }
    int numDistinct(string s, string t) {
        dp.assign(s.size()+1,vector<int>(t.size()+1,-1));
        return helper(0,0,s,t);
    }
};