class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int r = 0;
        int l = 0;
        int ans = 0;
        unordered_map<char,int> um;
        while(r < n) {
            um[s[r]]++;
            while(um[s[r]] >= 2) {
                um[s[l]]--;
                if(um[s[l]] == 0) um.erase(s[l]);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
