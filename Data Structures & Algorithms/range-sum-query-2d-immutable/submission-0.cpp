class NumMatrix {
public:

    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
       
        prefix.assign(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                int top = (i>0) ? prefix[i-1][j] : 0;
                int left = (j>0) ? prefix[i][j-1] : 0;
                int top_left = (i>0 && j>0) ? prefix[i-1][j-1] : 0;

                prefix[i][j] = matrix[i][j] + top + left - top_left;
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefix[row2][col2];
        int top = (row1>0) ? prefix[row1-1][col2] : 0;
        int left = (col1>0) ? prefix[row2][col1-1] : 0;
        int top_left = (col1 > 0 && row1 >0) ? prefix[row1-1][col1-1] : 0;

        int ans = total - top - left + top_left;
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */