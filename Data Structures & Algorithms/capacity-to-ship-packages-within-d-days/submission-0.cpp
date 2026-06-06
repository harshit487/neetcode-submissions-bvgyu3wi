class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(),weights.end());

        int end = 0;
        for(int w : weights)
        {
            end += w;
        }
        int ans = end;
        while(start < end)
        {
            int mid = start + (end - start)/2;
            int sum = 0;
            int day = 1;
            for(int w : weights)
            {
                sum += w;
                if(sum > mid)
                {
                    day++;
                    sum = w;
                }
            }

            if(day <= days)
            {
                ans = mid;
                end = mid;
            }
            else start = mid+1;
        }
        return ans;
    }
};