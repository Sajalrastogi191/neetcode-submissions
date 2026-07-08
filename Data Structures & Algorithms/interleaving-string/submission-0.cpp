class Solution {
public:
    vector<vector<int>> dp;
    bool helper(int i, int j,string& s1,string& s2,string &s3) {
        int idx = i+j;
        if(idx == s3.size()) {
            return i == s1.size() && j == s2.size();
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(i<s1.size() && s3[idx] == s1[i]) {
            ans |= helper(i+1,j,s1,s2,s3);
        }
        if(j<s2.size() && s3[idx] == s2[j]) {
            ans |= helper(i,j+1,s1,s2,s3);
        } 
        return dp[i][j] = ans;
    } 
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(0,0,s1,s2,s3);
    }
};