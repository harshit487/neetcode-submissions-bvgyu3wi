class Solution {
public:

    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    int r;
    int c;

    bool valid(int i,int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    void solve(vector<vector<char>>& board) {
        r = board.size();
        c = board[0].size();

        queue<pair<int,int>>q;

        for(int i = 0;i < c;i++) {
            if(board[0][i] == 'O') {
                q.push({0,i});
                board[0][i] = 'T';
            }
        }

        for(int i=0;i<c;i++) {
            if(board[r-1][i] == 'O') {
                q.push({r-1,i});
                board[r-1][i] = 'T';
            }
        }

        for(int i = 0;i < r;i++) {
            if(board[i][0] == 'O') {
                q.push({i,0});
                board[i][0] = 'T';
            }
        }

        for(int i = 0;i < r;i++) {
            if(board[i][c-1] == 'O') {
                q.push({i,c-1});
                board[i][c-1] = 'T';
            }
        }

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0;k < 4;k++) {
                if(valid(i + row[k],j + col[k]) && board[i + row[k]][j + col[k]] == 'O') {
                    q.push({i + row[k],j + col[k]});
                    board[i + row[k]][j + col[k]] = 'T';
                }
            }
        }

        for(int i = 0;i < r;i++) {
            for(int j = 0;j < c;j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'T') { 
                    board[i][j] = 'O';
                }
            }
        }
    }
};