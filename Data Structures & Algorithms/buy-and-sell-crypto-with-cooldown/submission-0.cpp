class Solution {
public:
    int helper(int idx,vector<int>& prices,int buy,vector<vector<int>>& dp) {
        if(idx >= prices.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit=0;
        if(buy) {
            profit = max(helper(idx+1,prices,1,dp),helper(idx+1,prices,0,dp) - prices[idx]);
        } else {
            profit = max(helper(idx+1,prices,0,dp),helper(idx+2,prices,1,dp) + prices[idx]);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(0,prices,1,dp);
    }
};