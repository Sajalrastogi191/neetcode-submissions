class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        for (int l = 0; l < n * m; l++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[i][j] > matrix[nr][nc]) {
                            dp[i][j] = max(dp[i][j], 1 + dp[nr][nc]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
