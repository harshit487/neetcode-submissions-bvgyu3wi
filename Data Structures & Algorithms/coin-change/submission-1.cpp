class Solution {
public:

    int minCoin(vector<int>& coins , int index , int amount , vector<vector<int>>& dp) {

        if(amount == 0) return 0;
        if(index < 0 || amount < 0) return 1e9;
        if(dp[index][amount] != -1) return dp[index][amount];

        return dp[index][amount] = min(minCoin(coins,index-1,amount , dp) ,1 + minCoin(coins , index , amount - coins[index] , dp));
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int result = minCoin(coins , n - 1 , amount , dp);
        return result >= 1e9 ? -1 : result ;
    }
};