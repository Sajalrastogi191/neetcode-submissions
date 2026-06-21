class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] != val) {
                swap(nums[i],nums[idx]);
                idx++;
                ans++;
            }
        }
        return ans;
    }
};