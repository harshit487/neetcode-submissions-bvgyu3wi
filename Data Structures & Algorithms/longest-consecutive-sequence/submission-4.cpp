class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>map;

        if(nums.empty()) return 0;

        for(auto num : nums)
        {
            map[num]++;
        }
        int t = INT_MIN;

        for(int i = 0;i<nums.size();i++)
        {
            int temp = nums[i];
            int size=0;
            while(true)
            {
               temp++;
               if(map.find(temp) == map.end())
               {
                    break;
               } 
               else
               {
                    size++;
               }
            }
            t = max(t,size);
        }
        return t>0 ?t+1:1;
    }
};
