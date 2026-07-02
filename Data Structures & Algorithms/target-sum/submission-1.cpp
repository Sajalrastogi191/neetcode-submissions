class Solution {
public:
    vector<vector<int>> dp;
    int offset;
    int helper(int idx,vector<int>& nums,int target) {
        if (target < -offset || target > offset) return 0;
        if(idx == nums.size()) {
            return target == 0;
        }
        if(dp[idx][target+offset] != -1) return dp[idx][target+offset];
        int add = helper(idx+1,nums,target-nums[idx]);
        int sub = helper(idx+1,nums,target+nums[idx]);
        return dp[idx][target+offset] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if (abs(target) > total) return 0;

        offset = total;
        dp.resize(nums.size(),vector<int>(2*total+1,-1));
        return helper(0,nums,target);
    }
};
