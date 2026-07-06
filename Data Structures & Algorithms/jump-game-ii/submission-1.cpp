class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxreach = nums[0];
        int currentend = 0;
        int ans = 0;
        for(int i = 0;i<n-1;i++) {
            maxreach = max(maxreach,i+nums[i]);
            if(i == currentend) {
                ans++;
                currentend = maxreach;
            }
        }
        return ans;
    }
};
