class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l =0,r = 0;
        int ans = 0;
        int maximumfreq = 0;
        unordered_map<char,int> um;
        while(r<n) {
            char ch = s[r];
            um[ch]++;
            maximumfreq = max(maximumfreq,um[ch]);
            if(((r-l+1)-maximumfreq) > k) {
                while(((r-l+1)-maximumfreq) > k) {
                    um[s[l]]--;
                    if(um[s[l]] == 0) um.erase(s[l]);
                    l++;
                }
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
