class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int r=n-1;
        int lmax=0;
        int rmax=0;
        int ans=0;
        while(l<=r){
            lmax=max(lmax,nums[l]);
            rmax=max(rmax,nums[r]);
            if(lmax<rmax){
                ans += lmax-nums[l];
                l++;
            }
            else{
                ans += rmax-nums[r];
                r--;
            }
        }
        return ans;
    }
};