class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxreach = 0;
        for(int i = 0;i<n;i++) {
            if(maxreach >= n-1) return true;
            int jump = i+nums[i];
            maxreach = max(maxreach,jump);
            if(i == maxreach) return false;
        }
        return true;
    }
};
