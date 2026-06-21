class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        for(int l = 0;l<n-2;l++) {
            int i = l+1,j=n-1;
            while(i<j) {
                int sum = nums[i]+nums[j]+nums[l];
                if(sum == 0) {
                    ans.insert({nums[l],nums[i],nums[j]});
                    i++;
                    j--;
                }
                else if(sum < 0) i++;
                else j--;
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
