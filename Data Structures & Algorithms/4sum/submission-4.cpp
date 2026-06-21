class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        for(int k = 0;k<n-3;k++) {
            for(int l = k+1;l<n-2;l++) {
                if(k > 0 && nums[k] == nums[k-1]) continue;
                if(l > k+1 && nums[l] == nums[l-1]) continue;
                int i = l+1,j=n-1;
                while(i<j) {
                    
                    long long sum = 1LL*nums[k]+nums[i]+nums[j]+nums[l];
                    if(sum == (long long)target) {
                        ans.push_back({nums[k],nums[l],nums[i],nums[j]});
                        i++;
                        j--;
                        while(i < j && nums[i] == nums[i-1]) i++;
                        while(i < j && nums[j] == nums[j+1]) j--;
                    }
                    else if(sum < (long long)target) i++;
                    else j--;
                }
            }
        }
        return ans;
    }
};