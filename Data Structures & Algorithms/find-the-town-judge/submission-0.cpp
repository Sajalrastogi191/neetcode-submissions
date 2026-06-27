class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(auto it:trust) {
            mat[it[0]-1][it[1]-1] = 1;
        }
        vector<int> q;
        for(int i = 0;i<n;i++) {
            int cnt = 0;
            for(int j = 0;j<n;j++) {
                if(mat[i][j]) cnt = 1;
            }
            if(cnt == 0) q.push_back(i);
        }
        for(auto &x:q) {
            int cnt = 0;
            for(int j = 0;j<n;j++) {
                if(x == j)  continue;
                if(mat[j][x]) cnt++;
            }
            if(cnt == n-1) return x+1;
        }
        return -1;
    }
};