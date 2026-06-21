class Solution {
public:
    int helper(int idx,vector<int>& prices,int canbuy,vector<vector<int>>& dp) {
        if(idx == prices.size()) return 0;
        if(dp[idx][canbuy] != -1) return dp[idx][canbuy];
        int profit = 0;
        if(canbuy) {
            int take = helper(idx+1,prices,0,dp) - prices[idx];
            int nottake = helper(idx+1,prices,1,dp);
            profit = max(take,nottake);
        } else {
            int take = helper(idx+1,prices,1,dp) + prices[idx];
            int nottake = helper(idx+1,prices,0,dp);
            profit = max(take,nottake);
        }
        return dp[idx][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,prices,1,dp);
    }
};