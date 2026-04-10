class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map1;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            int temp = nums[i];
            if(map1.find(temp) != map1.end())
            {
                if(i - (map1[temp]) <= k)
                {
                    return true;
                }
                else
                {
                    map1[temp] = i;
                }
            }
            map1[temp] = i;
        }
        return false;
    }
};