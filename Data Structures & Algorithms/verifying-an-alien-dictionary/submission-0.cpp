class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> um;
        for(int i = 0;i<order.size();i++) {
            um[order[i]] = i;
        }
        for(int i = 1;i<words.size();i++) {
            string word1 = words[i-1];
            string word2 = words[i];
            int j = 0;
            for(j = 0;j<min(word1.size(),word2.size());j++) {
                if(word1[j] == word2[j]) continue;
                if(um[word1[j]] < um[word2[j]]) break;
                if(um[word1[j]] > um[word2[j]]) return false;
            }
            if(j == min(word1.size(),word2.size()) && word1.size() > word2.size()) return false;
        }
        return true;
    }
};