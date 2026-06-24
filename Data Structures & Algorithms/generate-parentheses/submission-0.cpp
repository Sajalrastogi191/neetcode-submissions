class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> set;
        if(n==1) return {"()"};
        vector<string> smallans=generateParenthesis(n-1);
        vector<string> ans;
        for(int i=0;i<smallans.size();i++) {
            for(int j=0;j<=smallans[i].size();j++) {
                string temp;
                temp = smallans[i].substr(0, j) + "()" + smallans[i].substr(j);
                set.insert(temp);
            }
        }
        ans.assign(set.begin(), set.end());
        return ans;
    }
};