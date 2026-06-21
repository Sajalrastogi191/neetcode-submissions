class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int r = 0;
        int l = 0;
        int sum = 0;
        while(r < n) {
            sum += nums[r];
            if(sum >= target) {
                while(sum >= target) {
                    sum -= nums[l];
                    l++;
                }
                ans = min(ans,r-l+1);
            }
            r++;
        }
        return (ans == INT_MAX)? 0:ans+1;
    }
};