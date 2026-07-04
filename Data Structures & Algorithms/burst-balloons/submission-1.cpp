class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i,int j,vector<int>& nums) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k = i;k<=j;k++) {
            int cost = helper(i,k-1,nums) + helper(k+1,j,nums);
            cost += (nums[i-1]*nums[k]*nums[j+1]);
            ans = max(ans,cost);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        return helper(1,nums.size()-2,nums);
    }
};
