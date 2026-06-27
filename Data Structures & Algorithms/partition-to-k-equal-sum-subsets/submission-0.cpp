class Solution {
public:
    bool dfs(vector<int>& nums,vector<int> &sides,int idx, int length, int k) {
        if(idx == nums.size()) {
            return true;
        }
        for(int i = 0;i<k;i++) {
            if(sides[i] + nums[idx] <= length) {
                sides[i] += nums[idx];
                if(dfs(nums,sides,idx+1,length,k)) {
                    return true;
                }
                sides[i] -= nums[idx];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalLength = accumulate(nums.begin(), nums.end(), 0);
        if(totalLength % k != 0) return false;

        int length = totalLength / k;
        vector<int> sides(k, 0);
        sort(nums.rbegin(), nums.rend());

        return dfs(nums, sides, 0, length,k);
    }
};