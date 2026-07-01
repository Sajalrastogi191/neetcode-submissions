class Solution {
private:
    bool wordBreak(string s, unordered_set<string> &set, int start){
        if(start == s.size()){
            return true;
        }
        for(int i=start; i<s.size(); i++){
            if(set.count(s.substr(start, i+1-start)) && wordBreak(s, set, i+1)){
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreak(s, set, 0);*/
        int n = s.size();
        vector<int> dp(n+1,false);
        dp[0] = true;

        for(int i=1;i<=n;i++) {
            for(string& w : wordDict) {
                int start = i-w.size();
                if(start >=0 && dp[start] && s.substr(start,w.size()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};