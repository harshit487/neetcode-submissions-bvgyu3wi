class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> ans;
        for(int i = 0 ; i < n-k ; i++)
        {
            ans.push_back(nums[i]);
        }
        
        // while(k--)
        // {
        //     int temp = nums[n-1];
        //     for(int i = 0 ; i < n-1 ; i++)
        //     {
        //         nums[i+1] = ans[i];
        //     }
        //     nums[0] = temp;
        //     ans = nums;
        // }
        int flag = 0;
        for(int i = n-k ; i < n ; i++)
        {
            nums[flag++] = nums[i];
        }
        for(int i = 0 ; i < ans.size() ; i++)
        {
            nums[flag++] = ans[i];
        }


        
    }
};