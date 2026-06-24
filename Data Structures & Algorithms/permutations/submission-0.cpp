class Solution {
public:
    vector<vector<int>> Helper(vector<int>& nums ,int idx) {
        if(idx==nums.size()) return {{}};
        vector<vector<int>> smallans=Helper(nums,idx+1);
        vector<vector<int>> ans;
        for(int i=0;i<smallans.size();i++) {
            for(int j=0;j<=smallans[i].size();j++) {
                vector<int> temp = smallans[i];
                temp.insert(temp.begin()+j,nums[idx]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return {};
        return Helper(nums,0);
    }
};