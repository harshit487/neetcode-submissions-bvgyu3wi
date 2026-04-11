class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        int j = 1;
        int profit = 0;


        while(j < n)
        {
            int buy = prices[i];
            int sell = prices[j];

            if(sell > buy)
            {
                profit = max(profit,(sell-buy));
                j++;
            }
            else
            {
                i = j;
                j += 1;
            }
        }
        return profit;

    }
};
