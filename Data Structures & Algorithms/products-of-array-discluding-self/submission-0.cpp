class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());

        ans[0] = 1;
        ans[nums.size()-1] = 1;
        
        
        int pre = 1;
        for(int i = 0;i < nums.size()-1;i++)
        {
            pre *= nums[i];
            ans[i+1] = pre;
        }

        int post = 1;
        for(int j = nums.size()-1;j>0;j--)
        {
            post *= nums[j];
            ans[j-1] *= post;
            
        }
        return ans;
    }
};
