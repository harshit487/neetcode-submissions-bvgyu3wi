class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0;
        unordered_map<int,int>map;
        map[0] = 1;
        int total = 0;

        for(int i = 0;i<n;i++)
        {
            prefix += nums[i];

            if(map.count(prefix-k))
            {
                total += map[prefix - k];
                map[prefix]++;
            }
            else
            {
                map[prefix]++;
            }
        }
        return total;   
     }
};