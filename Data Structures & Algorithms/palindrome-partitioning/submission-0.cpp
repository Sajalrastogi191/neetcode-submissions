class Solution {
public:
    bool ispalindrome(string &s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(int idx,string &s,vector<string> &sol,vector<vector<string>> &ans) {
        if(idx == s.size()) {
            ans.push_back(sol);
            return;
        }
        for(int i = idx;i<=s.size();i++) {
            string tmp = s.substr(idx,i-idx+1);
            if(ispalindrome(tmp)) {
                sol.push_back(tmp);
                helper(i+1,s,sol,ans);
                sol.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sol;
        helper(0,s,sol,ans);
        return ans;
    }
};
