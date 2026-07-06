class Solution {
public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    int r ;
    int c ;

    void dfs(vector<vector<int>>& grid ,int i,int j,int& perimeter)
    {
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0)
        {
            perimeter++;
            return;
        }

        if(grid[i][j] == -1) return;

        grid[i][j] = -1;
        dfs(grid,i-1,j,perimeter);
        dfs(grid,i+1,j,perimeter);
        dfs(grid,i,j-1,perimeter);
        dfs(grid,i,j+1,perimeter);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int perimeter = 0;

 

        for(int i=0;i<r;i++) {
            for(int j = 0;j<c;j++) {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j,perimeter);
                    return perimeter;
                }
            }
        }

    return -1;
        
    }
};