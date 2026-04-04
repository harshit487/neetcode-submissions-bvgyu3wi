class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(auto num : nums)
        {
            m[num]++;
        }

        for(auto it : m)
        {
            if(it.second > floor(n/2))
            {
                return it.first;
            }
        }

        return 0;
    }
};