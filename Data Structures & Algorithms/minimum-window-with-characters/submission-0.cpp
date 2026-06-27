class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int l = 0,r =0;
        unordered_map<char,int> um1;
        unordered_map<char,int> um2;

        for(auto x:t) um2[x]++;
        int required = um2.size();
        int formed = 0;

        int len = INT_MAX;
        int idx = -1;

        while(r<n) {
            um1[s[r]]++;
            if(um2.count(s[r]) && um2[s[r]] == um1[s[r]]) formed++;
            if(formed == required) {
                while(formed == required) {
                    if(r-l+1 < len) {
                        idx = l;
                        len = r-l+1;
                    }
                    um1[s[l]]--;
                    if(um2.count(s[l]) && um1[s[l]] < um2[s[l]]) formed--; 
                    l++;
                }
            }
            r++;
        }
        if(idx == -1) return "";
        return s.substr(idx,len);
    }
};