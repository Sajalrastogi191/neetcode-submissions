class Solution {
public:
    void helper(int idx,unordered_map<string,int> &um,string &s,vector<string> &sol,vector<string> &ans) {
        if(idx == s.size()) {
            string tmp;
            for(auto &it:sol) {
                tmp.insert(tmp.end(),it.begin(),it.end());
                tmp.push_back(' ');
            }
            tmp.pop_back();
            ans.push_back(tmp);
            return;
        }
        for(int i = idx;i<s.size();i++) {
            string tmp = s.substr(idx,i-idx+1);
            if(um.find(tmp) != um.end()) {
                sol.push_back(tmp);
                helper(i+1,um,s,sol,ans);
                sol.pop_back();
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        vector<string> sol;
        unordered_map<string,int> um;
        for(auto &it:wordDict) {
            um[it]++;
        }
        helper(0,um,s,sol,ans);
        return ans;
    }
};