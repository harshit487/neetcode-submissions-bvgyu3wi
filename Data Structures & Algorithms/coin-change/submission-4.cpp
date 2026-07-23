class Solution {
public:

     
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int>prev(amount+1,1e9);

        prev[0] = 0;

       

        for(int i = 1 ;i <= n;i++) {
            vector<int>curr(amount+1,-1);
            curr[0] = 0;
            for(int j = 1;j <= amount;j++) {
                if(j - coins[i-1] >= 0) {
                    curr[j] = min(prev[j] , 1 + curr[j-coins[i-1]]);
                }
                else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        int result = prev[amount];
        return result >= 1e9 ? -1 : result ;
    }
};