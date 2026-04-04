class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0,end = n-1;
        int res = INT_MAX;
        while(start <= end)
        {
            if(nums[start] < nums[end])
            {
                res = min(res,nums[start]);
                break;
            }
            int mid = start + (end - start)/2;
            res = min(res,nums[mid]);

            if(nums[mid] >= nums[start])
            {
                start = mid+1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return res;
    }
};