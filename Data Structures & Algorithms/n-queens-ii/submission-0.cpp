class Solution {
public:

    void solve(int n , int row ,vector<string>& board,vector<bool>& cols,vector<bool>& left,vector<bool>& right,int& total)
    {
        if(row == n)
        {
            total++;
            return;
        }
        for(int j = 0;j < n;j++)
        {
            if(cols[j] == 0 && right[row + j] == 0 && left[(n-1) + (j-row)] == 0)
            {
                board[row][j] = 'Q';
                cols[j] = 1;
                right[row+j] = 1;
                left[(n-1)+(j-row)] = 1;
                solve(n,row+1,board,cols,left,right,total);
                board[row][j] = '.';
                cols[j] = 0;
                right[row+j] = 0;
                left[(n-1)+(j-row)] = 0;

            }
        }
    }

    int totalNQueens(int n) {
        vector<string>board(n);

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                board[i].push_back('.');
            }
        }       

        vector<bool>cols(n,0);
        vector<bool>left(2*n-1,0);
        vector<bool>right(2*n-1);

        int total = 0;
        solve(n,0,board,cols,left,right,total);
        return total;
 }
};