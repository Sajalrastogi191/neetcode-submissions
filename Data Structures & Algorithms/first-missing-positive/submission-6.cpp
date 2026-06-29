class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool is1 = false;
        for(int &x:nums) {
            if(x == 1) is1 = true;
            if(x <= 0 || x>n) {
                x = 1;
            }
        }
        if(!is1) return 1;
        for(int i = 0;i<n;i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0) nums[idx] = (-1)*nums[idx];
        }
        for(int i = 0;i<n;i++) {
            if(nums[i] > 0) return i+1;
        }
        return n+1;
    }
};