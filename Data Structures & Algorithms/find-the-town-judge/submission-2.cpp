 

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>isJudge(n+1,0);

        for(auto e : trust) {
            int i = e[0];
            int j = e[1];

            isJudge[i]--;
            isJudge[j]++;
        }

        for (int i = 1; i <= n; i++) {

            if (isJudge[i] == n - 1)

                return i;

        }
        
        return -1;
    }
};