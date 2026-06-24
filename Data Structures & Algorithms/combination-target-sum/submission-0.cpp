class Solution {
public:
    void helper(int idx, vector<int>& candidates, int target,vector<int>& sol,vector<vector<int>>& ans) {
        if(idx == candidates.size()) {
            if(target == 0) {
                ans.push_back(sol);
                //sol.pop_back();
            }
            return;
        }
        if(idx < candidates.size() && candidates[idx] <= target) {
            sol.push_back(candidates[idx]);
            helper(idx,candidates,target-candidates[idx],sol,ans);
            sol.pop_back();
        }
        helper(idx+1,candidates,target,sol,ans);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        vector<vector<int>> ans;
        helper(0,candidates,target,sol,ans);
        return ans;
    }
};