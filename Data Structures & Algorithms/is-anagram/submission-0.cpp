class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> um1;
        unordered_map<char,int> um2;
        for(char &ch:s) um1[ch]++;
        for(char &ch:t) um2[ch]++;

        for(auto& it:um1) {
            if(um2[it.first] != it.second) return false;
        }
        return true;
    }
};
