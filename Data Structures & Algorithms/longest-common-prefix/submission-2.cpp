class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str1 = strs[0];
        for(int i = 1;i<strs.size();i++) {
            string tmp = "";
            string str2 = strs[i];
            int n = min(str1.size(),str2.size());
            for(int j = 0;j<n;j++) {
                if(str1[j] == str2[j]) tmp.push_back(str1[j]);
                else break;
            }
            str1 = tmp;
        }
        return str1;
    }
};