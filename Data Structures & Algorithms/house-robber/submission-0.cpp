class Solution {
public:
    vector<int> dp;
    int helper(int idx,vector<int> nums) {
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = helper(idx+2,nums)+nums[idx];
        int nottake = helper(idx+1,nums);
        return dp[idx] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return helper(0,nums);
    }
};
