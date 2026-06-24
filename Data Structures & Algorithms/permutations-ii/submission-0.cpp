class Solution {
public:
    set<vector<int>> Helper(vector<int>& nums ,int idx) {
        if(idx==nums.size()) return {{}};
        set<vector<int>> smallans=Helper(nums,idx+1);
        set<vector<int>> ans;
        for(auto &it:smallans) {
            for(int j=0;j<=it.size();j++) {
                vector<int> temp = it;
                temp.insert(temp.begin()+j,nums[idx]);
                ans.insert(temp);
            }
        }
        return ans;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return {};
        set<vector<int>> ans =  Helper(nums,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};