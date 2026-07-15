class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int>dp(3);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = min(dp[1] + cost[1] , dp[0] + cost[0]);

        for(int i = 3;i <= n;i++) {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = min(dp[1] + cost[i-1],dp[0] + cost[i-2]); 
            
        }

        return dp[2];
    }
};