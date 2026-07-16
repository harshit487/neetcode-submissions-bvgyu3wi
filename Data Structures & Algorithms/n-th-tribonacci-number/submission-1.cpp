class Solution {
public:

    int tb(int n , vector<int>& dp){
        if(n <= 1) return n;
        if(n == 2) return 1;

        if(dp[n] != -1) return dp[n];
        return dp[n] = tb(n-1 , dp) + tb(n-2 , dp) + tb(n-3 , dp);
    }

    int tribonacci(int n) {
         vector<int>dp(n+1,-1);
         return tb(n,dp);
    }
};                                                  