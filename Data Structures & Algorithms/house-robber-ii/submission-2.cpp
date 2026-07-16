class Solution {
public:

    int maxAmt(int n , int start , vector<int>& nums , vector<int>& dp) {

        if(n == start) return nums[start];
        if(n == start+1) return max(nums[start],nums[start+1]);
        if(dp[n] != -1) return dp[n];

        return dp[n] = max(nums[n]+maxAmt(n-2,start,nums,dp),maxAmt(n-1,start,nums,dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        int case1 = maxAmt(n-1,1,nums,dp1);
        int case2 = maxAmt(n-2,0,nums,dp2);

        return max(case1 , case2);
    }
};