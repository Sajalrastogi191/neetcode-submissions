class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> um;
        for(int i = 0;i<s.size();i++) {
            um[s[i]] = i;
        }
        vector<int> ans;
        int maxreach = 0;
        int idx = 0;
        for(int i = 0;i<s.size();i++) {
            maxreach = max(maxreach,um[s[i]]);
            if(i == maxreach) {
                ans.push_back(i-idx+1);
                idx = i+1;
            }
        }
        return ans;
    }
};
