class Solution {
public:
    vector<vector<int>> dp;
    int helper(int x,int n) {
        if((x*x) == n) return 1;
        if((x*x) > n) return INT_MAX-1;
        if (dp[x][n] != -1) return dp[x][n];
        int nottake = helper(x+1,n);
        int take = helper(x,n-(x*x))+1;
        return dp[x][n] = min(nottake,take);
    } 
    int numSquares(int n) {
        dp.assign(sqrt(n) + 2, vector<int>(n + 1, -1));
        return helper(1,n);
    }
};