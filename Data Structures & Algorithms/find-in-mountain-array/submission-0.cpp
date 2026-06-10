/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {

int binary_search(int end , MountainArray &mountainArr , int target)
{
    int start = 0;

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(mountainArr.get(mid) == target) return mid;
        else if(mountainArr.get(mid) > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int rev_bs(int peak , MountainArray &mountainArr , int target)
{
    int start = peak + 1;
    int end = mountainArr.length() - 1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(mountainArr.get(mid) == target) return mid;

        else if(mountainArr.get(mid) > target) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int n = mountainArr.length();
        int start = 0;
        int end = n-1;
        
        int peak;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(mountainArr.get(mid) > mountainArr.get(mid-1) && mountainArr.get(mid) > mountainArr.get(mid+1)) 
            {
                peak = mid;
                break;
            }

            else if(mountainArr.get(mid-1) > mountainArr.get(mid)) end = mid - 1;

            else start = mid + 1;
        }
        int first = binary_search(peak , mountainArr , target);
        if(first >= 0) return first;

        int second = rev_bs(peak , mountainArr , target);
        return second;
    }
};