class Solution {
public:
    int tribonacci(int n) {
        vector<int>dp(4);
        if(n <= 1) return n;
        if(n == 2) return 1;

        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;

        for(int i = 3;i <= n;i++) {
             dp[0] = dp[1];
             dp[1] = dp[2];
             dp[2] = dp[3];
             dp[3] = dp[0] + dp[1] + dp[3];
        }
        return dp[3];
    }
};