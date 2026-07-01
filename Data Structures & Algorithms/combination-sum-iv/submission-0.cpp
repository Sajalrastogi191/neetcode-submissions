class Solution {
public:
    vector<int> dp;

    int helper(vector<int>& nums, int target) {
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];

        long long ans = 0;

        for (int x : nums) {
            if (x <= target) {
                ans += helper(nums, target - x);
            }
        }

        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return helper(nums, target);
    }
};