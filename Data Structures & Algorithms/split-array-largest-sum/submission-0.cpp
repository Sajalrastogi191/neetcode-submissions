class Solution {
public:
    bool cansplit(int total,vector<int>& nums,int k) {
        int sum = 0;
        int d = 1;
        for(auto &x:nums) {
            if(x > total) return false;
            if(sum+x > total) {
                d++;
                sum = x;
            } else {
                sum += x;
            }
        }
        return d <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(),nums.end());
        int e = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(s <= e) {
            int mid = s+(e-s)/2;
            if(cansplit(mid,nums,k)) {
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return ans;
    }
};