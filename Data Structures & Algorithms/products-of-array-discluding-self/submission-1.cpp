class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        //vector<int> pre(n,1),suff(n,1);
        vector<int> ans(n);
        int mul = 1;
        for(int i = 0;i<n;i++) {
            ans[i] = mul;
            mul *= nums[i];
        }
        mul = 1;
        for(int i = n-1;i>=0;i--) {
            ans[i] *= mul;
            mul *= nums[i];
        }
        return ans;
    }
};