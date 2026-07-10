class Solution {
public:

    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    int m , n;

    void dfs(vector<vector<int>>& heights ,int i , int j,int prev , vector<vector<bool>>& visited) {
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(heights[i][j] < prev || visited[i][j]) return;

        visited[i][j] = true;
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            dfs(heights,i_,j_,heights[i][j],visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> ans;

        vector<vector<bool>> pv(m,vector<bool>(n,false));
        vector<vector<bool>> av(m,vector<bool>(n,false));

        for(int i = 0;i < n;i++) {
            dfs(heights,0,i,INT_MIN,pv);
            dfs(heights,m-1,i,INT_MIN,av);
        }        

        for(int i=0;i<m;i++) {
            dfs(heights,i,0,INT_MIN,pv);
            dfs(heights,i,n-1,INT_MIN,av);
        }
        
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(pv[i][j] && av[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
