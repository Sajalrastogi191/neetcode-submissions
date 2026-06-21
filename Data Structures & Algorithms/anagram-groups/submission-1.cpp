class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(auto &str:strs) {
            string tmp = str;
            sort(tmp.begin(),tmp.end());
            um[tmp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto &it:um) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
