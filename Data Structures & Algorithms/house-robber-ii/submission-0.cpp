class Solution {
   public:
    vector<int> dp;
    int helper(int idx, vector<int> nums, int n) {
        if (idx > n) return 0;
        if (dp[idx] != -1) return dp[idx];
        int take = helper(idx + 2, nums, n) + nums[idx];
        int nottake = helper(idx + 1, nums, n);
        return dp[idx] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        dp.assign(n, -1);
        int ans1 = helper(0, nums, n - 2);

        dp.assign(n, -1);
        int ans2 = helper(1, nums, n - 1);

        return max(ans1, ans2);
    }
};
