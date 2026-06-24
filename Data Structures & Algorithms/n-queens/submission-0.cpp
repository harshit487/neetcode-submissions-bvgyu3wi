class Solution {
public:


    bool check(int n , vector<string>& board,int i, int j)
    {
        int row = i;
        int col = j;
        while(row > -1 && col > -1)
        {
            if(board[row][col] == 'Q') return 0;
            row--;
            col--;
        }
        col = j;
        row = i;

        while(row > -1 && col < n)
        {
            if(board[row][col] == 'Q') return 0;
            row--;
            col++;
        }
        return 1;
    }

    void solve(int row,int n,vector<vector<string>>& ans,vector<string>& board, vector<bool>& cols)
    {
        //base
        if(row == n) 
        {
            ans.push_back(board);
            return;
        }

        for(int j = 0;j < n;j++)
        {
            if(cols[j]==0 && check(n,board,row,j))
            {
                board[row][j] = 'Q';
                cols[j] = 1;
                solve(row+1,n,ans,board,cols);
                board[row][j] = '.';
                cols[j] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                board[i].push_back('.');
            }
        }

        vector<bool>cols(n,0);

        solve(0,n,ans,board,cols);
        return ans;
    }
};
