class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int start = *max_element(nums.begin(),nums.end());
        int end = 0;
        int ans = 0;
        for(int x : nums)
        {
            end += x;
        }

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            int count = 1;
            int current = 0;

            for(int x : nums)
            {
                current += x;
                if(current > mid)
                {
                    count++;
                    current = x;
                }
                
            }

            if(count <= k)
            {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};