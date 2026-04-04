class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto num : nums)
        {
            map[num] = 1;
        }

        int k = 1;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(map.count(k))
            {
                k++;
            }
            else
            {
                return k;
            }
        }
        return k;
    }
};