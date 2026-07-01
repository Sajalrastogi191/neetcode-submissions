class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xornum = 0;
        for(int i = 1;i <= n;i++) {
            xornum ^= i;
        }
        for(int i = 0;i < n;i++) {
            xornum ^= nums[i];
        }
        return xornum;
    }
};
