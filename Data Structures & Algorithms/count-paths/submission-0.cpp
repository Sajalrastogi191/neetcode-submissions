class Solution {
public:
    int uniquePaths(int m, int n) {
        const int MOD = 2*pow(10,9);
        vector<vector<long long>> dp(m, vector<long long>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
        return dp[m - 1][n - 1];
    }
};