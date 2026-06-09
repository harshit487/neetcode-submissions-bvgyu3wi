class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>temp;

        int r = 0;
        int l = 0;

        while(l<n && r<m)
        {
            if(nums1[l] < nums2[r])
            {
                temp.push_back(nums1[l]);
                l++;
            }
            else
            {
                temp.push_back(nums2[r]);
                r++;
            }
        }

        while(l < n)
        {
            temp.push_back(nums1[l]);
            l++;
        }
        while(r < m)
        {
            temp.push_back(nums2[r]);
            r++;
        }
        int t = temp.size();
        int mid = (t-1)/2;
        if(t%2 != 0) return temp[mid];
        
        return (temp[mid] + temp[mid+1])/2.0 ; 
    }
};
