class Solution {
public:
    vector<int> dp;

    int helper(int i, vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(i >= n) return 0;

        if(dp[i] != INT_MIN) return dp[i];

        int take = 0;
        int ans = INT_MIN;

        for(int k = 0; k < 3 && i + k < n; k++) {
            take += stoneValue[i + k];
            ans = max(ans, take - helper(i + k + 1, stoneValue));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int res = helper(0, stoneValue);

        if(res > 0) return "Alice";
        if(res < 0) return "Bob";
        return "Tie";
    }
};