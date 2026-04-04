class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int n = piles.size();
         int start = 1 ,end = 0;
         int ans;

         for(int i = 0 ;i < n;i++)
         {
            end = max(end,piles[i]);
         }

         while(start <= end)
         {
            int time = 0;
            int mid = start + (end - start)/2;
            for(int i = 0;i < n;i++)
            {
                time += piles[i] / mid;
                if(piles[i] % mid != 0)
                {
                    time++;
                }
            }
            if(time <= h)
            {
                ans = mid;
                end = mid-1;
            }
            else 
            {
                start = mid + 1;
            }
         }

         return ans;
    }
};