class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x2 = matrix.size() - 1, y2 = matrix[0].size() - 1;
        int x1 = 0, y1 = 0;
        vector<int> ans;
        while (x1 <= x2 && y1 <= y2) {
            vector<int> tmp;
            for (int i = y1; i <= y2; i++) {
                tmp.push_back(matrix[x1][i]);
            }
            x1++;
            for (int i = x1; i <= x2; i++) {
                tmp.push_back(matrix[i][y2]);
            }
            y2--;
            if (x1 <= x2) {
                for (int i = y2; i >= y1; i--) {
                    tmp.push_back(matrix[x2][i]);
                }
                x2--;
            }
            if (y1 <= y2) {
                for (int i = x2; i >= x1; i--) {
                    tmp.push_back(matrix[i][y1]);
                }
                y1++;
            }
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        return ans;
    }
};
