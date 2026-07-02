class Solution {
public:
    vector<vector<int>> dp;
    int helper(int idx,vector<int>& coins,int amount) {
        if(idx == coins.size()) {
            return amount == 0;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int nottake = helper(idx+1,coins,amount);
        int take = (coins[idx] <= amount)? helper(idx,coins,amount-coins[idx]):0;
        return dp[idx][amount] = nottake+take;
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        return helper(0,coins,amount);
    }
};
