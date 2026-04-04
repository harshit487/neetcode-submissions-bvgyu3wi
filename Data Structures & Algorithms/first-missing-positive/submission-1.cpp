class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0;i < n;i++){
            if(nums[i] <= 0 || nums[i] > n)
            {
                nums[i] = n+1;
            }

        }

        for(int i = 0;i < n;i++){
            int seat = abs(nums[i]);
            if(seat == n+1) continue;

            else
            {
                if(nums[seat-1] > 0)
                {
                    nums[seat-1] = -nums[seat-1];
                }
                
            }
        }

        for(int i = 0;i < n;i++)
        {
            if(nums[i] > 0)
            {
                return i+1;
            }
        }

        return n+1;
    }
};