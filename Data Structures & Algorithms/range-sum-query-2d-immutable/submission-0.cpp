class NumMatrix {
public:
    vector<vector<int>> pre;
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        pre.resize(n,vector<int>(m,0));
        pre[0][0] = matrix[0][0];
        for(int i = 1;i<n;i++) {
            pre[i][0] = pre[i-1][0] + matrix[i][0];
        }
        for(int i = 1;i<m;i++) {
            pre[0][i] = pre[0][i-1] + matrix[0][i];
        }
        for(int i = 1;i<n;i++) {
            for(int j = 1;j<m;j++) {
                pre[i][j] = (pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1])+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1 = (row1-1>=0 && col2 < m)? pre[row1-1][col2]:0; //righttop
        int sum2 = (row1-1>=0 && col1-1 >=0)? pre[row1-1][col1-1]:0; //lefttop
        int sum3 = (row2<n && col1-1 >=0)? pre[row2][col1-1]:0; // bottomleft
        int presum = (row2 < n && col2 < m)? pre[row2][col2]:0;
        return presum-(sum1+sum3)+sum2;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */