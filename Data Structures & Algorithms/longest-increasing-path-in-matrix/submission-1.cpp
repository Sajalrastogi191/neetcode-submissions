class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                matrix[nr][nc] > matrix[i][j]) {
                dp[i][j] = max(dp[i][j], 1 + dfs(nr, nc, matrix));
            }
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dp.assign(n, vector<int>(m, -1));

        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        return ans;
    }
};