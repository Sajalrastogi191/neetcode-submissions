class Solution {
public:
    void helper(int i,vector<int>& nums,int& ans,int &sol) {
        if(i == nums.size()) {
            ans += sol;
            return;
        }
        
        helper(i+1,nums,ans,sol);
        sol ^= nums[i];
        helper(i+1,nums,ans,sol);
        sol ^= nums[i];
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int sol = 0;
        helper(0,nums,ans,sol);
        return ans;
    }
};