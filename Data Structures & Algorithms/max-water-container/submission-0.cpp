class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int maxi = INT_MIN;

        while(i<=j)
        {
            if(heights[i] < heights[j])
            {
                int sum = heights[i] * (j-i);
                i++;
                maxi = max(sum,maxi);
            }
            else
            {
                int sum = heights[j] * (j-i);
                j--;
                maxi = max(maxi,sum);
            }
        }
        return maxi;

    }
};
