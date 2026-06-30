class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++) {            
            for(int x:coins) {
                if(i-x>=0) dp[i] = min(dp[i],dp[i-x]);
            }
            dp[i]++;
        }
        return (dp[amount]==INT_MAX)? -1:dp[amount];
    }
};