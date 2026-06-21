class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        set<vector<int>> ans;
        for(int k = 0;k<n-3;k++) {
            for(int l = k+1;l<n-2;l++) {
                int i = l+1,j=n-1;
                while(i<j) {
                    long long sum = 1LL*nums[k]+nums[i]+nums[j]+nums[l];
                    if(sum == (long long)target) {
                        ans.insert({nums[k],nums[l],nums[i],nums[j]});
                        i++;
                        j--;
                    }
                    else if(sum < (long long)target) i++;
                    else j--;
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};