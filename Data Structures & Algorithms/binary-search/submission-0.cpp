class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0,end = n-1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end--;
            else start++;
        }
        return -1;
    }
};