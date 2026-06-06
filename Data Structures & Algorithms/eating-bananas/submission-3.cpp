class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans = r;

        while(l<r)
        {
            int m = l + (r-l)/2;
            int total_time = 0;

            for(int p:piles)
            {
                total_time += p/m;
                if(p % m != 0) total_time++;
            }
            if(total_time <= h)
            {
                ans = m;
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};
