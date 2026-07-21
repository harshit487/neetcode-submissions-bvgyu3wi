class Solution {
public:

    int find(vector<int>& coins,int index , int amount , vector<vector<int>>& dp) {
        if(amount == 0) return 1;
        if(index < 0 || amount < 0) return 0;
        if(dp[index][amount] != -1) return dp[index][amount];
        
        return dp[index][amount] = find(coins,index-1,amount,dp) + find(coins,index,amount - coins[index],dp);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return find(coins,n-1,amount,dp);
    }
};
