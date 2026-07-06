class Solution {
public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    int r;
    int c;


    bool valid(int x , int y)
    {
        return x>=0 && x<r && y>=0 && y<c;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>>q;

        for(int i =0;i<r;i++) {
            for(int j = 0;j<c;j++) {
                if(grid[i][j] == 1)
                {
                q.push({i,j});
                grid[i][j] = -1;
                break;
                }
            }
         }

        int perimeter = 0;

         while(!q.empty())
         {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k=0;k<4;k++) {
                if(!valid(i+row[k] , j+col[k]))
                    perimeter++;
                else
                {
                    if(grid[i+row[k]][j+col[k]] == 0)
                        perimeter++;
                    else if(grid[i+row[k]][j+col[k]] == 1)
                    {
                        grid[i+row[k]][j+col[k]] = -1;
                        q.push({i+row[k],j+col[k]});
                    }
                }
            } 
         }
         return perimeter;
    }
};