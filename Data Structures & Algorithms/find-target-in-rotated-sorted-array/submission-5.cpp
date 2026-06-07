class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while(s <= e)
        {
            int mid = s + (e - s)/2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] >= nums[0])
            {
                if(nums[s] <= target && nums[mid] >= target)
                {
                   e = mid - 1;

                }
                else  s = mid + 1;
            }
            else 
            {
                if(target > nums[mid] && target <= nums[e])
                {
                   s = mid + 1;
                }
                else e = mid - 1;
            }
        }
        return -1;
    }
};