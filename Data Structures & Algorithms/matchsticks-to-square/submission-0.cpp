class Solution {
public:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int idx, int length) {
        if(idx == matchsticks.size()) {
            return true;
        }
        for(int i = 0;i<4;i++) {
            if(sides[i] + matchsticks[idx] <= length) {
                sides[i] += matchsticks[idx];
                if(dfs(matchsticks,sides,idx+1,length)) {
                    return true;
                }
                sides[i] -= matchsticks[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int totalLength = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(totalLength % 4 != 0) return false;

        int length = totalLength / 4;
        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());

        return dfs(matchsticks, sides, 0, length);
    }
};