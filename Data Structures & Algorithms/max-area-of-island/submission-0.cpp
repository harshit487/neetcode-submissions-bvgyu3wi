class Solution {
public:

    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    int r , c;

    bool valid(int i , int j) {
        return i >= 0 && j >= 0 && i < r && j < c;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>>q;

        int ans = INT_MIN;
        
        for(int i = 0;i < r;i++) {
            for(int j = 0;j < c;j++) {
                if(grid[i][j] == 1) {
                    int area = 1;
                    ans = max(ans,area);
                    grid[i][j] = 0;
                    q.push({i,j});

                    while(!q.empty()) {
                        int i_ = q.front().first;
                        int j_ = q.front().second;
                        q.pop();

                        for(int k = 0;k<4;k++) {
                            if(valid(i_ + row[k],j_ + col[k]) && grid[i_ + row[k]][j_ + col[k]] == 1) {
                                grid[i_ + row[k]][j_ + col[k]] = 0;
                                area++;
                                q.push({i_ + row[k],j_ + col[k]});
                                ans = max(ans,area);
                            }
                        }
                    }
                }
            }
        }
        return ans < 1 ? 0 : ans;
    }
};