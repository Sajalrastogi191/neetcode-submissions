class Solution {
public:
    bool solve(int idx, int sum,vector<int>& nums,vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(idx >= nums.size() || sum <0 ) return false;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool nottake = solve(idx+1,sum,nums,dp);
        bool take = solve(idx+1,sum-nums[idx],nums,dp);
        return dp[idx][sum] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total=0;
        for(int &num:nums) total+=num; 
        if(total%2==1) return false;
        vector<vector<int>> dp(n,vector<int>((total/2)+1,-1));
        return solve(0,total/2,nums,dp);
    }
};