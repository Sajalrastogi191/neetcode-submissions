class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums,int idx) {
        if(idx == nums.size()) return {{}};

        vector<vector<int>> smallans=helper(nums,idx+1);
        vector<vector<int>> ans=smallans;
        for(int i=0;i<smallans.size();i++) {
            vector<int> temp;
            temp.push_back(nums[idx]);
            temp.insert(temp.end(),smallans[i].begin(),smallans[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans= helper(nums,0);
        set<vector<int>> uniqueSubsets(ans.begin(), ans.end());
        return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
    }
};