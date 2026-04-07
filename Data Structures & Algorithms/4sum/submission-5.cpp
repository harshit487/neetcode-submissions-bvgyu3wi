class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n-1 ; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1 ; j < n ; j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int start = j+1;
                int end = n-1;

                while(start < end)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[start] + nums[end];

                    if(sum == target)
                    {
                        ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;

                        while(start < end && nums[start] == nums[start-1])
                        {
                            start++;
                        }
                    }
                    else if(sum < target) start++;
                    else end--;
                }
            }
        }

        return ans;
    }
};