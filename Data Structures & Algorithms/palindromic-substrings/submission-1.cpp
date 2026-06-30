class Solution {
public:
    vector<vector<int>> dp;
    bool ispalindrome(int l,int r,string &s) {
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int helper(int l,int r,string& s) {
        if(l == r) return 1;
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = ispalindrome(l,r,s)? 1:0;
        ans += helper(l+1,r,s);
        ans += helper(l,r-1,s);
        ans -= helper(l + 1, r - 1, s);
        return dp[l][r] = ans;
    }
    int countSubstrings(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        return helper(0,s.size()-1,s);
    }
};
