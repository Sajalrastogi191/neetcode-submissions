class Solution {
public:
    vector<int> dp;
    int helper(int n) {
        if(n == 2) return 1; 
        if(n == 3) return 2; 
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 2;i<=n/2;i++) {
            int ans1 = max(i,helper(i));
            int ans2 = max(n-i,helper(n-i));
            ans = max(ans,ans1*ans2);
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        dp.resize(n+1,-1);
        return helper(n);
    }
};