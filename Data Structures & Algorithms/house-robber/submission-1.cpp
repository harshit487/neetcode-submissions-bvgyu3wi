class Solution {
public:

    int maxAmt(int n , vector<int>& nums , vector<int>& dp) {
        if(n == 0) return nums[0];
        if(n == 1) {
            return max(nums[0] , nums[1]);
        }
        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = max(nums[n] + maxAmt(n-2,nums,dp) , maxAmt(n-1,nums,dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return maxAmt(n-1,nums,dp);
    }
};