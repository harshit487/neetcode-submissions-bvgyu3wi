class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>x(nums.begin(),nums.end());
        int longest = 0;
        for(int num : nums)
        {
            if(x.find(num-1) == x.end())
            {
                int length = 1;
                while(x.find(num+length) != x.end())
                {
                    length++;
                }
                longest = max(length,longest);
            }
            
        }
        return longest;
    }
};
