class Solution {
public:

 

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1,0);
        prev[0] = 1;

        for(int i = 1;i <= n;i++) {
            vector<int>curr(amount+1,0);
            curr[0] = 1;
            for(int j = 1;j <= amount;j++) {
                if(j - coins[i-1] >= 0) {
                    curr[j] = prev[j] + curr[j - coins[i-1]];
                }
                else {
                    curr[j] = prev[j];
                }
            }    
            prev = curr;
        }

        return prev[amount];
        
    }
};
