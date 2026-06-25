class Solution {
public:
    void solve(vector<int>& nums, int n, int k, int curr, int start_index, int count, vector<bool>& visited, int target, bool &ans) {
        // Base case: If k-1 subsets are formed, the last one is automatically formed
        if (count == k - 1) {
            ans = true;
            return;
        }

        // Current subset is filled
        if (curr == target) {
            solve(nums, n, k, 0, 0, count + 1, visited, target, ans);
            return;
        }

        for (int i = start_index; i < n; i++) {
            // Optimization: if already visited or adding this exceeds target, skip
            if (visited[i] || curr + nums[i] > target) continue;

            visited[i] = true;
            solve(nums, n, k, curr + nums[i], i + 1, count, visited, target, ans);
            if (ans) return;
            
            // Backtrack
            visited[i] = false;
            
            // Optimization: If the first element fails, the whole path will fail
            if (curr == 0) return;
        }
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        int target = sum / k;
        int n = nums.size();
        
        // Sorting in descending order helps hit the 'target' faster and fail early
        sort(nums.rbegin(), nums.rend());
        
        // Fail if the largest element is bigger than the target
        if (nums[0] > target) return false;

        vector<bool> visited(n, false);
        bool ans = false;
        solve(nums, n, k, 0, 0, 0, visited, target, ans);
        return ans;
    }
};