class Solution {
public:
    vector<int> dp;
    int helper(int idx,vector<int>& code) {
        if(idx >= code.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int cost = code[idx];
        int cost1 = helper(idx+1,code);
        int cost2 = helper(idx+2,code);
        return dp[idx] = min(cost1,cost2)+cost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(),-1);
        return min(helper(0,cost),helper(1,cost));
    }
};
