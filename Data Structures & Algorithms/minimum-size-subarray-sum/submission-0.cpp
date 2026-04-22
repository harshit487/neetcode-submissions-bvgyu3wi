class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int first = 0;
        int second = 0;
        int n = nums.size();
        int length = INT_MAX;

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i = 1;i < n;i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }


        while(second < n)
        {
            int t;
            if(first == 0)
            {
                t = 0;
            }
            else
            {
                t = prefix[first-1];
            }

            if((prefix[second] - t) >= target)
            {
                length = min(length , (second - first + 1));
                first++;
            }
            else
            {
                second++;
            }

           
        }

         return length == INT_MAX ? 0 : length;

    }
};