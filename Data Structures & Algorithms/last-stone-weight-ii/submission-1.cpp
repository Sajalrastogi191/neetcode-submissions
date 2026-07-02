class Solution {
public:
    vector<vector<int>> dp;
    int total;

    int helper(int idx, int currSum, vector<int>& stones) {
        if (idx == stones.size()) {
            return abs(total - 2 * currSum);
        }

        if (dp[idx][currSum] != -1)
            return dp[idx][currSum];

        int take = helper(idx + 1, currSum + stones[idx], stones);
        int notTake = helper(idx + 1, currSum, stones);

        return dp[idx][currSum] = min(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {
        total = 0;
        for (int x : stones)
            total += x;

        dp.assign(stones.size(), vector<int>(total + 1, -1));

        return helper(0, 0, stones);
    }
};