class Solution {
public:
    void helper(int idx,int n,vector<vector<int>>& ans,vector<int>& sol,int k) {
        if(idx == n+1) {
            if(sol.size() == k) {
                ans.push_back(sol);
            }   
            return;
        }
        helper(idx+1,n,ans,sol,k);
        sol.push_back(idx);
        helper(idx+1,n,ans,sol,k);
        sol.pop_back();
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sol;
        helper(1,n,ans,sol,k);
        return ans;
    }
};