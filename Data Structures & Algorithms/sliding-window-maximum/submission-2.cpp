class Solution {
public:


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return nums;
        int first = 0;
        int second = k-1;
        vector<int>answer;


        while(second < n)
        {
            int maxi = INT_MIN;

            for(int i = first;i<=second;i++)
            {
                maxi = max(maxi,nums[i]);
            }

            answer.push_back(maxi);
            first++;
            second++;
        }
        return answer;
    }
};