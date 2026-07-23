class Solution {
public:

    int minCoin(vector<int>& coins , int index , int amount) {

        if(amount == 0) return 0;
        if(index < 0 || amount < 0) return 1e9;

        return min(minCoin(coins,index-1,amount) ,1 + minCoin(coins , index , amount - coins[index]));
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        int result = minCoin(coins , n - 1 , amount);
        return result >= 1e9 ? -1 : result ;
    }
};