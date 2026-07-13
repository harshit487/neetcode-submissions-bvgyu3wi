class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int>Indeg(n,0);

        for(auto it : pre) {

            adj[it[1]].push_back(it[0]);
            Indeg[it[0]]++;
            
        }

        queue<int>q;
        int count = 0;

        for(int i = 0;i < n;i++) {
            if(!Indeg[i]) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            count++;
            int i = q.front();
            q.pop();

            for(int j = 0;j < adj[i].size();j++) {
                Indeg[adj[i][j]]--;
                if(!Indeg[adj[i][j]]) {
                    q.push(adj[i][j]);
                }
            }
        }
        return count == n;
    }
};